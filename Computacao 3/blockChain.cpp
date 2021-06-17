#include <iostream>
#include <stdio.h>
#include <ctime>
#include <fstream>
#include "md5.h"
 
using namespace std; 
 
string pegaHashDosHashes (int indiceArquivo) {
  ifstream arq;
  string arqName;
  string line;
  string hash;

  //arquivo com padrão
  if (indiceArquivo < 10){
    arqName = "transacoes0";
    arqName += indiceArquivo + ".txt";
  }else{
    arqName = "transacoes";
    arqName += indiceArquivo + ".txt";
  }
  arq.open (arqName);

  getline(arq, line);
  while(getline(arq, line))
    hash += md5(line);

  return md5(hash);
}


int main(int argc, char *argv[]) {
  char buf[100] = { 0 };
  char staticHeader[100] = { 0 };
  //sempre tem largura de 32 dígitos
  string md5Buf = "0";
  
  for(unsigned bloco = 1; bloco<=2; bloco++){

    sprintf(staticHeader, "|%u|???|%s|%s|", bloco, md5Buf.c_str(), pegaHashDosHashes(bloco).c_str());

    for( unsigned i = 4e9; i > 0; i-- ) {
      time_t now = time(0);
      tm *ltm = localtime(&now);
  
      sprintf(buf, "%d/%d/%d %d:%d:%d%s%u",  ltm->tm_mday, ltm->tm_mon, 1900+ltm->tm_year, ltm->tm_hour, ltm->tm_min, ltm->tm_sec, staticHeader, i);
  
      md5Buf = md5(buf);
      if(md5Buf[0]=='0' && md5Buf[1]=='0' && md5Buf[2]=='0' && md5Buf[3]=='0' && md5Buf[4]=='0' && md5Buf[5]=='0') {
        cout << buf << endl;
        cout << md5Buf << endl;
        break;
      }
    }
  }

  return 0;
}
