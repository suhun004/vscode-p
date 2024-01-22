#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char origin[] = "BlockDMask";
	char dest[20] = "aaabbb";
	strcat(dest, origin);
	memset(dest, 'o', 4);
	printf("%s\n", dest);
	
	return 0;
}
