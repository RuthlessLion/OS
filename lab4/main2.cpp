#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <iostream>
#include <string>

int c = 0;

void *func(void *arg)
{
	while(1)
  if(c == 0){
    std::cout << "Kurwa!"<< '\n';
  }else{
    std::cout << "Aaaaa!"<< '\n';
  }
	return arg;
}

void signaler (int signo)
{
  c = (c == 0) ? 1:0;
	signal(SIGUSR1, signaler);
}

int main(int argc, char const *argv[]) {

	signaler(1);
	pthread_t th1;
  pthread_create (&th1, NULL, func, &c);
  char ch;

	while (1)
	{
		ch = getchar();
		if (ch == ' ') raise(SIGUSR1);
	}
	return 0;
}
