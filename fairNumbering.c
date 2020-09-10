#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "math.h"

int digits(int st, int ed)
{
    int total = 0;
    for (int j = 1; j <= ed; j *= 10)
        total += (ed - j + 1);
    for (int j = 1; j < st; j *= 10)
        total -= (st - 1 - j + 1);
    return total;
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) { // N not 1
        int st;
        int ed;
        scanf("%d%d", &st, &ed);
        fprintf(stderr, "%d %d\n", st, ed);
        int total = digits(st, ed);
        fprintf(stderr, "%d\n", total);
        total /= 2;
        int mid = (ed - st) / 2 - 1;
        mid = st + mid;
        fprintf(stderr, "%d\n", mid);
        int next = mid / 2;
        fprintf(stderr, "%d\n", next);
        int found = 0;
        while (found == 0)
        {
            int dig = digits(st, mid);
            if (dig <= total)
            {
                if (dig == total)
                {
                    found = 1;
                    break;
                }
                if (digits(st, mid + 1) > total)
                {
                    found = 1;
                    break ;
                }
                //mid += next;
                //next /= 2;
                mid++;
            }
            else
            {
                mid --;
            }
        }
        printf("%d\n", mid);
    }
    return 0;
}
