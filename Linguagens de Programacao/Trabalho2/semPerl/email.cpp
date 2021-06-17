/* Programa de implementação da classe email
Autor: Elvis Nobrega                      */

#include "email.h"
/*Classe email, responsável por guardar os arquivos e definições de um email especifico
Ela possui apenas os métodos get() e os dados*/
Email::Email(string name, string orig, string title, string date, string hour, bool spm) {
	nome = name; origem = orig; titulo = title;
	data = date; hora = hour; SPAM = spm;
}

string Email::getNome () const{ return nome;}

string Email::getOrigem () const{ return origem;}

string Email::getTitulo () const{ return titulo;}

string Email::getData () const{ return data;}

string Email::getHora () const{ return hora;}

bool Email::getSPAM () const{ return SPAM;}