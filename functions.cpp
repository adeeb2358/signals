#include "functions.h"


void basic_signal(){
	int status;
	int a,b,c;

	if(fork()){
		wait(&status);
		if(WIFEXITED(status)){
			printf("Child exited normally with exit status %d\n",WEXITSTATUS(status));
		}
		if(WIFSIGNALED(status)){
			printf("Child exited on signal %d:%s\n",WTERMSIG(status),strsignal(WTERMSIG(status)));
		}
	}else{
		/*
			child process
		*/
		printf("Child PID = %d\n",getpid());
		pause();
		exit(5);
	}

	return;
}