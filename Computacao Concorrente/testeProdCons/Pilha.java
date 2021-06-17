package br.com.exe;
public class Pilha {
	int n = 0;
	synchronized int get(){
		return n;
	}
	synchronized int put(int n){
		this.n = n;
		return this.n;
	}
}
