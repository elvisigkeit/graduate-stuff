package br.com.exe;
public class Consumidor implements Runnable {
	Pilha pilha;
	public Consumidor(Pilha pilha) {
		this.pilha = pilha;
	}
	public void run() {
		while (true) {
			synchronized (this) {
				try {
					wait();  // ---------------- 1
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				while (pilha.get() != 0) {
					System.out.println("Consumindo -> " + pilha.get());
					pilha.put(pilha.get() - 1);
				}
			}
		}
	}
	public void init() {
		new Thread(this, "Consumidor").start();
	}
}
