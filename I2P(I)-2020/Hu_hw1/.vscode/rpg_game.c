#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p_hp = 0, p_atk = 0, p_def = 0;
    int e_hp = 0, e_atk = 0, e_def = 0;
    scanf("%d %d %d", &p_hp, &p_atk, &p_def);
    scanf("%d %d %d", &e_hp, &e_atk, &e_def);
    printf("Battle Start \\^_^/\n");
    while(p_hp > 0 && e_hp > 0)
    {
        printf("The player dealt %d damage to the enemy", p_atk - e_def); 
        printf(" and the enemy dealt %d damage to the player\n", e_atk - p_def);
        p_hp -= (e_atk - p_def);
        e_hp -= (p_atk - e_def);
        printf("The player has %d HP left", p_hp);
        printf(" and the enemy has %d HP left\n", e_hp);
    }
    printf("Battle End \\^_^/\n");

    return 0;
}