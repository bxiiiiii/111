#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/wait.h>

int main()
{
	int stat_val;
	int oldpri, newpri;
	pid_t pid;
	
	pid = fork();
	switch (pid) {
		case -1:
			perror("fork failed\n");
			exit(1);
		case 0:
			printf("child process\n");
			oldpri = getpriority(PRIO_PROCESS, getpid());
			printf("childpid = %d, oldpri = %d\n", getpid(), oldpri);

			newpri = nice(2);
			printf("newpri = %d\n",newpri);

			exit(0);
		default:
			printf("parentpid = %d\n", getpid());
			break;
	}

	wait(&stat_val);
	exit(0);
}
