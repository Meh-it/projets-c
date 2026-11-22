#include <stdio.h>

int main(void) {
    FILE *fichier = fopen("passConfig.txt", "r");
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir passConfig.txt\n");
        return 1;
    }

    char tabCourant[11];
    int scoresGenerale[100];
    int nbLus = 0;

    while (nbLus < 100 && fscanf(fichier, "%10s", tabCourant) == 1) {
        int score = 0;

        /* R1 : +10 points pour chaque caractere distinct apparaissant >= 4 fois */
        char dejaVu[10];
        int nbDejaVu = 0;

        for (int j = 0; j < 10; j++) {
            char cible = tabCourant[j];
            int occurence = 0;

            for (int k = 0; k < 10; k++) {
                if (tabCourant[k] == cible) {
                    occurence++;
                }
            }

            int dejaCompte = 0;
            for (int d = 0; d < nbDejaVu; d++) {
                if (dejaVu[d] == cible) {
                    dejaCompte = 1;
                }
            }

            if (occurence >= 4 && !dejaCompte) {
                score += 10;
                dejaVu[nbDejaVu] = cible;
                nbDejaVu++;
            }
        }

        /* R2 : +10 points pour chaque paire de caracteres voisins identiques */
        for (int l = 0; l < 9; l++) {
            if (tabCourant[l] == tabCourant[l + 1]) {
                score += 10;
            }
        }

        scoresGenerale[nbLus] = score;
        nbLus++;
    }

    fclose(fichier);

    int tresVulnerables = 0;
    int vulnerables = 0;
    int semiVulnerables = 0;
    int aucunCritere = 0;

    for (int i = 0; i < nbLus; i++) {
        if (scoresGenerale[i] > 30) {
            tresVulnerables++;
        } else if (scoresGenerale[i] >= 20) {
            vulnerables++;
        } else if (scoresGenerale[i] == 10) {
            semiVulnerables++;
        } else {
            aucunCritere++;
        }
    }

    printf("Tres vulnerables (>30) : %d\n", tresVulnerables);
    printf("Vulnerables (20 a 30) : %d\n", vulnerables);
    printf("Semi-vulnerables (10) : %d\n", semiVulnerables);
    printf("Aucun critere detecte (0) : %d\n", aucunCritere);

    return 0;
}


Tu as maintenant les 4 fichiers complets (`mission1.c` à `mission4.c`) pour ton portfolio[cite: 5]. Tu veux qu'on passe au suivi des candidatures de stage maintenant ?
