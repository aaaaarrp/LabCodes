// Write a program to create the following hierarchy and print their Id and its parent ID using fork statements.

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    printf("Parent ID is P1\n\n");
    if(fork()>0){
        if(fork()==0){
            printf("ID:P3\nParent ID:P1\n\n");
            if(fork()>0){
                if(fork()==0){
                    printf("ID:P4\nParent ID:P3\n\n");
                }
            }else{
                printf("ID:P5\nParent ID:P3\n\n");
            }
        }
    }else{
        printf("ID:P2\nParent ID:P1\n\n");
    }
}