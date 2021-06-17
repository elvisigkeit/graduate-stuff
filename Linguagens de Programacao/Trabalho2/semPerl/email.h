/*Arquivo de protótipos da classe email
Autor: Elvis Nobrega                 */

#include <string>

#ifndef EMAIL_H
#define EMAIL_H

using namespace std;

class Email {
	public:
		Email (string , string , string , string , string , bool);
		string getNome () const;
		string getOrigem () const;
		string getTitulo () const;
		string getData () const;
		string getHora () const;
		bool getSPAM () const;
	private:
		string nome, origem, titulo, data, hora;
		bool SPAM;
};

#endif