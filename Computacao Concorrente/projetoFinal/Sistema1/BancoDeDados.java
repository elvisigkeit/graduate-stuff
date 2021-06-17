//autor: Carolina Hiromi Kameyama
//		 Elvis Nobrega de Alcantara
//		 Thiago Conceicao da Silva Costa
import java.util.concurrent.*;
public class BancoDeDados {
	int qtdAssento;//quantidade de assentos
	int estadoAssento[];//1 = reservado, 0 = livre
	int reserva[];//guarda o codigo do usuario do assento
	int livres;//quantidade de assentos livres
	int assentoReservado;//guarda o id do assento a ser reservado
	public BancoDeDados(int n) {
		qtdAssento = n;
		estadoAssento = new int[n];
		reserva = new int[n];
		livres = n;
	}
	
	public synchronized boolean Visualiza() {
		if(livres > 0) {
			return true;
		}
		return false;
	}
	
	public synchronized int Seleciona(int id) {
		if(livres > 0) {
		for(int i=0;i<qtdAssento;i++) {
			if(estadoAssento[i] == 0) {
				estadoAssento[i] = 1;
				reserva[i] = id;
				assentoReservado = i;
				break;
			}
		}
		livres--;
		return assentoReservado+1;
		}
		return 0;
	}
	
	public synchronized void Cancela(int reservado) {
		estadoAssento[reservado - 1] = 0;
		livres++;
	}
}
