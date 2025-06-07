#include "main.h"

void handle_ctrlback(int sig) { (void)sig; }

void rl_replace_line(const char *, int);
// ctrl-c
void handle_ctrlc(int sig) {
	(void)sig;
	extern bool ctrlc;
	ctrlc = true;
	write(STDOUT_FILENO, "\n", 1); // Ensure newline is printed
	rl_on_new_line();			   // Move to a new line
	rl_replace_line("", 0);		   // Clear the line buffer
	rl_redisplay();				   // Refresh the prompt
}
