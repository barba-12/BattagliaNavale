#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** creaTabella(int num) {
    int** lista = (int**)malloc(num * sizeof(int*));
    for (int i = 0; i < num; i++) {
        lista[i] = (int*)malloc(num * sizeof(int));
        for (int y = 0; y < num; y++) {
            lista[i][y] = 0; // 0 indica cella vuota
        }
    }
    return lista;
}

void place_ship(int** lista, int num, int l) {
    int nave_non_piazzata = 1;
    while (nave_non_piazzata) {
        int x_nave = rand() % num;
        int y_nave = rand() % num;
        int direzione = rand() % 2; // 0 = orizzontale, 1 = verticale
        int valido = 1;

        // Verifica validità posizione
        for (int i = 0; i < l; i++) {
            int x = x_nave + (direzione == 1 ? i : 0);
            int y = y_nave + (direzione == 0 ? i : 0);
            if (x >= num || y >= num || lista[x][y] == 1) {
                valido = 0;
                break;
            }
        }

        if (valido) {
            for (int i = 0; i < l; i++) {
                int x = x_nave + (direzione == 1 ? i : 0);
                int y = y_nave + (direzione == 0 ? i : 0);
                lista[x][y] = 1; // 1 indica cella occupata da una nave
            }
            nave_non_piazzata = 0;
        }
    }
}

void stampaTabella(int** lista, int num, int mostraNavi) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (lista[i][j] == 1 && !mostraNavi) {
                printf(". "); // Nasconde le navi all'avversario
            } else if (lista[i][j] == 1) {
                printf("O "); // Mostra le navi
            } else if (lista[i][j] == 2) {
                printf("X "); // Cella colpita con nave
            } else if (lista[i][j] == 3) {
                printf("- "); // Cella colpita vuota
            } else {
                printf(". "); // Cella vuota
            }
        }
        printf("\n");
    }
    printf("\n");
}

int shoot(int** lista, int x, int y, int num) {
    if (x < 0 || x >= num || y < 0 || y >= num) {
        printf("Coordinate fuori dai limiti!\n");
        return 0;
    }
    if (lista[x][y] == 1) {
        lista[x][y] = 2; // 2 indica cella colpita con nave
        printf("Colpito!\n");
        return 1;
    } else if (lista[x][y] == 0) {
        lista[x][y] = 3; // 3 indica cella vuota colpita
        printf("Mancato!\n");
        return 0;
    } else {
        printf("Hai già sparato qui!\n");
        return 0;
    }
}

int tutteNaviAffondate(int** lista, int num) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (lista[i][j] == 1) return 0; // C'è ancora una nave non colpita
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    int val_min = 9, val_max = 13;
    int numero_casuale = val_min + rand() % (val_max - val_min + 1);

    printf("Griglia di dimensione %d x %d\n", numero_casuale, numero_casuale);

    // Creazione delle griglie per i due giocatori
    int** tabella_G1 = creaTabella(numero_casuale);
    int** tabella_G2 = creaTabella(numero_casuale);

    // Posizionamento navi per entrambi i giocatori
    for (int i = 0; i < 1; i++) place_ship(tabella_G1, numero_casuale, 4); // 1 nave da 4
    for (int i = 0; i < 2; i++) place_ship(tabella_G1, numero_casuale, 3); // 2 navi da 3
    for (int i = 0; i < 3; i++) place_ship(tabella_G1, numero_casuale, 2); // 3 navi da 2
    for (int i = 0; i < 4; i++) place_ship(tabella_G1, numero_casuale, 1); // 4 navi da 1

    for (int i = 0; i < 1; i++) place_ship(tabella_G2, numero_casuale, 4); // 1 nave da 4
    for (int i = 0; i < 2; i++) place_ship(tabella_G2, numero_casuale, 3); // 2 navi da 3
    for (int i = 0; i < 3; i++) place_ship(tabella_G2, numero_casuale, 2); // 3 navi da 2
    for (int i = 0; i < 4; i++) place_ship(tabella_G2, numero_casuale, 1); // 4 navi da 1

    int turno = 1;
    while (!tutteNaviAffondate(tabella_G1, numero_casuale) && !tutteNaviAffondate(tabella_G2, numero_casuale)) {
        printf("Turno del Giocatore %d\n", turno);
        if (turno == 1) {
            printf("Griglia avversaria:\n");
            stampaTabella(tabella_G2, numero_casuale, 0);
            int x, y;
            printf("Inserisci le coordinate (riga e colonna): ");
            scanf("%d %d", &x, &y);
            shoot(tabella_G2, x, y, numero_casuale);
            if (tutteNaviAffondate(tabella_G2, numero_casuale)) {
                printf("Giocatore 1 ha vinto!\n");
                break;
            }
        } else {
            printf("Griglia avversaria:\n");
            stampaTabella(tabella_G1, numero_casuale, 0);
            int x, y;
            printf("Inserisci le coordinate (riga e colonna): ");
            scanf("%d %d", &x, &y);
            shoot(tabella_G1, x, y, numero_casuale);
            if (tutteNaviAffondate(tabella_G1, numero_casuale)) {
                printf("Giocatore 2 ha vinto!\n");
                break;
            }
        }
        turno = 3 - turno; // Alterna tra 1 e 2
    }

    // Libera la memoria
    for (int i = 0; i < numero_casuale; i++) {
        free(tabella_G1[i]);
        free(tabella_G2[i]);
    }
    free(tabella_G1);
    free(tabella_G2);

    return 0;
}
