#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

char flag[] = "Th1s_is_Th3_first_Fl4g!!";


int main()
{
	printf("Enter your password, and I'll tell you if you're a cool dude.\n");

	char *input = readline("");
	if(strcmp(input, flag) == 0)
	{
		printf("Congratulations! You are a cool dude!\n");
		exit(0);
	}
	else
	{
		printf("No... you are not a very cool dude...\n");
		exit(0);
	}
}

