import java.util.ArrayList;
import java.util.concurrent.locks.*;
public class Mapa_Assento {
	public Mapa_Assento(int n) {
		tranca = new ReentrantLock[n];
		assento = new Assento[n];
		for(int i = 0; i<n; i++) {
			tranca[i] = new ReentrantLock();
			assento[i] = new Assento();
		}
	}
	
	public Assento[] assento;
	public ReentrantLock[] tranca;
}
