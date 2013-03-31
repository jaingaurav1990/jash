#include <unistd.h>
#include <sys/wait.h>
#include <cstdio>

#define MAX_CMD_LEN 80

int main(int argc, char * argv[])
{
	char cmd[MAX_CMD_LEN];
	while (true)
	{
		printf("%s", "jash:");
		scanf("%s", cmd);
		pid_t pid; 

		if ((pid = fork()) < 0)
		{
			/*Error condition*/
		}

		if (pid == 0)
		{
			/* Only child process executes this */
			execlp(cmd, cmd, (char *)0);	
		}
		else
		{
			/* Only parent process executes this */
			wait(NULL);		
		}	
	}
}
