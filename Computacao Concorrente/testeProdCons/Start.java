package br.com.exe;
public class Start {
	public static void main(String[] args) {
		new Runnable() {
			@Override
			public void run() {
				final int bufferSize = 10;
				Pilha pilha = new Pilha();
				Produtor p = new Produtor(pilha, bufferSize);
				Consumidor c = new Consumidor(pilha);
				p.init();
				c.init();
				while (true) {
					if (pilha.get() == 0) { // -----------> 2
						synchronized (p) {
							System.out.println("************************* Incializa Produção *************************");
							p.notify();
						}
					}
					if (pilha.get() == bufferSize) { // -------------> 3
						synchronized (c) {
							System.out.println("************************* Incializa Consumo *************************");
							c.notify();
						}
					}
				}
			}
		}.run();
	}
}
