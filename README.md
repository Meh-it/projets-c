# Projets en langage C – Mehdi CHARGUI
 
Projets réalisés en 2026 au Conservatoire National des Arts et Métiers (Cnam), à Paris, pendant mon DSP Développement et exploitation de parcs informatiques. Ce sont des devoirs pratiques des cours d'Algorithmique et Programmation en C. Chaque programme s'utilise dans le terminal. Je les ai écrits sous VS Code et compilés avec GCC.
 
## Sommaire
 
| N° | Projet | Dossier | Statut |
|----|--------|---------|--------|
| 1 | Sondage entre 5 films | [`01-sondage-films`](01-sondage-films) | Terminé |
| 2 | Morpion à deux joueurs | [`02-morpion`](02-morpion) | Terminé |
| 3 | Calculatrice | [`03-calculatrice`](03-calculatrice) | Terminé |
| 4 | Code secret à retrouver | [`04-code-secret`](04-code-secret) | Terminé |
| 5 | Message intercepté (déchiffrement) | [`05-message-intercepte`](05-message-intercepte) | Terminé |
| 6 | Audit de mots de passe fictifs | [`06-audit-mots-de-passe`](06-audit-mots-de-passe) | Terminé |
| 7 | Blackjack | [`07-blackjack`](07-blackjack) | En cours |
 
## Compiler et exécuter
 
```bash
gcc fichier.c -o programme
./programme
```
 
---
 
## 1. Sondage entre 5 films
 
**Contexte :** projet réalisé en 2026 au Cnam, dans le cadre de ma formation. Il fallait écrire une application de vote en console pour une sélection de 5 films.
 
**Ce que fait le programme :** il affiche un menu, enregistre les votes, vérifie les saisies et affiche le décompte final.
 
**Notions utilisées :** conditions `if / else`, boucle `for` pour le décompte des voix, boucle `while` pour garder le menu actif.
 
**Test :** j'ai essayé des saisies incorrectes, le programme ne plante pas.
 
**Code :** [`01-sondage-films/sondage.c`](01-sondage-films/sondage.c)
 
---
 
## 2. Morpion à deux joueurs
 
**Contexte :** devoir pratique réalisé au Cnam dans le cadre du cours d'Algorithmique et Programmation en C. Il fallait développer un jeu de morpion interactif à deux joueurs dans le terminal, sans utiliser de tableaux multidimensionnels.
 
**Ce que fait le programme :** le premier joueur choisit son symbole (`X` ou `O`), puis les deux joueurs jouent chacun leur tour sur une grille 3x3. Le programme refuse les coups invalides et annonce le vainqueur ou le match nul.
 
**Notions utilisées :**
- la grille est représentée par 9 variables `char` (`case11` à `case33`) initialisées avec `'-'` ;
- affichage avec `printf()` et lecture des coups avec `scanf()` ;
- vérification des coordonnées (entre 1 et 3) et de la case (libre ou non) ;
- test des 8 alignements possibles (3 lignes, 3 colonnes, 2 diagonales) ;
- match nul quand les 9 cases sont occupées sans alignement.
**Code :** [`02-morpion/morpion.c`](02-morpion/morpion.c)
 
---
 
## 3. Calculatrice
 
**Contexte :** Devoir 2 d'Algorithmique en C (« Mission PEACE-007-DSP »), mission 1, à rendre le 20 novembre 2026.
 
**Ce que fait le programme :** il demande deux entiers puis une opération (`+`, `-`, `*` ou `/`), et affiche le résultat en nombre décimal avec deux chiffres après la virgule. Par exemple, 7 / 2 donne `3.50`. Il refuse la division par zéro et signale une opération inconnue.
 
**Notions utilisées :** saisie avec `scanf()`, choix de l'opération avec `if / else if` ou `switch`, affichage d'un réel avec deux décimales.
 
**Code :** [`03-calculatrice/mission1.c`](03-calculatrice/mission1.c)
 
---
 
## 4. Code secret à retrouver
 
**Contexte :** Devoir 2, mission 2, à rendre le 20 novembre 2026. Le scénario est fictif : un agent est prisonnier sur une île et doit retrouver le code d'une porte avant d'épuiser ses tentatives.
 
