#include <cstdio>
#include <unistd.h>
#include <cstdlib>
#include <sys/wait.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  std::cout << getpid() << "(main)" << '\n';
	pid_t pid;
	switch(pid = fork())
	{
		case -1:
			cout << "error fork" << endl;
			break;
		case 0:
			switch(pid = fork())
			{
				case -1:
					cout << "error fork" << endl;
					break;
				case 0:
					break;
				default:
					switch(pid = fork())
					{
						case -1:
							cout << "error fork" << endl;
							break;
						default:
							wait(0);
							break;
					}
					break;
			}
			wait(0);
			break;
		default:
			switch(pid = fork())
			{
				case -1:
					cout << "error fork" << endl;
					break;
				case 0:
					pid = fork();
					wait(0);
					break;
				default:
					wait(0);
					break;
			}
			wait(0);
			break;

	}
	wait(0);
	cout << getpid() << ", child of " << getppid() << endl;
	return 0;
}
