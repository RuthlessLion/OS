#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <iostream>

int main()
{
	int fds[2];
	pipe(fds);
	char msg[80] = "Hell World! \n";

	switch(fork())
	{
		case 0:
			close(fds[1]);
			char buf[80];
      std::cout <<getpid() << "  " << getppid()<<'\n';//ребёнок

			read(fds[0], buf, 80);
			write(1, buf, strlen(buf) - 2);

			break;
		default:
			write(fds[1], msg, strlen(msg));
      std::cout <<getpid() << "  " << getppid()<< '\n';//родитель
			wait(0);
			break;
	}
	return 0;
}
