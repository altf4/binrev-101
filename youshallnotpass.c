#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <unistd.h>

char flag[13];

//Assembles the string "h4cK3r_M4gik" into flag
void AssembleFlag()
{
	memset(flag, '\0', 13);
	for(int i = 0; i < 12; i++)
	{
		flag[i] = i+3;
	}

	for(int i = 0; i < 12; i++)
	{
		if((i % 3) == 2)
		{
			flag[i] = flag[i] + 19;
		}
		flag[i] = (flag[i] * 247) % 127;
	}

	flag[0] -= 2;
	flag[2] = flag[1]; 
	flag[1] = flag[7] - 5;
	flag[11] = flag[11] >> 2;
	flag[3] = flag[11] * 15;
	flag[6] = (flag[2] * 24) % 7;
	flag[8] = flag[1];
	flag[4] = flag[6] * 17;
	flag[10] = (flag[0] - flag[2]) * flag[11];
	flag[5] = (flag[10] * 4) + 14;
	flag[6] = flag[11] * 19;
	flag[7] = (flag[11] + 2) * 11;
	flag[9] *= 2;
	flag[9] += 17;
	flag[10] -= 2;
	flag[10] *= 6896;
	flag[10] -= 39;
	flag[11] *= 21;
	flag[11] += 2;
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
	printf("YOUUUUUU\n");
	sleep(1);
	printf("SHALL NOT\n");
	sleep(1);
	printf("PAAAAASS!!\n");
	printf("(You'll never break THIS encoding scheme!)\n");

	char *input = readline("");
	AssembleFlag();

	if(StringCompare(input, flag) == 0)
	{
		printf("Congratulations! You are a cool Mithrandir!\n");
		exit(0);
	}
	else
	{
		printf("No... you are not a very cool Mithrandir...\n");
		exit(0);
	}
}

