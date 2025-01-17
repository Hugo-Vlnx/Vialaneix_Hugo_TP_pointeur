#include <stdio.h>




int main() {
	int a = 5;
	printf("voici : %p\n", &a);

	int *p = &a;
	printf("voici :%p\n", p);

	printf("voici :%p\n", &p);
	*p = 7;  
	printf("voici : %d \n ", a);

}