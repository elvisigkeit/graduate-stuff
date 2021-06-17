#include "mysocket.h"
#include <pthread.h>

typedef struct {
  TSocket cliSock;
  char ip[16];
} TArgs;

#define MAX_SIZE_NAME           40
#define DEFAULT_PORT            9988
#define MAX_PUBLISHERS_FOLLOWED 20

char afterReceivedMessage = 0;
char MSG_SUBSCRIBE_QUESTION[] = "Quem desejas seguir?\n ";
char MSG_CONTINUE_ADDING_SUBSCRIPTION[] = "Desejas seguir mais alguém? [y/n]\n ";
char MSG_CONTINUE_ADDING_INVALID[] = "Resposta inválida, por favor escrever y ou n\n";
char MSG_RETRY_SUBSCRIBE_USER[] = "Esse usuário não está cadastrado, por favor escreva um usuário cadastrado:\n ";
char MSG_SUBSCRIPTION_LOOP[] = "Espere as mensagens ou\ndigite CANCELAR <usuario> para cancelar uma subscrição\ndigite SUBSCREVER <usuario> para subscrever a um novo usuário\ndigite FIM para finalizar as subscrições\n\n";
char MSG_SUCCESS_CLOSE_SINGLE_SUBSCRIPTION[] = "O usuário foi removido com sucesso\n";
char MSG_SUCCESS_SINGLE_SUBSCRIPTION[] = "O usuário foi adicionado com sucesso\n";
unsigned short nr_publishers_followed;
char publishers[MAX_PUBLISHERS_FOLLOWED][100];
char subscription_codes[MAX_PUBLISHERS_FOLLOWED][20];
char *servIP;

void get_subscription_code(char *message, char *code){
  char *copy = strdup(message);

  char *tok = copy, *end = copy;
  strsep(&end, " ");
  tok = end;
  if (tok == NULL)
    ExitWithError("Subscription code is null");

  strsep(&end, " ");
  strcpy(code, tok);

  free(copy);
}

char get_user_from_loop(char *message, char *user){
  char *copy = strdup(message);

  char *tok = copy, *end = copy;
  strsep(&end, " ");
  tok = end;
  if (tok == NULL) {
    WriteError("Invalid user, action not done");
    return 1;
  }

  strsep(&end, " ");
  strcpy(user, tok);

  free(copy);
  return 0;
}

char subscription_request (unsigned short subscription_index) {
  TSocket srvSock;
  char subscription[120];
  int sub_len;
  char result_subscription[50];

  srvSock = ConnectToServer(servIP, 4018);

  snprintf(subscription, 120, "2 %s %d \n", publishers[subscription_index], DEFAULT_PORT);
  sub_len = strlen(subscription);
  
  if (WriteN(srvSock, subscription, sub_len) <= 0)
    ExitWithError("WriteN() in subscription request failed");


  if (ReadLine(srvSock, result_subscription, 49) < 0)
    ExitWithError("ReadLine() failed");

  close(srvSock);

  if(result_subscription[0] == '1') {
    get_subscription_code(result_subscription, subscription_codes[subscription_index]);
    return 0;
  }

  return 1;
}

void close_single_subscription (char *message) {
  char user[100];
  int i, user_size;

  if(get_user_from_loop(message, user))
    return; 

  user_size = strlen(user);
  for (i = 0; i < nr_publishers_followed; i++) {
    if (!strncmp(publishers[i], user, user_size)) {
    int sub_cancel_len;
    char result_cancel[50];

      TSocket srvSock = ConnectToServer(servIP, 4018);

      snprintf(publishers[i], 100, "3 %s", subscription_codes[i]);
      sub_cancel_len = strlen(publishers[i]);
      
      if (WriteN(srvSock, publishers[i], sub_cancel_len) <= 0)
        ExitWithError("WriteN() in closing subscription request failed");
      
      if (ReadLine(srvSock, result_cancel, 49) < 0)
        ExitWithError("ReadLine() in closing subscription failed");
      
      if (result_cancel[0] == '0') {
        WriteError("Result cancel code doesn't exists");
        close(srvSock);
        return;
      }

      publishers[i][0] = '\0';
      subscription_codes[i][0] = '\0';
    system("clear");
    printf(MSG_SUCCESS_CLOSE_SINGLE_SUBSCRIPTION);
    getc(stdin);
    break;
  }
  }
}

