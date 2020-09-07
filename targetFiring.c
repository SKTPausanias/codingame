#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

typedef struct  t_spaceship
{
    char type[8];
    int hp;
    int armor;
    int damage;
    float priority;
}               s_spaceship;

s_spaceship assignator(s_spaceship n2)
{
    s_spaceship new;
    strcpy(new.type, n2.type);
    new.hp = n2.hp;
    new.armor = n2.armor;
    new.damage = n2.damage;
    new.priority = n2.priority;
    return new;
}

int main()
{
    int myHealth = 5000;
    int N;
    scanf("%d", &N);
    s_spaceship sships[N];
    for (int i = 0; i < N; i++) {
        char TYPE[8];
        int HP;
        int ARMOR;
        int DAMAGE;
        scanf("%s%d%d%d", TYPE, &HP, &ARMOR, &DAMAGE);
        strcpy(sships[i].type, TYPE);
        sships[i].hp = HP;
        sships[i].armor = ARMOR;
        sships[i].damage = DAMAGE;
    }

    for (int i = 0; i < N; i++)
    {
        int dmg_deal;
        if (strcmp(sships[i].type, "FIGHTER") == 0)
            dmg_deal = 20 - sships[i].armor;
        else
            dmg_deal = 10 - sships[i].armor;
        if (dmg_deal <= 0)
            dmg_deal = 1;
        int resist_turns = (int)ceil((float)sships[i].hp / (float)dmg_deal);
        sships[i].priority = (float)sships[i].damage / (float)resist_turns; 
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (sships[j].priority < sships[j - 1].priority)
            {
                s_spaceship aux = assignator(sships[j]);
                sships[j] = assignator(sships[j - 1]);
                sships[j - 1] = assignator(aux);
            }
        }
    }

    int j = N - 1;
    while (j >= 0)
    {
        for (int i = j; i >= 0; i--)
            myHealth -= sships[i].damage;
        int dmg_deal;
        if (strcmp(sships[j].type, "FIGHTER") == 0)
            dmg_deal = (20 - sships[j].armor);
        else if (strcmp(sships[j].type, "CRUISER") == 0)
            dmg_deal = (10 - sships[j].armor);
        if (dmg_deal <= 0)
            dmg_deal = 1;
        sships[j].hp -= dmg_deal;
        if (sships[j].hp <= 0)
            j--;
    }

    if (myHealth < 0)
        printf("FLEE\n");
    else
        printf("%d\n", myHealth);
    return 0;
}
