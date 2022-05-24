
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

        // ftok to generate unique key
        key_t key = ftok("shmfile", 65);

        // shmget returns an identifier in shmid
        int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    
        // shmat to attach to shared memory
        char *str = (char*) shmat(shmid, (void*) 0, 0);
        
        printf("Enter the input: ");
        // `str` will be share memory

        // read the input
        fgets(str, 1024, stdin);

        // detach the shared memory
        shmdt(str);
    } else {
        // parent here
        // parent will read from shared memory and give the number of vowels

        wait(NULL);
        // ftok to generate unique key
        key_t key = ftok("shmfile", 65);
    
        // shmget returns an identifier in shmid
        int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    
        // shmat to attach to shared memory
        char *str = (char*) shmat(shmid, (void*)0, 0);

        printf("\nData read from memory: %s",str);

        int i = 0, count = 0;

        while (str[i] != '\0' && i < 1024) {

            if (tolower(str[i]) == 'a' ||
                tolower(str[i]) == 'e' ||
                tolower(str[i]) == 'i' ||
                tolower(str[i]) == 'o' ||
                tolower(str[i]) == 'u') {

                count++;
            }
            i++;
        }

        printf("\nVowels in strings: %d\n\n", count);

        // detach from shared memory 
        shmdt(str);

        // destroy the shared memory
        shmctl(shmid, IPC_RMID,NULL);
    }

    return 0;
}