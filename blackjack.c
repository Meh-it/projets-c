#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

struct Carte
{
    int valeur;
    char symbole[5];
};


struct Carte convertDeck(int cartenum){
    int k;
    struct Carte carte;

    for(k = 0; k < 52; k += 4)
    {
        if(cartenum == k)
        {
            carte.valeur = cartenum;
            strcpy(carte.symbole, "♠");
        }
    }

    for(k = 1; k < 52; k += 4)
    {
        if(cartenum == k)
        {
            carte.valeur = cartenum;
            strcpy(carte.symbole, "♥");
        }
    }

    for(k = 2; k < 52; k += 4)
    {
        if(cartenum == k)
        {
            carte.valeur = cartenum;
            strcpy(carte.symbole, "♦");
        }
    }

    for(k = 3; k < 52; k += 4)
    {
        if(cartenum == k)
        {
            carte.valeur = cartenum;
            strcpy(carte.symbole, "♣");
        }
    }

    return carte;
}

void printCarte(struct Carte carte)
{
    printf("Valeur : %d\n", carte.valeur);
    printf("Symbole : %s\n", carte.symbole);
}


int tirerCarte(int min, int max){
    int carte = (rand() % (max - min + 1)) + min;

    //printf("La carte tirée est de numéro %d\n", carte);

    return carte;
}

int sommeMain(int n[], int size, int actor){
    int sum = 0;

    for (int i = 0; i < size; i++){
        sum += n[i];
    }
    if (actor == 0){
        printf("La somme de la main joueur est de %d\n", sum);
    }else {
        printf("La somme de la main croupier est de %d\n", sum);
    }

    return sum;
}

bool sumDepasse(int somme){
    if (somme >= 21){
        //printf("La somme dépasse 21\n");

        return true;
    }
    //printf("La somme ne dépasse pas 21\n");

    return false;
}

void valeurCarte(int *carte, int jeuCarte[]){
    *carte = jeuCarte[*carte];
}

void piocher(int main[], int *index, int jeu[]){
    int carte = tirerCarte(0, 51);
    valeurCarte(&carte, jeu);

    main[*index] = carte;

    printf("Picohe la carte\n");
    printCarte(convertDeck(carte));

    (*index)++;
}

bool win(int sumMainJoueur, int sumMainCroup){
    if (sumMainJoueur > 21){
        printf("perdu\n");
        return false;
    }
    else if (sumMainCroup > 21){
        printf("gagné\n");
        return true;
    }
    else if (sumMainJoueur > sumMainCroup){
        printf("gagné\n");
        return true;
    }
    else if (sumMainJoueur < sumMainCroup){
        printf("perdu\n");
        return false;
    }
    else {
        printf("égalité\n");
        return false;
    }
}




int main(){
    srand((unsigned)time(NULL));

    // INIT DATA
    int cartes[52] = {
        1,1,1,1, 2,2,2,2, 3,3,3,3, 4,4,4,4,
        5,5,5,5, 6,6,6,6, 7,7,7,7, 8,8,8,8,
        9,9,9,9, 10,10,10,10, 10,10,10,10,
        10,10,10,10, 10,10,10,10
    };

    struct Carte deck[52];



    int manche = 1;


    // INIT PLAYER
    int mise = 0;
    int solde = 1000;

    int mainJoueur[11];
        for (int i = 0; i < 11; i++){
            mainJoueur[i] = 0;
        }
        int indexMain = 0;




    // INIT CROUPIER
    int mainCroup[11];
        for (int i = 0; i < 11; i++){
            mainCroup[i] = 0;
        }
        int indexMainCroup = 0;





    printf("Saisissez votre mise : \n");
    while (mise <= 0 || mise > 1000){
        scanf("%d", &mise);
    }
    printf("Vous avez misé %d\n", mise);

    // PLAYING
    while (sumDepasse(sommeMain(mainJoueur, 11, 0)) == false && sumDepasse(sommeMain(mainCroup, 11, 1)) == false ){
        printf("===============DEBUT MANCHE %d===============\n", manche);printf("\n");

        if (manche == 1){
            piocher(mainJoueur, &indexMain, cartes);
            piocher(mainJoueur, &indexMain, cartes);
            printf("\n");
            piocher(mainCroup, &indexMainCroup, cartes);
            piocher(mainCroup, &indexMainCroup, cartes);
        }

        char choix = 'n';

            printf("\nQue faire ?\nh : HIT\ns : STAND\nq : Quitter\n");
            scanf(" %c", &choix);

        

        // CHOIX HIT STAND QUITTER
        if (choix == 'h'){
            piocher(mainJoueur, &indexMain, cartes);
            piocher(mainCroup, &indexMainCroup, cartes);
            if (win(sommeMain(mainJoueur, 11, 0), sommeMain(mainCroup, 11, 1)) == true){
                solde += mise * 2;
            }
            else {
                solde = solde - mise;
            }
            break;
        }

        else if (choix == 's'){

            if (win(sommeMain(mainJoueur, 11, 0), sommeMain(mainCroup, 11, 1)) == true){
                solde += mise * 2;
            }
            else {
                solde = solde - mise;
            }
            break;
        }

        else if (choix == 'q'){
            printf("Vous quittez\n");
            break;
        }
        manche++;

        printf("===============FIN MANCHE %d===============\n", manche);printf("\n");printf("\n");printf("\n");
    }
    printf("Votre solde est de %d\n", solde);

    return 0;
}
// gcc blackjack.c -o bj && ./bj