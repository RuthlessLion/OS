#include <unistd.h>
#include <iostream>

int main(int argc, char const *argv[]) {

  execl("/bin/ls", "ls", "-l" , NULL);

  return 0;
}
