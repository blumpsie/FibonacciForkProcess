#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;
        /* Forks Another Process*/
        pid = fork();

        if(pid < 0){
            /*Error Occured*/
            fprintf(stderr, "Fork Failed");
            exit(-1);
        }
        else if (pid == 0){
            /*Child Process*/
            int userNum;
            int count;
            int nextNum;
            int firstTerm = 0;
            int secondTerm = 1;

            printf("How many terms for the Fibonacci sequence?\n", userNum);
            scanf("%d", &userNum);
            printf("The first %d numbers of the Fibonacci sequence are:\n", userNum);

            for (count = 0; count < userNum; count++)
            {
                if (count <= 1)
                {
                    nextNum = count;
                }
                else
                {
                    nextNum = firstTerm + secondTerm;
                    firstTerm = secondTerm;
                    secondTerm = nextNum;
                }

                printf("%d\n", nextNum);
            }
        }
        else{
            /*Parent Process*/
            /* Parent will wait for the child to complete*/
            wait(NULL);
            printf("Child Complete");
            exit(0);
        }


}
