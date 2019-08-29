#include "stdio.h"

int main()
{
	int *a;
	char *p = malloc(100);

    printf("sizeof(char):%u \n",sizeof(char));
	printf("sizeof(8):%u \n", sizeof(8));
	printf("sizeof(8.8):%u \n", sizeof(8.8));
	printf("sizeof('ab'):%u \n", sizeof("ab"));

	printf("sizeof('a'):%u \n", sizeof(a));
	printf("sizeof('*a'):%u \n", sizeof(*a));
	printf("sizeof('p'):%u \n", sizeof(p));
	printf("sizeof('*p'):%u \n", sizeof(*p));
	
	char buf[] = { 'a','b','c','d','e','f' };
	int m = strlen(buf);
	int n = sizeof(buf);
	printf(" %u:%u \n", m,n);

    return 0;
}