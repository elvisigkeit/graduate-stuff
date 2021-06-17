#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <setjmp.h>
#include <wait.h>
#include <stdlib.h>
sigjmp_buf buf;
int pid, i, status;
void handler(int sig) {
	pid_t pid;
	while ((pid = waitpid(-1, &status, 0)) > 0)
		if (WIFEXITED(status))
			printf("%d %d\n", pid, WEXITSTATUS(status));
	if (errno != ECHILD)
		printf("waitpid error\n");
	i++;
	siglongjmp(buf, i);
}
int main(int argc, char **argv) {
	sigset_t mask;
	signal(SIGCHLD, handler);
	i = sigsetjmp(buf, 0);
	while (i < 5) {
		sigemptyset(&mask);
		sigaddset(&mask, SIGCHLD);
		sigprocmask(SIG_BLOCK, &mask, NULL);
		pid = fork();
		if (pid == 0) {
			sigprocmask(SIG_UNBLOCK, &mask, NULL);
			exit(i);
		}
		sigprocmask(SIG_UNBLOCK, &mask, NULL);
		pause();
	}
	exit(0);
}
