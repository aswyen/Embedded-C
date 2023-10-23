#include <stdio.h>
#include <stdint.h>

int main (void){

	unsigned age;
	printf("Enter your age in years:");
	scanf("%u", &age);

	if(age >= 18){
		printf("Congrats, you can vote!\n");
	}else{
		printf("Come back in %d years!", 18-age);

	}

	return 0;
}
