
void initialiserMotSecret(char *mot){
int i = 0;
    for (i = 0; i < sizeof(mot)-1; i++)
        mot[i] = '*';
    afficherMot(mot);
}


void afficherMot(char *mot){
    int i = 0;
    printf("Mot Secret : ");
    for (i=0; i<strlen(mot); i++)
        printf("%c",mot[i]);

    printf("\n");
}

char lireCaractere()
{
    char caractere = 0;

    // pour s'assurer que le caractere ne soit pas un espace ou retour a la ligne \n
    do{
        caractere = getchar(); // On lit le premier caractère
    }while(caractere == '\n' || caractere == ' ');

    caractere = toupper(caractere); //convertir la lettre en majuscule
    // On lit les autres caractères mémorisés un à un jusqu'au \n pour les effacer
    while (getchar() != '\n') {}

    return caractere; // On retourne le premier caractère qu'on a lu
}

int rechercherLettre(char *mot, char lettre, char *decouvrirMot){
    int i = 0;
    int test = 0;
    while(i < strlen(mot)){
        // pour tester la decouverte du premier caractere dans le mot
        if (lettre == mot[i]){
            // chercher si la lettre est encore present dans le mot
            for (i=i; i<strlen(mot); i++){
                if(lettre == mot[i])
                    decouvrirMot[i]= lettre;
            }
            i = strlen(mot); //pour sortir du boucle while
            test = 1;
        }
        else
            i++;
    }
    afficherMot(decouvrirMot);

    return test;
}

// on cherche si il n'y a plus de * dans le mot grillé ce qui signifie que le joueur a gagné
int gagner (char *mot){
    int b = 0;
    //on teste si on pas de * dans le mot grillé
    if(strchr(mot, '*'))
        b +=1;
    return b;
}

void jouer(char *motSecret, char *motGrille){

    char lettre ;
    int compteur = 10;

    initialiserMotSecret(motGrille);

    do{
        printf("\tProposer une lettre :");
        lettre = lireCaractere();
        if(rechercherLettre(motSecret,lettre,motGrille) == 0){
            compteur--;
            printf("Vous avez encore %d coups\n",compteur);
        }
    }while(gagner(motGrille) != 0 && compteur > 0);

    if (compteur != 0)
        printf("\n\t\tBRAVO .... Vous avez gagne.....!!!!!!!\n\n");
    else{
        printf("\n\tVous avez PERDU la partie \n\t ");
        afficherMot(motSecret);
    }
// pour lancer ou non une nouvelle partie
    char sortie;
    do{
        printf("\nVoulez Vous rejouer \n\t 1. Rejouer \n\t 0. Quitter\n\t ******>> ");
        sortie = lireCaractere();
    }while(sortie != '1' && sortie != '0');

    switch (sortie){
        case '1': jouer(motSecret,motGrille); break;
        case '0': exit(0); break;
    }

}


void rejouer (){

}
