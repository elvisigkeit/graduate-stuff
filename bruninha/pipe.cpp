#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;

int main (int argc, char **argv) {

  if (!isatty(STDIN_FILENO)) {
    string linha;
    while(1) {
      if(!getline(cin, linha))
        return 0;
      cout << linha;
      cout << endl;
    }
  } else {
    cout << "Não rolou pipezão" << endl;
  }
  return 0;
}


/*
int main () {
  FILE *fp = popen("cat pipe.cpp", "r");
  int ch;


  if(!fp) {
    printf("Erro, pipe não funcionou\n");
    
    return 1;
  }

  while((ch=fgetc(fp)) != EOF)
    putchar(ch);

  pclose(fp);

  return 0;
}*/
