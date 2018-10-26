#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  pid_t pid;
  int t;
  switch(pid=fork())
  {
    case -1:
      std::cout << "error fork" << '\n';
    case 0 :
      std::cout << "n000000  ";
      std::cout << getpid() << '\n';
      exit(t);
    default : std::cout << "I'm your father!  ";
    std::cout << getpid() << '\n';
    wait(0);
    WEXITSTATUS(t);
  }

  return 0;
}
