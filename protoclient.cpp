#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>

using namespace std;

typedef struct {
  string message = "ProtocolMessage";
  string senderIP = "127.0.0.1";
  string receiverIP = "127.0.0.1";
} protocolFormat;

void sendMessage()
{
    for(int i=0; i<1000;++)
    {
        //create epoll
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