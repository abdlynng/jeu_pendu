/* ⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆
   ⋆  $Author: Abdlynng
⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆*/
#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"

int main()
{
    printf("\t============================================\n"
            "\t**********\tJEU DE PENDU\t *********** \n"
           "\t============================================\n\n\t");

    char *motSecret ="BONJOUR";
    char *motGrille =  malloc(strlen(motSecret) * sizeof(char) );
    jouer(motSecret, motGrille);

    return 0;
}
