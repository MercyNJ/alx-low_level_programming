#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * findBiggestNum - finds the biggest number
 *
 * @usrn: username
 * @len: length of username
 * Return: the biggest number
 */
int findBiggestNum(char *usrn, int len)
{
	int ch;
	int iterator;
	unsigned int randomNO;

	ch = *usrn;
	iterator = 0;

	while (iterator < len)
	{
		if (ch < usrn[iterator])
			ch = usrn[iterator];
		iterator += 1;
	}

	srand(ch ^ 14);
	randomNO = rand();

	return (randomNO & 63);
}

/**
 * mult_each_char - multiplies each char of username
 *
 * @usrn: username
 * @len: length of username
 * Return: multiplied char
 */
int mult_each_char(char *usrn, int len)
{
	int ch;
	int iterator;

	ch = iterator = 0;

	while (iterator < len)
	{
		ch = ch + usrn[iterator] * usrn[iterator];
		iterator += 1;
	}

	return (((unsigned int)ch ^ 239) & 63);
}

/**
 * randonchar_gen - generates a random char
 *
 * @usrn: username
 * Return: a random char
 */
int randonchar_gen(char *usrn)
{
	int ch;
	int iterator;

	ch = iterator = 0;

	while (iterator < *usrn)
	{
		ch = rand();
		iterator += 1;
	}

	return (((unsigned int)ch ^ 229) & 63);
}

/**
 * main - Entry point
 *
 * @argc: arguments count
 * @argv: arguments vector
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char keygen[7];
	int len, ch, iterator;
	long alphabet[] = {
		0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
		0x74767a5835737956, 0x2b554c59634a474f, 0x71786636576a6d34,
		0x723161513346655a, 0x6b756f494b646850 };
	(void) argc;

	for (len = 0; argv[1][len]; len++)
		;
	/* ----------- f1 ----------- */
	keygen[0] = ((char *)alphabet)[(len ^ 59) & 63];
	/* ----------- f2 ----------- */
	ch = iterator = 0;
	while (iterator < len)
	{
		ch = ch + argv[1][iterator];
		iterator = iterator + 1;
	}
	keygen[1] = ((char *)alphabet)[(ch ^ 79) & 63];
	/* ----------- f3 ----------- */
	ch = 1;
	iterator = 0;
	while (iterator < len)
	{
		ch = argv[1][iterator] * ch;
		iterator = iterator + 1;
	}
	keygen[2] = ((char *)alphabet)[(ch ^ 85) & 63];
	/* ----------- findBiggestNum ----------- */
	keygen[3] = ((char *)alphabet)[findBiggestNum(argv[1], len)];
	/* ----------- mult_each_char ----------- */
	keygen[4] = ((char *)alphabet)[mult_each_char(argv[1], len)];
	/* ----------- randonchar_gen ----------- */
	keygen[5] = ((char *)alphabet)[randonchar_gen(argv[1])];
	keygen[6] = '\0';
	for (ch = 0; keygen[ch]; ch++)
		printf("%c", keygen[ch]);
	return (0);
}
