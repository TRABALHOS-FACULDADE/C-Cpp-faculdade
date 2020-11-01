#include <stdio.h>
#include <math.h>
#include <locale.h>

int fibonacci(int num) {

int f;

if ((num==1) || (num==2)) {
	
	return 1;
	
}

f = fibonacci(num-1) + fibonacci(num-2);

return f;
}

int main () {
	
setlocale(LC_ALL, "portuguese");

int n;

	scanf("%d", &n);
	printf("%d", fibonacci(n));

return 0;
}
