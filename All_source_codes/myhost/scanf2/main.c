#include <stdio.h>
#include <stdint.h>
#include <windows.h>


int main(void){


	uint8_t chars[8];

	printf("Enter 6 characters separated by spaces:");
	scanf("%c %c %c %c %c %c", &chars[0], &chars[1], &chars[2], &chars[3], &chars[4], &chars[5]);


	for(int i=0; i < 6; i++)
	{

		printf("%c -> %u\n", chars[i], chars[i]);

	}


	printf("Press any key to continue...");
	getchar();

	return 0;
}
