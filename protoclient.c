#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>

using namespace std;

typedef struct {
  char* message = "ProtocolMessage";
  char* senderIP = "127.0.0.1";
  char* receiverIP = "127.0.0.1";
} protocolFormat;

void sendMessage()
{
      fd = epoll_create(10);
         if (epollfd == -1) 
         {
             perror("EPOLL CREATE ERROR!");
             exit(EXIT_FAILURE);
         }
         
         ev.events = EPOLLIN;
         ev.data.fd = listen_sock;
         
         if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev) == -1) 
         {
             perror("EPOLL CONTROL ERROR : listen_sock");
             exit(EXIT_FAILURE);
         }

         while(true) 
         {
             nfds = epoll_wait(epollfd, events, 1000, -1);
             if (nfds == -1) 
             {
                 perror("EPOLL WAIT ERROR!");
                 exit(EXIT_FAILURE);
             }
         }
         
}

int main(){

    int numberOfThreads;
    printf("Enter number of threads (1-100)");
    scanf("%d", &numberOfThreads);

    pthread_t threads[numberOfThreads];

    protocolFormat format;

    for(int i=0; i<numberOfThreads;i++)
        {
            pthread_create(&threads[i], NULL, sendMessage, (void *)i);
            pthread_join(thread[i],NULL);
        }


  return 0;
}
