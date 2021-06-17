// A multithread echo server 

#include "mysocket.h"  
#include <pthread.h>

#define NTHREADS 100

/* Structure of arguments to pass to client thread */
struct TArgs {
  TSocket cliSock;   /* socket descriptor for client */
};

/* Handle client request */
void * HandleRequest(void *args) {
  char str[100];
  TSocket cliSock;

  /* Extract socket file descriptor from argument */
  cliSock = ((struct TArgs *) args) -> cliSock;
  free(args);  /* deallocate memory for argument */

  for(;;) {
    /* Receive the request */
    if (ReadLine(cliSock, str, 99) < 0) 
      { ExitWithError("ReadLine() failed"); 
    } else printf("%s",str);  
    if (strncmp(str, "quit", 4) == 0) break; 
 
    /* Send the response */
    if (WriteN(cliSock, str, strlen(str)) <= 0)  
      { ExitWithError("WriteN() failed"); }  
  }
  close(cliSock);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  TSocket srvSock, cliSock;        /* server and client sockets */
  struct TArgs *args;              /* argument structure for thread */
  pthread_t threads[NTHREADS];
  int tid = 0;

  if (argc == 1) { ExitWithError("Usage: server <local port>"); }

  /* Create a passive-mode listener endpoint */  
  srvSock = CreateServer(atoi(argv[1]));

  /* Run forever */
  for (;;) { 
    if (tid == NTHREADS) 
      { ExitWithError("number of threads is over"); }

    /* Spawn off separate thread for each client */
    cliSock = AcceptConnection(srvSock);

    /* Create separate memory for client argument */
    if ((args = (struct TArgs *) malloc(sizeof(struct TArgs))) == NULL)
      { ExitWithError("malloc() failed"); }
    args->cliSock = cliSock;

    /* Create a new thread to handle the client requests */
    if (pthread_create(&threads[tid++], NULL, HandleRequest, (void *) args)) {
      { ExitWithError("pthread_create() failed"); }
    }
    /* NOT REACHED */
  }
}
