#include "mysocket.h"
#include <pthread.h>

typedef struct {
  TSocket cliSock;
  char ip[16];
} TArgs;

#define MAX_SIZE_NAME 40
#define DEFAULT_PORT  9988
char MSG_PUBLISH_QUESTION[] = "Com que usuário deseja se registrar?\n ";
char MSG_RETRY_REGISTER_USER[] = "Esse usuário já existe, por favor escreva um nome novo:\n ";
char MSG_NEW_BROADCAST_MESSAGE[] = "Por favor, escreva a mensagem:\n[Ou FIM para finalizar o broadcast]\n ";
char *servIP;

char unregister_user (char *user) {
  TSocket srvSock;
  char sub_cancel[100];
  int sub_cancel_len;
  char result_cancel[50];

  srvSock = ConnectToServer(servIP, 4018);

  snprintf(sub_cancel, 100, "5 %s \n", user);
  sub_cancel_len = strlen(sub_cancel);

	if (WriteN(srvSock, sub_cancel, sub_cancel_len) <= 0)
	  ExitWithError("WriteN() in unregistering request failed");

  if (ReadLine(srvSock, result_cancel, 49) < 0)
    ExitWithError("ReadLine() in unregistering failed");

  close(srvSock);

  if (result_cancel[0] == '0') {
    WriteError("Unregistering user doesn't exists");
    return 1;
  }

  return 0;
}

char registering_loop (char *user) {
  TSocket srvSock;
  char message[141];
  char letter[150];
  int message_len;
  char result_message[50];

  srvSock = ConnectToServer(servIP, 4018);

  printf(MSG_NEW_BROADCAST_MESSAGE);
  scanf("%139[^\n]%*c", message);

  if (!strncmp(message, "FIM", 3)) 
    return 0;

  snprintf(letter, 100, "4 %s %s \n", user, message);
  message_len = strlen(letter);

	if (WriteN(srvSock, letter, message_len) <= 0)
	  ExitWithError("WriteN() in registering loop failed");

  if (ReadLine(srvSock, result_message, 49) < 0)
    ExitWithError("ReadLine() in registering loop failed");

  close(srvSock);
  
  if (result_message[0] == '0') {
    WriteError("Error writing in registering loop");
    WriteError("User doesn't exists");
    return 0;
  }

  return 1;
}

char register_request (char *user) {
  TSocket srvSock;
  char registering[100];
  int sub_len;
  char result_registering[50];

  srvSock = ConnectToServer(servIP, 4018);

  snprintf(registering, 100, "1 %s \n", user);
  sub_len = strlen(registering);

	if (WriteN(srvSock, registering, sub_len) <= 0)
	  ExitWithError("WriteN() in registering request failed");

  if (ReadLine(srvSock, result_registering, 49) < 0)
    ExitWithError("ReadLine() in registering request failed");

  close(srvSock);

  if(result_registering[0] == '0') 
    return 1;

  return 0;
}

char publish (char *user) {
  while (register_request(user)) {
    printf(MSG_RETRY_REGISTER_USER);
    scanf("%99[^\n]%*c", user);
  }

  while (registering_loop(user));

  if (unregister_user(user))
    return 1;

  return 0;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    ExitWithError("Uso: client <server IP>");
  }

  servIP = argv[1];

  char user[100];

  printf(MSG_PUBLISH_QUESTION);
  scanf("%99[^\n]%*c", user);

  if (publish(user))
	  WriteError("Publishing error");

  return 0;
}

