#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
	long long ntest;
	scanf("%lld", &ntest);
	int i = 0;
	while (i < ntest)
	{
		int test;
		scanf("%d", &test);
		int j = 0;
		int arr[test];
		int mul = 1;
		while (j < test)
		{
			scanf("%d", &arr[j]);
			mul *= arr[j];
			j++;
		}
		j = 0;
		while (j < test)
		{
			if (j - 1 == test)
				printf("%d\n", mul);
			else 
				printf("%d ", mul);
			j++;
		}
		i++;
	}
	return 0;
}