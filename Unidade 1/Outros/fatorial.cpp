#include <stdio.h>

int fatorial(int num) {

int fat;

if (num != 0) {

	fat = num * fatorial(num-1);
	return fat;

} else return 1;
}

int main() {

int num;

scanf("%d", &num);
printf("\n%d\n", fatorial(num));

return 0;
}
