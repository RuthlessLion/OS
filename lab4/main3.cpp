#include <iostream>
#include <cstdio>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
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
	signal(SIGALRM, signaler);
  alarm(1);
}

int main(int argc, char const *argv[]) {

  char ch;
	signaler(1);
	pthread_t thread1;
  pthread_create (&thread1, NULL, func, &c);
  alarm(1);
  pthread_join(thread1,NULL);
	return 0;
}