void single_subscription (char *message) {
  char user[100];
  if(get_user_from_loop(message, user))
    return;
  
  strcpy(publishers[nr_publishers_followed], user);

  while (subscription_request(nr_publishers_followed)) {
    printf(MSG_RETRY_SUBSCRIBE_USER);
    scanf("%99[^\n]%*c", publishers[nr_publishers_followed]);
  }
  system("clear");
  printf(MSG_SUCCESS_SINGLE_SUBSCRIPTION);
  getc(stdin);

  nr_publishers_followed++;
}

char close_all_subscription() {
  TSocket srvSock;
  char sub_cancel[100];
  int sub_cancel_len;
  char result_cancel[50];
  unsigned short i;

  srvSock = ConnectToServer(servIP, 4018);

  for (i = 0; i < nr_publishers_followed; i++) {
    if (subscription_codes[i][0] != '\0') {
      snprintf(sub_cancel, 100, "3 %s", subscription_codes[i]);
      sub_cancel_len = strlen(sub_cancel);
     
      if (WriteN(srvSock, sub_cancel, sub_cancel_len) <= 0)
        ExitWithError("WriteN() in closing subscription request failed");
     
      if (ReadLine(srvSock, result_cancel, 49) < 0)
        ExitWithError("ReadLine() in closing subscription failed");
     
      if (result_cancel[0] == '0') {
        WriteError("Result cancel code doesn't exists");
        close(srvSock);
        return 1;
      }
    }
  }

  close(srvSock);

  return 0;
}

char subscription_loop (fd_set set, TSocket srvSock) {
  char entrada[100];
  char stdin_string[60];
  TArgs *args;  

  FD_ZERO(&set);
  FD_SET(STDIN_FILENO, &set);
  FD_SET(srvSock, &set);

  if (!afterReceivedMessage) {
    system("clear");
    printf(MSG_SUBSCRIPTION_LOOP);
  }
  afterReceivedMessage = 0;

  /********************** SELECT ****************************/
  if (select(FD_SETSIZE, &set, NULL, NULL, NULL) < 0) {
    WriteError("select() of subscription failed");
    return 0;
  }

  /********************** -> STDIN ****************************/
  if (FD_ISSET(STDIN_FILENO, &set)) {
    scanf("%99[^\n]%*c", stdin_string);
    if (!strncmp(stdin_string, "CANCELAR", 8)) {
      close_single_subscription(stdin_string);
      return 1;
    }
    if (!strncmp(stdin_string, "SUBSCREVER", 10)) {
      single_subscription(stdin_string);
      return 1;
    }
    if (!strncmp(stdin_string, "FIM", 3)) 
      return 0;
  }

  /********************** -> SOCKET ****************************/
  if (FD_ISSET(srvSock, &set)) {
    TSocket cliSock = AcceptConnection(srvSock);

    if ((args = (TArgs *) malloc(sizeof(TArgs))) == NULL)
      ExitWithError("Malloc of accepting connection failed");

    args->cliSock = cliSock;

    if (ReadLine(cliSock, entrada, 99) < 0)
      ExitWithError("Message from subscription can't be read");

    printf(entrada);
    afterReceivedMessage = 1;
    close(cliSock);
  }

  return 1;
}


char subscribe () {
  TSocket srvSock;
  fd_set set;

  srvSock = CreateServer(DEFAULT_PORT);

  while (subscription_loop(set, srvSock));

  close(srvSock);

  if (close_all_subscription())
    return 1;

  return 0;
}

int main(int argc, char **argv) {
  char continue_answer[10];
  unsigned short publisher_index = 0;

  if (argc != 2) {
    ExitWithError("Uso: client <server IP>");
  }

  servIP = argv[1];

  do {
    printf(MSG_SUBSCRIBE_QUESTION);
    scanf("%99[^\n]%*c", publishers[publisher_index]);

    while (subscription_request(publisher_index)) {
      printf(MSG_RETRY_SUBSCRIBE_USER);
      scanf("%99[^\n]%*c", publishers[publisher_index]);
    }

    publisher_index++;

    printf(MSG_CONTINUE_ADDING_SUBSCRIPTION);
    scanf("%9[^\n]%*c", continue_answer);
    while (continue_answer[0] != 'y' && continue_answer[0] != 'n') {
      printf(MSG_CONTINUE_ADDING_INVALID);
      printf(MSG_CONTINUE_ADDING_SUBSCRIPTION);
      scanf("%9[^\n]%*c", continue_answer);
    }
  } while (continue_answer[0] == 'y' && publisher_index < MAX_PUBLISHERS_FOLLOWED);

  nr_publishers_followed = publisher_index;

  if (subscribe())
    WriteError("Subscription error");

  return 0;
}

