#include <stdio.h>


int main(void){

	char a = 100;
	char b = 0;

	char *pa = &a;



	printf("a=%c, &a=%p\n", a, &a);
	printf("b=%c, &b=%p\n", b, &b);

	b = *pa;

	printf("a=%c, &a=%p\n", a, &a);
	printf("b=%c, &b=%p\n", b, &b);

	*pa = 65;

	printf("a=%c, &a=%p\n", a, &a);
	printf("b=%c, &b=%p\n", b, &b);





	return 0;
}
