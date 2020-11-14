#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
	long long ntest;
	scanf("%lld", &ntest);
	int i = 0;
	int nzeros = 0;
	int nunos = 0;
	int ndos = 0;
	while (i < ntest)
	{
		int total = 0;
		scanf("%d%d%d", &nzeros, &nunos, &ndos);
		total += nzeros;
		if (nunos >= ndos)
		{
			int rest = nunos - ndos;
			int rest2 = nunos - rest;
			total += rest2;
			rest /= 3;
			total += rest;
		}
		else if (ndos > nunos)
		{
			int rest = ndos - nunos;
			int rest2 = ndos - rest;
			total += rest2;
			rest *= 2;
			rest /= 6;
			total += rest;
		}
		printf("%d\n", total);
		i++;
	}
	return 0;
}