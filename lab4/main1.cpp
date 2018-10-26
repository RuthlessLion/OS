#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void* first(void* arg);
void* second(void* arg);

int main(int argc, char const *argv[]) {

  int id1, id2;
  void* thread_data = NULL;

  id1 = 1;
  id2 = 2;
  pthread_t thread1, thread2;

  pthread_create(&thread1, NULL, first, &id1);
  pthread_create(&thread2, NULL, second, &id2);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

 pthread_exit(0);

  return 0;
}

void* first(void* arg){
  std::cout << " A " << arg << '\n';
}
void* second(void* arg){
  std::cout << " B " << arg << '\n';
}
