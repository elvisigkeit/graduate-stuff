#include "mysocket.h"
#include <string.h>

typedef struct {
  TSocket cliSock;
} TArgs;

int HandleRequest(void *args) {
  char str[100];
  unsigned short i;
  int result;
  char operation;
  char *response;
  unsigned short resSize;
  short validResponse;
  char *token, *copyStr;
  TSocket cliSock;

  cliSock = ((TArgs *) args) -> cliSock;

  do {
    if (ReadLine(cliSock, str, 99) < 0) {
      ExitWithError("ReadLine() failed");
    } 

	if (!strcmp(str, "exit\n")) {
	  if (WriteN(cliSock, "ok\n", 3) <= 0) {
        ExitWithError("WriteN() failed");
      }
	  break;
    }
    
    response = (char *) malloc (sizeof(char)*100);
    copyStr = strdup(str);
    printf("Operation: ");
    for(i=0; i<3; i++){
      if (!(token = strsep(&copyStr, ";")))
        break;
      switch (i) {
        case 0:
          result = atoi(token);
        break;
 
        case 1:
          operation = token[0]; 
        break;
 
        case 2:
          switch(operation) {
            case '+':
      	    result += atoi(token);
      		validResponse = 1;
      	  break;
 
      	  case '-':
      	    result -= atoi(token);
      		validResponse = 1;
      	  break;
 
      	  case '*':
      	    result *= atoi(token);
      		validResponse = 1;
      	  break;
 
      	  case '/':
      	    result /= atoi(token);
      		validResponse = 1;
      	  break;
 
      	  default:
      		validResponse = 0;
      	}
      }
      printf("%s ", token);
    }
    free(copyStr);
 
    if (validResponse){
      snprintf(response, 100, "Result: %d\n", result);
    } else {
      snprintf(response, 100, "Invalid Operation\n");
    }

    printf("%s", response);

    resSize = strlen(response);
 
    if (WriteN(cliSock, response, resSize) <= 0) {
      ExitWithError("WriteN() failed");
    }
 
    free(response);
  
  } while (1);

  printf("Connection Closed\n");
  close(cliSock);
  return 1;
}

int main(int argc, char **argv) {
  TSocket srvSock, cliSock;
  TArgs *args;

  if (argc != 2) {
    ExitWithError("Usage: server <local port>");
  }

  srvSock = CreateServer(atoi(argv[1]));

  while (1) {
    cliSock = AcceptConnection(srvSock);

	if ((args = (TArgs *) malloc(sizeof(TArgs))) == NULL) {
	  ExitWithError("malloc() failed");
	}

	args->cliSock = cliSock;

	if (HandleRequest((void *) args) != 1) {
	  ExitWithError("HandleRequest() failed");
	}

	free(args);
  }
}
