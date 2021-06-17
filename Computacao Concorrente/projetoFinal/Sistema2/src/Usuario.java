import java.util.ArrayList;

public class Usuario extends Thread{
	Usuario (int id, Monitor monitor, ProdutorConsumidor escritor, ArrayList<Pair> roteiro) {
		this.id = id;
		this.monitor = monitor;
		this.escritor = escritor;
		this.roteiro = roteiro;
	}
	
	public void verifica() {
		//Codigo 1
		synchronized(lock) {senha = monitor.verifica();}
		String log = "1" + "," + this.id + "," + monitor.getMapa();
		synchronized(lock) {
			while(senha!=senhaAtual){
				try { 
					lock.wait();
				}catch(InterruptedException e) {e.printStackTrace();};
			}
		}
		escritor.escreveNoBuffer(log,senha);
		senhaAtual++;
		synchronized(lock){lock.notifyAll();}
	}
	
	public void ocupaVazio() {
		int senha, assento;
		int retorno[] = monitor.ocupaVazio(id);
		senha = retorno[0]; assento = retorno[1];
		//Codigo 2
		String log = "2" + "," + this.id + "," + (assento+1) + "," + monitor.getMapa();
		synchronized(lock){
			while(senha!=senhaAtual){
				try { 
					lock.wait();
				}catch(InterruptedException e) {e.printStackTrace();};
			}	
		}
		escritor.escreveNoBuffer(log,senha);
		senhaAtual++;
		synchronized(lock){lock.notifyAll();}
	}
	
	public void ocupaAssento(int assento) {
		senha = monitor.ocupaAssento(assento, id);
		//Codigo 3
		String log = "3" + "," + this.id + "," + (assento+1) + "," + monitor.getMapa();
		synchronized(lock){
			while(senha!=senhaAtual){
				try { 
					lock.wait();
				}catch(InterruptedException e) {e.printStackTrace();};
			}
		}
		escritor.escreveNoBuffer(log,senha);
		senhaAtual++;
		synchronized(lock){lock.notifyAll();}
	}

	public void cancela(int assento) {
		senha = monitor.cancela(assento, id);
		//Codigo 4
		String log = "4" + "," + this.id + "," + (assento+1) + "," + monitor.getMapa();
		synchronized(lock){
			while(senha!=senhaAtual){
				try { 
					lock.wait();
				}catch(InterruptedException e) {e.printStackTrace();};
			}
		}
		escritor.escreveNoBuffer(log,senha);
		senhaAtual++;
		synchronized(lock){lock.notifyAll();}
	}
	
	public void run() {
		for(Pair atual : roteiro) {
			switch (atual.l) {
			case 1:
				verifica();
				break;
			case 2:
				ocupaVazio();
				break;
			case 3:
				ocupaAssento(atual.r-1);
				break;
			case 4:
				cancela(atual.r-1);
				break;
			}
			synchronized(lock){lock.notifyAll();}
		}
	}
	
	private int id;
	private Monitor monitor;
	private ProdutorConsumidor escritor;
	private ArrayList<Pair> roteiro;
	private int senha;
	private static int senhaAtual = 1;
	private static Object lock = new Object();
}

