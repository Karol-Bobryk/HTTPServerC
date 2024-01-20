#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>

#define BUFFER_SIZE 512

void *handleConnection(int clientSocket, void *buf) {
  ssize_t recieviedBytes = recv(clientSocket, buf, BUFFER_SIZE, 0);
  return NULL;
}

int main() {

  int serverSocket;

  serverSocket = socket(AF_INET, SOCK_STREAM, 0); 

  int bindSocket;

  struct sockaddr_in serverSocketAddress;
  serverSocketAddress.sin_family = AF_INET;
  serverSocketAddress.sin_port = htons(5000);
  serverSocketAddress.sin_addr.s_addr = INADDR_ANY;
  printf("%d\n", serverSocketAddress.sin_port);
  bindSocket = bind(serverSocket, (struct sockaddr *)&serverSocketAddress,
                    sizeof(serverSocketAddress));

  printf("%d\n", bindSocket);

  int listenSocket;

  listenSocket = listen(serverSocket, 10);

  printf("awaiting\n");

  int *clientSocket = (int *)malloc(sizeof(int));
  
  struct sockaddr *clientSocketAddress = malloc(sizeof(struct sockaddr));
  
  socklen_t clientSocketSize = sizeof(clientSocket);
  
  char *buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
  
  clientSocketAddress->sa_family = AF_INET;
  
  while (1){ 
    if(accept(serverSocket, clientSocketAddress, &clientSocketSize) >= 0)
    {
      printf("spotted D");
    }
    printf("%d\n",errno);
  }
  return 0;
}
