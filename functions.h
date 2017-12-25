#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <cstdlib>
#include <string.h>

void basic_signal();
void basic_signal_handler_demo();
void sigaction_demo_pipe();

#endif // FUNCTIONS_H
