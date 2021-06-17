#include "mysocket.h"

int main(int argc, char **argv) {
  TSocket sock;
  char *servIP;
  unsigned short servPort;
  char str[100];
  char args[2][49];
  char symbol;
  unsigned short n;

  if (argc != 3) {
    ExitWithError("Usage: client <server IP> <server PORT>");
  }

  servIP = argv[1];
  servPort = atoi(argv[2]);

  sock = ConnectToServer(servIP, servPort);
  
  do {

    printf("Please put your operation separated with spaces\nOr exit, to end the connection:\n");
    scanf("%s", args[0]);
    if (!strcmp(args[0], "exit")){
	  if (WriteN(sock, "exit\n", 5) <= 0) {
        ExitWithError("WriteN() failed");
      }
      if (ReadLine(sock, str, 99) < 0) {
        ExitWithError("ReadLine() failed");
      }
      break;
	}
    scanf("%s", &symbol);
    scanf("%s", args[1]);
 
 
    snprintf(str, 100, "%s;%c;%s\n", args[0], symbol, args[1]);
 
    n = strlen(str);
 
    if (WriteN(sock, str, ++n) <= 0) {
      ExitWithError("WriteN() failed");
    }
 
    if (ReadLine(sock, str, 99) < 0) {
      ExitWithError("ReadLine() failed");
    } else {
      printf("%s", str);
    }

  } while (1);

  close(sock);

  return 0;
}
