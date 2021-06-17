/*
Arquivo das funções do paralelepipedo 
Autor : Elvis Nobrega
*/
#include "paralelepipedo.h"

Paralelepipedo::Paralelepipedo (float altura, float largura, float comprimento) {
	setVolume(altura, largura, comprimento);
}

void Paralelepipedo::setVolume (float altura, float largura, float comprimento) {
	volume = altura*comprimento*largura;
}

float Paralelepipedo::getVolume () const {
	return volume;
}
