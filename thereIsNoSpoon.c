#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

int main()
{
    // the number of cells on the X axis
    int width;
    scanf("%d", &width);
    // the number of cells on the Y axis
    int height;
    scanf("%d", &height); fgetc(stdin);
    char mat[height][32];
    for (int i = 0; i < height; i++) {
        // width characters, each either 0 or .
        fgets(mat[i], 32, stdin);
    }

    for (int i = 0; i < height; i++) {
        // width characters, each either 0 or .
        fprintf(stderr, "%s", mat[i]);
    }

    fprintf(stderr, "%d", height); 

    for (int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++)
        {
            int right = -1;
            int below = -1; 
            if (mat[i][j] == '0')
            {
                for (int h = j + 1; h < width; h++)
                {
                    if (mat[i][h] == '0')
                    {
                        right = h;
                        break;
                    }
                }
                for (int k = i + 1; k < height; k++)
                {
                    if (mat[k][j] == '0')
                    {
                        below = k;
                        break;
                    }
                }
                if (right != -1 && below != -1)
                    printf("%d %d %d %d %d %d\n", j, i, right, i, j, below);
                else if (right != -1)
                    printf("%d %d %d %d %d %d\n", j, i, right, i, -1, -1);
                else if (below != -1)
                    printf("%d %d %d %d %d %d\n", j, i, -1, -1, j, below);
                else
                    printf("%d %d %d %d %d %d\n", j, i, -1, -1, -1, -1);
            }
        }   
    }
    return 0;
}
