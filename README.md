# Battaglia Navale

Un programma in linguaggio C che simula una partita a Battaglia Navale tra due giocatori. Le navi vengono posizionate casualmente su una griglia, e i giocatori si alternano per colpire le navi avversarie. Vince chi affonda tutte le navi dell'avversario.

## Caratteristiche

- **Griglia dinamica:** La dimensione della griglia (tra 9x9 e 13x13) viene determinata casualmente.
- **Navi di diverse dimensioni:**
  - 1 nave da 4 celle
  - 2 navi da 3 celle
  - 3 navi da 2 celle
  - 4 navi da 1 cella
- **Turni alternati:** I giocatori scelgono le coordinate per colpire la griglia dell'avversario.
- **Stato delle celle:**
  - `O`: Cella occupata da una nave
  - `X`: Cella colpita con una nave
  - `-`: Cella colpita vuota
  - `.`: Cella vuota o nascosta

## Requisiti

- Compilatore C (ad esempio, `gcc`).
- Sistema operativo con supporto a C standard (Windows, Linux, macOS).

## Installazione ed Esecuzione

### Compilazione
Per compilare il programma, usa il comando:
```bash
gcc battaglia_navale.c -o battaglia_navale
```

### Esecuzione
Per eseguire il programma, usa il comando:
```bash
./battaglia_navale
```

Durante l'esecuzione:
1. Il programma genererà una griglia per ciascun giocatore con le navi posizionate casualmente.
2. I giocatori si alterneranno per inserire le coordinate di attacco.
3. Il gioco termina quando tutte le navi di un giocatore vengono affondate.

## Struttura del Programma

- **Funzioni principali:**
  - `creaTabella()`: Crea una griglia vuota per il giocatore.
  - `place_ship()`: Posiziona le navi sulla griglia.
  - `stampaTabella()`: Visualizza lo stato della griglia (nascosto o completo).
  - `shoot()`: Gestisce l'attacco di un giocatore, aggiornando la griglia.
  - `tutteNaviAffondate()`: Controlla se tutte le navi di un giocatore sono state affondate.

- **Logica del gioco:**
  - I giocatori inseriscono le coordinate di attacco.
  - Il programma verifica se la cella contiene una nave (`Colpito!`) o è vuota (`Mancato!`).
  - Il gioco termina quando tutte le navi di un giocatore sono colpite.

## Esempio di Gioco

Durante una partita, il programma mostrerà messaggi come:
```
Turno del Giocatore 1
Griglia avversaria:
. . . . .
. . . . .
. . . . .
. . . . .
. . . . .
Inserisci le coordinate (riga e colonna): 2 3
Colpito!
```

## Personalizzazione

Puoi modificare le dimensioni della griglia o il numero di navi modificando le chiamate a `place_ship()`:
```c
for (int i = 0; i < 2; i++) place_ship(tabella_G1, numero_casuale, 3); // Cambia numero di navi o dimensioni
```

## Suggerimenti per il Debug

- **Coordinate fuori dai limiti:** Il programma verifica e notifica se le coordinate sono fuori dai limiti della griglia.
- **Celle già attaccate:** Il programma impedisce di attaccare una cella già colpita.
