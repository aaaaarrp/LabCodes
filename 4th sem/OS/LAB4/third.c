// Write a program to create the following hierarchy and print their Id and its parent ID using fork statements.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{

    pid_t pid1, pid2, pid3, pid4, pid5;
    printf("Parent : %d\n", getpid());

    pid1 = fork();

    if (pid1 == 0)
    { // A child Process. Lets say p2.
        printf("P2: %d || Parent id: %d \n", getpid(), getppid());
    }
    if (pid1 > 0)
    {
        pid2 = fork();
        if (pid2 == 0)
        { // A child process. Lets say p3.
            printf("P3: %d || Parent id: %d \n", getpid(), getppid());
            pid3 = fork();
            if (pid3 == 0)
            { // A child process. Lets say p4.
                printf("P4: %d || Parent id: %d \n", getpid(), getppid());
            }
            if(pid3 > 0){
                pid4 = fork();
                if (pid4 == 0)
                { // A child process. Lets say p5.
                    printf("P5: %d || Parent id: %d \n", getpid(), getppid());
                }
            }
        }
    }
    for (int i = 0; i < 5; i++)
        wait(NULL);
}