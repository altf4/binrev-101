#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <unistd.h>
#include <crypt.h>
#include <openssl/md5.h>

char flag[18];

//Assembles the string "y0U_Are_A_pirat3!" into flag
void PrintFlag()
{
	memset(flag, '\0', 18);
	for(int i = 0; i < 17; i++)
	{
		flag[i] = i+3;
	}

	for(int i = 0; i < 17; i++)
	{
		if((i % 3) == 2)
		{
			flag[i] = flag[i] + 19;
		}
		flag[i] = (flag[i] * 247) % 127;
	}

	flag[3] -= 80;
	flag[3] *= 19;
	flag[1] = ((flag[1] / 11) * 5) + 3;
	flag[0] +=  15;
	flag[2] -= 1;
	flag[4] = flag[5];
	flag[15] *= 345;
	flag[5] = (flag[7] - 54) * 38;
	flag[6] = flag[7] + flag[8];
	flag[7] = flag[3];
	flag[8] = flag[4];
	flag[9] = flag[3];
	flag[10] = (flag[1] / 12) * 28;
	flag[11] = (flag[7] - 90) * 21;
	flag[12] = flag[5];
	flag[13] = (flag[13] * 3467) + 60;
	flag[14] *= 58;
	flag[15] = 51;
	flag[16] -= 88;

	printf("Thank you for using IniTech PasswordMagic Enterprise Edition Pro for Large Buisiness and Government Extended Plus. Your password is: %s", flag);
}

int KeyFilePresent()
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int n;
	MD5_CTX ctx;
	unsigned char digest[16];
	char *out = (char*)malloc(33);
	char correctHash[] = "19ea4e45b34616a94ce3de529c0115da";

	sleep(1);
	printf("Reading...");
	fflush(stdout);
	sleep(2);
	printf("...");
	fflush(stdout);
	sleep(1);
	printf("...");
	fflush(stdout);

	fp = fopen("/cdrom/DRM-license.key", "r");

	if(fp == NULL)
		return 0;

	ssize_t read = getline(&line, &len, fp);

	if(line != NULL)
		free(line);

	MD5_Init(&ctx);

	while(read > 0)
	{
		if(read > 512)
		{
		    MD5_Update(&ctx, line, 512);
		}
		else
		{
		    MD5_Update(&ctx, line, read);
		}
		read -= 512;
		line += 512;
	}

	MD5_Final(digest, &ctx);

	//Yea, yea... timing attacks
	memcmp(digest, correctHash, 32) != 0;

	return 1;
}

int main()
{
	printf("\nWelcome to:\n\n");
	printf("####################################\n");
	printf("# IniTech PasswordMagic Enterprise #\n");
	printf("# Edition Pro for Large Buisiness  #\n");
	printf("# and Government Extended Plus     #\n");
	printf("####################################\n\n");
	printf("© IniTech Corporation of America 2013\n\n");

	printf("Please enter your delux IniTech PasswordMagic user CD-ROM and press Enter...\n");

	readline("");

	while(KeyFilePresent() == 0)
	{
		printf("\nError finding your delux IniTech PasswordMagic user CD-ROM\n");
		printf("\nPlease enter your delux IniTech PasswordMagic user CD-ROM and press Enter...\n");
		readline("");
	}

	PrintFlag();
}

