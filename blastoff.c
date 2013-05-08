#include "stdio.h"
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char flag[13];
char input[13];
char message[] = "<Y" "\x13" "lbh\x13^abj\x13g[X\x13Y_TZ\x1f\x13Z\\iX" "\x13" "4_g\x13T" "\x13" "f\\_Xag\x13g[h`Uf\x13hc";

char *GenerateFlag()
{
	//builds then returns "0Mg_4th_flag"
	memset(flag, '\0', 13);
	for(int i = 0; i < 12; i++)
	{
		memset(flag+i, i+3, 1);
	}

	for(int i = 0; i < 12; i++)
	{
		if((i % 3) == 2)
		{
			flag[i] = flag[i+1] + 19;
		}		
	}
	for(int i = 0; i < 12; i++)
	{
		flag[i] = (flag[i] * 247) % 256;
	}
	flag[0] += 57;
	flag[7] *= flag[7] % 12;
	flag[7] -= 56;
	flag[11] = flag[7] << 1;
	flag[11] += 103;
	flag[0] += 18;
	flag[7] -= 20;
	flag[1] += flag[11] + 66;
	flag[2] -= 184; 
	flag[3] *= 23;
	flag[3] += 57;
	flag[7] = 95;
	flag[4] += 115;
	flag[5] *= 29;
	flag[6] -= 71;
	flag[8] = (flag[3] * 8) + 14;
	flag[8] *= 17;
	flag[9] *= flag[9] + 31;
	flag[9] -= 16;
	flag[11] *= 2;
	flag[10] += 125;
	flag[10] *= 12;
	flag[10] += 1;
	flag[11] += 9;

	return flag;
}

// if != 0, then there is data to be read on stdin
int kbhit()
{
	struct timeval tv;
	fd_set fds;
	tv.tv_sec = 1;
	tv.tv_usec = 0;

	FD_ZERO(&fds);
	FD_SET(STDIN_FILENO, &fds);
	return select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
}

void PrintMessage()
{
	//Prints "If you know the flag give Alt a silent thumbs up"
	for(int i = 0; i < strlen(message); i ++)
	{
		message[i] += 13;
	}
	printf("%s\n", message);
}

int main()
{
	printf("Ready for launch...\n");
	sleep(1);

	printf("10...\n");
	sleep(1);
	printf("9...\n");
	sleep(1);
	printf("8...\n");
	sleep(1);
	printf("7...\n");
	sleep(1);
	printf("6...\n");
	sleep(1);
	printf("5...\n");
	sleep(1);
	printf("4...\n");

	if(kbhit() != 0)
	{
		memset(input, '\0', 13);
		int numBytes = read(0, input, 12);
		if(strcmp(input, GenerateFlag()) == 0)
		{
			PrintMessage();
			exit(EXIT_SUCCESS);
		}
	}	

	printf("3...\n");
	sleep(1);
	printf("2...\n");
	sleep(1);
	printf("1...\n");
	sleep(1);
	printf("ABORT! You lose :(\n");
}

