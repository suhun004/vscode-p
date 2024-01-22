#include <stdio.h>

int main() {
	char* p;
	int a = 0X13016377;
	p = (char*)&a;
	int i;
	for (i = 0; i < 4; i++) {
		printf("%X ", p[i]);
	}
	printf("\n");

	return 0;
}
