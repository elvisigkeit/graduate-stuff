import java.util.ArrayList;
import java.util.LinkedList;

public class Sistema{
	public static void main(String args[]) {
		buffer = new LinkedList<String>();
		produtorConsumidor = new ProdutorConsumidor(args[0], buffer);
		produtorConsumidor.start();
		
		Monitor monitor = new Monitor(Integer.valueOf(args[1]));
		
		Usuario[] usuarios = new Usuario[NUMERO_DE_THREADS];
		criaRoteiroDosUsuarios();
		for(int i=0; i<NUMERO_DE_THREADS; i++) {
			usuarios[i] = new Usuario((i+1), monitor, produtorConsumidor, roteiro[i]);
			usuarios[i].start();
		}

		for(int i=0; i<NUMERO_DE_THREADS; i++) {
			try {
				usuarios[i].join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		produtorConsumidor.termina();
	}

	static private void criaRoteiroDosUsuarios() {
		roteiro = new ArrayList[NUMERO_DE_THREADS];
		//Padronizar o roteiro da thread 1
		roteiro[0] = new ArrayList<Pair>();
		roteiro[0].add(new Pair(1,0));
		roteiro[0].add(new Pair(2,0));
		roteiro[0].add(new Pair(1,0));
		//Padronizar o roteiro da thread 2
		roteiro[1] = new ArrayList<Pair>();
		roteiro[1].add(new Pair(1,0));
		roteiro[1].add(new Pair(3,3));
		roteiro[1].add(new Pair(1,0));
		//Padronizar o roteiro da thread 3
		roteiro[2] = new ArrayList<Pair>();
		roteiro[2].add(new Pair(1,0));
		roteiro[2].add(new Pair(3,4));
		roteiro[2].add(new Pair(1,0));
	}
	
	static private int NUMERO_DE_THREADS = 3;
	static ArrayList<Pair> roteiro[];
	static ProdutorConsumidor produtorConsumidor;
	static private LinkedList<String> buffer;

}
