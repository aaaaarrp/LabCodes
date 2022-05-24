
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    printf("\n");

    if (pid == 0) {
        // child here
        // child will read from buffer and write it to share memory  

        int n;
        printf("Enter the value of n: ");
        scanf("%d", &n);

        // 0, 1, 2, 3, .. n
        // n + 1
        // length, 1, 2, .. n + 1

        key_t key = ftok("shmfile1", 65);    
        int shmid = shmget(key, sizeof(int) * (n + 1), 0666 | IPC_CREAT);
        int *array = (int*) shmat(shmid, (void*) 0, 0);

        array[0] = n;
    
        for (int i = 0; i < n; ++i) {
            printf("Enter the element no %d: ", i);
            scanf("%d", &array[i + 1]);
        }

        // detach the shared memory
        shmdt(array);
    } else {
        // parent here
        // parent will read from shared memory and give the number of vowels

        wait(NULL);

        key_t key = ftok("shmfile1", 65);
        int shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT);
        int *array = (int*) shmat(shmid, (void*) 0, 0);

        printf("\nlength of the array: %d\n", array[0]);

        int sum = 0;

        for (int i = 0; i < array[0]; ++i) {
            sum += array[i + 1];
        }

        printf("\nSum of the array: %d\n\n", sum);

        shmdt(array);
        shmctl(shmid, IPC_RMID,NULL);
    }

    return 0;
}