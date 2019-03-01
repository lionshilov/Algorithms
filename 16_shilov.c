#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void main()
{
	signed long long int result = 0;
	int c = 0;
	int n = 0;
	int i = 1;
scanf ("%d",&c);
	for (i;i<=c;i++)
{
	scanf("%d",&n);
	n = abs(n);
	result = result + (pow(-1,i+1)*pow(n,3));
	n = 0;
}
	printf("%lld",result);
}