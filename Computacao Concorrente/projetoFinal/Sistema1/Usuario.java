//autor: Carolina Hiromi Kameyama
//		 Elvis Nobrega de Alcantara
//		 Thiago Conceicao da Silva Costa
import java.util.concurrent.*;
public class Usuario extends Thread{
	BancoDeDados bd = null;
	boolean podeReservar = true;//analiza se o usuario pode reservar uma vaga
	int id;//id do usuario
	int reservado;//assento reservado
	public Usuario(int i,BancoDeDados banco) {
		bd = banco;
		id = i;
	}
	public void run()
	{
		podeReservar = bd.Visualiza();
		
		if(podeReservar) {reservado = bd.Seleciona(id);}
		if(podeReservar && reservado != 0) {bd.Cancela(reservado);}
	}
}
