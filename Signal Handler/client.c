#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>

void post(char* , int);
void bits(char, int);


int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        return EXIT_FAILURE;
    }
  char arr[100];
    printf("Enter message: ");
    if (fgets(arr, sizeof(arr), stdin) == NULL) {
        fprintf(stderr, "Failed to read input\n");
        return EXIT_FAILURE;
    }
  int pid = atoi(argv[1]);
  if (pid <= 0) {
        fprintf(stderr, "Invalid process ID\n");
        return EXIT_FAILURE;
    }
  post(arr, pid);

}

void post(char* text, int pid)
{   
    int n = 0;
    while (text[n] != '\0')
    {
        bits(text[n], pid);
        n++;
    }
    
} 

void bits(char ch, int pid)
{   int count = 0;
    while(count < 8)
    {
        if (ch & 1)
        {
            kill(pid, SIGUSR1);
        }

        else
        {
            kill(pid, SIGUSR2);
        }
        usleep(10000);

        count++;
        ch>>=1;

    }

        
}
