#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_dir();
void change_dir(char *in_dir);
void make_dir(char *in_dir);
void remove_cmd(char *in_dir);
void list_dir(char *in_dir);
void copy_cmd(char *source, char *dest);

// the current working directory (maximum path of 4096 characters)
char dir[4096] = "/home/deagen";

void main() {
	// the input buffer where user input is stored
	char *input;
	// the number of characters in the buffer	
	size_t n = 1024;
	// allocating memory for the buffer
	input = (char *)malloc(n * sizeof(char));
	
	// pointers to each of the individual argument strings within the input buffer
	char *args[6];

	do {
		printf("shell: ");

		// getting the user's input and storing it in the buffer
		getline(&input, &n, stdin);
		// removing the trailing newline character
		input[strlen(input)-1] = '\0';	
		
		// parsing the input string into multiple seperate arguments
		char delim[] = " ";
		char *arg_ptr = strtok(input, delim);
		int i = 0;
		while(arg_ptr != NULL && i <= 5) {		
			args[i] = arg_ptr;	
			arg_ptr = strtok(NULL, delim);
			i++;
		}
		
		// taking the appropriate action for each of the individual commands
		if(strcmp(args[0], "pwd") == 0) {
			print_dir();
		} else if(strcmp(args[0], "cd") == 0) {
			change_dir(args[1]);
		} else if(strcmp(args[0], "mkdir") == 0) {
			make_dir(args[1]);	
		} else if(strcmp(args[0], "rm") == 0) {
			remove_cmd(args[1]);	
		} else if(strcmp(args[0], "ls") == 0) {
			list_dir(args[1]);	
		} else if(strcmp(args[0], "cp") == 0) {
			copy_cmd(args[1], args[2]);	
		}



		
	} while(strcmp(args[0], "exit") != 0);
}

void print_dir() {
	printf("%s\n", dir);	
}

void change_dir(char *in_dir) {
	strcpy(dir, in_dir);
}

void make_dir(char *in_dir) {
	printf("*perform make directory functionality*\n");
}

void remove_cmd(char *in_dir) {
	printf("*perform remove functionality*\n");
}

void list_dir(char *in_dir) {
	printf("*perform list directory functionality\n");
}

void copy_cmd(char *source, char *dest) {
	printf("*perform copy functionality\n");
}
