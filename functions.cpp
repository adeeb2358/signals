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

/*
	function for handling the signal	
*/
void my_custom_signal_hanlder(int signal_type){
	std::cout <<"signal handler invoked\n"<<signal_type;
	return;
}

/*
	function invoking the signal handler
*/
void basic_signal_handler_demo(){
	signal(SIGINT,my_custom_signal_hanlder);
	int i = 0;
	while(1){
		pid_t pid = getpid();
		printf("pid: %d :my value is  %d\n",pid,i);
		i++;
		sleep(1);
	}
	return;
}

void sigaction_demo_pipe(){
	struct sigaction one_action;
	int pipe_descriptor[2];
	int no_of_bytes_read;
	char data_buf[1000];
	/*
		pipe here for demonstrating the 
		blocking signal handler
	*/
	pipe(pipe_descriptor);
	one_action.sa_handler = my_custom_signal_hanlder;
	sigemptyset(&one_action.sa_mask);
	//one_action.sa_flags = SA_RESTART;
	one_action.sa_flags = 0;
	sigaction(SIGINT,&one_action,NULL);
	while(1){
		no_of_bytes_read = read(pipe_descriptor[0],data_buf,1000);
		 printf("read returned %d, errno = %d\n", no_of_bytes_read, errno);
	}
}