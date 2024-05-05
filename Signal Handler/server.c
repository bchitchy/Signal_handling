#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>

char ch;
char count = 0;
void handlerUsr1(int sig)
{   
        if (sig == SIGUSR1)
        {
            ch |= (1<< count);
        }
        
        ++count;
        if (count == 8) {
            //putchar(ch);
            write(1 , &ch, 1);
            //fflush(stdout);
            //printf("%c", ch);
            ch = 0;
            count = 0;
        }
}

int main()
{   
    pid_t pid = getpid();
    printf("%d", pid);
    signal(SIGUSR1, handlerUsr1);
    signal(SIGUSR2, handlerUsr1);
    // while (1);

    return 0;
}
    

