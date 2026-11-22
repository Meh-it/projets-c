#include <stdio.h>

int main() {
    int a, b;
    char op;
    double resultat;

    printf("Premier entier : ");
    if (scanf("%d", &a) != 1) {
        printf("Erreur de saisie.\n");
        return 1;
    }

    printf("Deuxieme entier : ");
    if (scanf("%d", &b) != 1) {
        printf("Erreur de saisie.\n");
        return 1;
    }

    printf("Operation (+,-,*,/) : ");
    scanf(" %c", &op);

    if (op == '+') {
        resultat = (double)a + (double)b;
        printf("Resultat : %.2f\n", resultat);
    } else if (op == '-') {
        resultat = (double)a - (double)b;
        printf("Resultat : %.2f\n", resultat);
    } else if (op == '*') {
        resultat = (double)a * (double)b;
        printf("Resultat : %.2f\n", resultat);
    } else if (op == '/') {
        if (b == 0) {
            printf("Erreur : division par zero impossible.\n");
        } else {
            resultat = (double)a / (double)b;
            printf("Resultat : %.2f\n", resultat);
        }
    } else {
        printf("Erreur : operation inconnue.\n");
    }

    return 0;
}
