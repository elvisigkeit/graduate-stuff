package br.com.exe;
public class Produtor implements Runnable {
	Pilha pilha;
	int bufferSize;
	Produtor(Pilha pilha, int bufferSize) {
		this.pilha = pilha;
		this.bufferSize = bufferSize;
	}
	public void run() {
		while (true) {
			synchronized (this) {
				try {
					wait();  // -----> 1
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				while (pilha.get() >= 0 && pilha.get() <= (bufferSize-1)) {
					pilha.put(pilha.get() + 1);
					System.out.println("Produzindo -> " + pilha.get());
				}
			}
		}
	}
	public void init() {
		new Thread(this, "Produtor").start();
	}
}
