#include <stdio.h>

int n = 0;
int tmpFunc(int a, int b) {
	printf("tmpFunc is called, a = %d, b = %d \n", a, b);
	return (a + b);
}

int main() {
	int tmp;
	tmp = 1;
	tmp++;
	tmp--;
	n += 100;
	n -= 12;
	printf("tmp = %d, n = %d \n", tmp, n);
 	
	tmp = tmpFunc(1, 2);
	printf("tmp = %d", n);

	return 0;
}
