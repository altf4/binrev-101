#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

char table[] = "ABCDEFGHIJKLMNOPQRSTUVQXYZ";

char* AssembleFlag()
{
	char *flag = malloc(8);
	memcpy(flag + 0, &table[2], 1);
	memcpy(flag + 1, &table[14], 1);
	memcpy(flag + 2, &table[14],  1);
	memcpy(flag + 3, &table[11],  1);
	memcpy(flag + 4, &table[1],  1);
	memcpy(flag + 5, &table[17],  1);
	memcpy(flag + 6, &table[14],  1);
	memset(flag + 7, '\0', 1);
	return flag;
}

int StringCompare(char *first, char *second)
{
	int i = 0;
	for(;;)
	{
		if((first[i] == '\0') && (second[i] == '\0'))
		{
			return 0;
		}
		if(first[i] != second[i])
		{
			return 1;
		}
		i++;
	}
}

int main()
{
	printf("Let's try this again. Just how cool are you NOW?!\n");

	char *input = readline("");

	char *flag = AssembleFlag();
	if(StringCompare(input, flag) == 0)
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

