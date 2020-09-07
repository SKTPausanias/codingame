#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    // the total number of nodes in the level, including the gateways
    int N;
    // the number of links
    int L;
    // the number of exit gateways
    int E;
    scanf("%d%d%d", &N, &L, &E);
    int links[L][2];
    int gateways[E];
    for (int i = 0; i < L; i++) {
        // N1 and N2 defines a link between these nodes
        int N1;
        int N2;
        scanf("%d%d", &N1, &N2);
        links[i][0] = N1;
        links[i][1] = N2;
        //fprintf(stderr, "%d  %d\n", N1, N2);
    }
    for (int i = 0; i < E; i++) {
        // the index of a gateway node
        int EI;
        scanf("%d", &EI);
        gateways[i] = EI;
        //fprintf(stderr, "%d", EI);
    }
    int bol = 0;
    // game loop
    while (1) {
        // The index of the node on which the Skynet agent is positioned this turn
        int SI;
        scanf("%d", &SI);
        bol = 0;
        for (int i = 0; i < L; i++)
        {
            if (links[i][0] == SI || links[i][1] == SI)
            {
                fprintf(stderr, "%d\n", SI);
                if (links[i][0] == SI)
                {
                    for (int j = 0; j < E; j++)
                    {
                        if (links[i][1] == gateways[j])
                        {
                            printf("%d %d\n", links[i][0], links[i][1]);
                            bol = 1;
                            break;
                        }
                    }
                }
                else
                {
                    for (int j = 0; j < E; j++)
                    {
                        if (links[i][0] == gateways[j])
                        {
                            printf("%d %d\n", links[i][0], links[i][1]);
                            bol = 1;
                            break;
                        }
                    }
                }
            }
        }
        int i = 0;
        if (!bol)
            printf("%d %d\n", links[i][0], links[i][1]);
        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");


        // Example: 0 1 are the indices of the nodes you wish to sever the link between
    }

    return 0;
}
