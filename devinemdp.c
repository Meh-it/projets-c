#include <stdio.h>

int main() {
    int tabSecret[8];
    int tabTentatives[8];
    int tentativesUtilisees = 0;
    int victoire = 0;

    for (int i = 0; i < 8; i++) {
        tabTentatives[i] = -1;
    }

    printf("Dr. Mechant, saisissez les 8 chiffres du code secret (0 a 9) :\n");
    for (int i = 0; i < 8; i++) {
        int val;
        do {
            printf("Chiffre %d : ", i + 1);
            if (scanf("%d", &val) != 1) {
                printf("Erreur de saisie.\n");
                return 1;
            }
            if (val < 0 || val > 9) {
                printf("Valeur invalide, entrez un chiffre entre 0 et 9.\n");
            }
        } while (val < 0 || val > 9);
        tabSecret[i] = val;
    }

    printf("\nEtat initial : ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", tabTentatives[i]);
    }
    printf("\n");

    while (tentativesUtilisees < 8 && !victoire) {
        int prop;
        do {
            printf("Agent DSP, proposez un chiffre (0 a 9) : ");
            if (scanf("%d", &prop) != 1) {
                printf("Erreur de saisie.\n");
                return 1;
            }
            if (prop < 0 || prop > 9) {
                printf("Proposition hors bornes (0..9), non comptee.\n");
            }
        } while (prop < 0 || prop > 9);

        tentativesUtilisees++;

        for (int i = 0; i < 8; i++) {
            if (tabSecret[i] == prop) {
                tabTentatives[i] = prop;
            }
        }

        printf("Etat actuel : ");
        int casesRestantes = 0;
        for (int i = 0; i < 8; i++) {
            printf("%d ", tabTentatives[i]);
            if (tabTentatives[i] == -1) {
                casesRestantes++;
            }
        }
        printf("\nTentatives utilisees : %d\n", tentativesUtilisees);

        if (casesRestantes == 0) {
            victoire = 1;
        }
    }

    if (victoire) {
        printf("Victoire ! Code retrouve en %d tentative(s).\n", tentativesUtilisees);
    } else {
        printf("Echec ! Le code secret etait : ");
        for (int i = 0; i < 8; i++) {
            printf("%d ", tabSecret[i]);
        }
        printf("\n");
    }

    return 0;
}
