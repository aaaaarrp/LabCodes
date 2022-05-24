//Create 2 processes (parent and child process) and a pipe. Child process read N characters and puts in to the pipe and Parent process reads and finds total no of vowels.

#include<stdio.h>
#include<unistd.h>

int main() {
   int pipefds[2];
   int returnstatus;
   int pid;
   char writemessages[100];
   fgets(writemessages,100,stdin);
   char readmessage[100];
   returnstatus = pipe(pipefds);
   if (returnstatus == -1) {
      printf("Unable to create pipe\n");
      return 1;
   }
   pid = fork();
   
   // Child process
   if (pid == 0) {
	   printf("Child Process - Writing to pipe -  %s\n", writemessages);
      write(pipefds[1], writemessages, sizeof(writemessages));    //fds[1] - write end of the pipe
   } else { //Parent process

   	  read(pipefds[0], readmessage, sizeof(readmessage));    //fds[0] - read end of the pipe
      printf("Parent Process - Reading from pipe -  %s\n", readmessage);
      
		int c = 0, count = 0;
		while (readmessage[c] != '\0') {
			if (readmessage[c] == 'a' || readmessage[c] == 'A' || readmessage[c] == 'e'
			 || readmessage[c] == 'E' || readmessage[c] == 'i' || readmessage[c] == 'I' 
			 || readmessage[c] =='o' || readmessage[c]=='O' 
			 || readmessage[c] == 'u' || readmessage[c] == 'U')
			count++;
			c++;
		}

		printf("Number of vowels in the string: %d\n", count);
   }
   return 0;
}