**Ce que fait le programme :** un premier utilisateur saisit un code secret de 8 chiffres (de 0 à 9). Le second propose un chiffre à la fois. Si ce chiffre apparaît plusieurs fois dans le code, toutes ses positions sont révélées. Le programme affiche l'état des 8 cases après chaque proposition et compte les tentatives. Le joueur gagne quand plus aucune case n'est inconnue, avec au maximum 8 propositions valides. Une saisie hors de 0 à 9 est redemandée sans compter de tentative.
 
**Notions utilisées :** deux tableaux d'entiers (`tabSecret[8]` et `tabTentatives[8]`, ce dernier initialisé à `-1`), boucles, conditions, contrôle des saisies.
 
**Code :** [`04-code-secret/mission2.c`](04-code-secret/mission2.c)
 
---
 
## 5. Message intercepté (déchiffrement)
 
**Contexte :** Devoir 2, mission 3, à rendre le 20 novembre 2026. Le scénario est fictif : un message codé a été intercepté et il faut le décoder.
 
**Ce que fait le programme :** il parcourt un tableau de 100 entiers compris entre -1 et 25. Chaque `-1` donne un espace. Les autres valeurs sont des indices dans un tableau de 26 lettres rangées dans un ordre différent de l'alphabet. Le message complet est affiché sur une seule ligne. Il est reconstitué par le programme : la phrase n'est pas écrite dans le code.
 
**Notions utilisées :** tableaux d'entiers et de caractères, boucle `for`, condition sur la valeur lue.
 
**Code :** [`05-message-intercepte/mission3.c`](05-message-intercepte/mission3.c)
 
---
 
## 6. Audit de mots de passe fictifs
 
**Contexte :** Devoir 2, mission 4, à rendre le 20 novembre 2026. Le fichier `passConfig.txt` contient 100 mots de passe fictifs de 10 caractères, un par ligne. Le début du programme (ouverture du fichier, lecture avec une boucle `while`, rangement du score dans `scoresGenerale[i]`) était fourni. J'ai écrit le calcul du score et les statistiques.
 
**Ce que fait le programme :** pour chaque mot de passe, il calcule un score de vulnérabilité avec deux règles :
- R1 : +10 pour chaque caractère présent au moins 4 fois ;
- R2 : +10 pour chaque paire de caractères identiques consécutifs (les paires qui se chevauchent comptent).
Ensuite, il compte les mots de passe par catégorie (très vulnérable au-dessus de 30, vulnérable de 20 à 30, semi-vulnérable à 10, aucun critère à 0) et affiche uniquement les statistiques finales.
 
**Notions utilisées :** lecture d'un fichier texte, chaînes de caractères (`char tabCourant[11]`), parcours de tableaux, comptage par catégorie.
 
**Code :** [`06-audit-mots-de-passe/mission4.c`](06-audit-mots-de-passe/mission4.c)
 
---
 
## 7. Blackjack (en cours)
 
**Contexte :** Devoir 3 d'Algorithmique en C, à rendre et à présenter à l'oral le 24 novembre 2026. Il s'agit d'une version simplifiée du blackjack pour une startup fictive, « RachidCasino ». Le jeu se joue avec une monnaie fictive (des Rach$), sans argent réel.
 
**Ce qui est demandé :**
- Partie 1 : un seul joueur. Il commence avec 1 000 Rach$, saisit sa mise, reçoit deux cartes tirées au hasard, puis choisit HIT, STAND ou QUIT dans une boucle `while`. S'il dépasse 21, il perd sa mise.
- Partie 2 : jouer contre la banque, qui tire aussi ses cartes.
- Partie 3 : une extension au choix (affichage des cartes tirées, cartes non répétées dans une partie, ou type `struct` pour une carte).
**Notions utilisées :** fonctions, tableau des 52 cartes, tirage aléatoire (`rand()`, `srand()`, `time()`), variable booléenne, boucle `while`. La fonction de tirage et le tableau de cartes étaient fournis.
 
**Statut :** en cours de développement.
 
**Code :** [`07-blackjack`](07-blackjack)
 
---
 
## Contact
 
- E-mail : mehdi.chargui07@gmail.com
- LinkedIn : https://www.linkedin.com/in/mehdi-chargui-it/
- Portfolio : https://meh-it.github.io/Portfolio-Mehdi/
