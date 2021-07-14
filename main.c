#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Niveau()
{
    int choix = 0;

    while (choix < 1 || choix > 3)
    {
        printf("== CHOIX NIVEAU == \n");
        printf("1. 1-100 \n");
        printf("2. 1-1000 \n");
        printf("3. 1-10000 \n");
        printf("Choix du niveau : ");
        scanf("%d", &choix);
    }

    return choix;
}

int main()
{
    int nombreMystere = 0, nombreEntree = 0, compteur_de_coup = 1, nouvelle_partie = 0;
    int MIN = 1;

    do //boucle pour nouvelle partie
    {
        switch(Niveau())
        {
        case 1:
            { //après un ":" on ne peut pas directement déclarer de variable (donc mettre des accolades)
                int MAX = 100;
                srand(time(NULL)); //generation aléatoire d'un chiffre
                nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
            }
            break;
        case 2:
            {
                int MAX = 1000;
                srand(time(NULL)); //generation aléatoire d'un chiffre
                nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
            }
            break;
        case 3:
            {
                int MAX = 10000;
                srand(time(NULL)); //generation aléatoire d'un chiffre
                nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
            }
            break;
        default:
            printf("Choix niveau incorrect");
            break;
        }

        /*if(choix_niveau == 1)
        {
           int MAX = 100, MIN = 1;
            srand(time(NULL)); //generation aléatoire d'un chiffre
            nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
        }
        else if(choix_niveau == 2)
        {
            int MAX = 1000, MIN = 1;
            srand(time(NULL)); //generation aléatoire d'un chiffre
            nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
        }
        else if(choix_niveau == 3)
        {
            int MAX = 10000, MIN = 1;
            srand(time(NULL)); //generation aléatoire d'un chiffre
            nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
        }
        else
        {
            printf("Niveau demande inexistant");
        } */

        printf("Quel est le nombre ?");
        do
        {
            scanf("%d", &nombreEntree);

            if(nombreEntree > nombreMystere)
            {
                printf("C'est moins ! \n");
            }
            else if (nombreEntree < nombreMystere)
            {
                printf("C'est plus ! \n");
            }
            else
            {
                printf("Bravo, vous avez trouve le nombre mystere en %d coups !! \n", compteur_de_coup);
            }
            compteur_de_coup++;
        }
        while(nombreEntree != nombreMystere);
        printf("Jouer une nouvelle partie ? (1 = oui , 0 = non) :");
        scanf("%d", &nouvelle_partie);
    }
    while(nouvelle_partie);

    return 0;
}
