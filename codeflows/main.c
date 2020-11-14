#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
	long long ncakes;
	scanf("%lld", &ncakes);
	long long heights[ncakes];
	long long i = 0;
	for(i=0; i < ncakes; i++)
    	scanf("%lld", &heights[i]);
	long long tasknum;
	scanf("%lld", &tasknum);
	i = 0;
	long long solutions[tasknum];
	long long suma = 0;
	long long suma2 = 0;
	long long h = 0;
	while (h < ncakes)
	{
		if (h % 2 == 0)
			suma += heights[h];
		else
			suma2 += heights[h];
		h++;
	}
	while (i < tasknum)
	{
		long long task;
		scanf("%lld", &task);
		if (task == 1)
		{
			long long j = 1;
			long long h = 0;
			long long tasks[3];
			scanf("%lld%lld%lld", &tasks[0], &tasks[1], &tasks[2]);
			h = tasks[0];
			h--;
			long long rest = tasks[1] - tasks[0] + 1;
			if (--tasks[0] % 2 == 0)
			{
				suma += (((rest + 1) / 2) * tasks[2]);
				suma2 += ((rest / 2) * tasks[2]);
			}
			else
			{
				suma += ((rest / 2) * tasks[2]);
				suma2 += (((rest + 1) / 2) * tasks[2]);			
			}
		}
		else if (task == 2)
			printf("%lld\n", suma);
		else if (task == 3)
			printf("%lld\n", suma2);
		i++;
	}
	return 0;
}