#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
	int ncakes;
	scanf("%d", &ncakes);
	int heights[ncakes + 1];
	int i = 0;
	while (i < ncakes)
	{
		scanf("%d", heights[i]);
		i++;
	}
	printf("%d\n", ncakes);
	i = 0;
	while (i < ncakes)
	{
		printf("%d", heights[i]);
		i++;
	}
}