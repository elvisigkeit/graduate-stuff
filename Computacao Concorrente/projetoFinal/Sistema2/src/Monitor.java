
public class Monitor {
	public Mapa_Assento mapa;
	int qtdAssento;
	int senha = 1;

	public Monitor(int n) {
		mapa = new Mapa_Assento(n);
		qtdAssento = n;
	}
	
	public String getMapa() {
		StringBuilder resultado = new StringBuilder();
		resultado.append("[");
		boolean primeiro = true;
		for (int i=0; i<qtdAssento; i++) {
			if (primeiro) 
				primeiro = false;
			else
				resultado.append(",");
			resultado.append(mapa.assento[i].id_usuario);
		}
		resultado.append("]");		
		
		return resultado.toString();		
	}

	public int verifica(){return senha++;}	

	public int[] ocupaVazio(int id_user) {
		int id_aleatorio = (int)(Math.random() * qtdAssento);
		mapa.tranca[id_aleatorio].lock();
		if(mapa.assento[id_aleatorio].estado == false) {
			mapa.assento[id_aleatorio].estado = true;
			mapa.assento[id_aleatorio].id_usuario = id_user;
		}
		mapa.tranca[id_aleatorio].unlock();
		int []retorno = new int[2];
		retorno[0] = senha++;
		retorno[1] = id_aleatorio;
		return retorno;
	}
	
	public int ocupaAssento(int id, int id_user) {//id = id do assento; id_user = id do pr�prio usu�rio, reserva assento do id
		mapa.tranca[id].lock();
		if(mapa.assento[id].estado == false) {
			mapa.assento[id].estado = true;
			mapa.assento[id].id_usuario = id_user;
		}
		mapa.tranca[id].unlock();
		return senha++;
	}
	
	public int cancela(int id, int id_user) {//id = id do assento; id_user = id do pr�prio usu�rio
		mapa.tranca[id].lock();
		if(mapa.assento[id].id_usuario != id_user || mapa.assento[id].estado != true) 
			System.out.println("usuario nao reservou esse assento");
		else 
			mapa.assento[id].estado = false;
		mapa.tranca[id].unlock();
		return senha++;
	}
}
