#include <iostream>

extern int _del(int x, int y);
extern int _minus(int x, int y);
extern int _mod(int x, int y);
extern int _plus(int x, int y);
extern int _umno(int x, int y);

int main(int argc, char const *argv[]) {
  int x = 10;
  int y = 2;
  std::cout << "/ - % + *" << '\n';
  std::cout << _del(x,y)<<'\n';
  std::cout << _minus(x,y)<<'\n';
  std::cout << _mod(x,y)<<'\n';
  std::cout << _plus(x,y)<<'\n';
  std::cout << _umno(x,y)<<'\n';
  return 0;
}
