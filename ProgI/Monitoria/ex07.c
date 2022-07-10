/*
 * Exercício 7 - Monitoria Prog I
 * Autor: Jheam Storch Ross
 */

#include <stdio.h>

typedef struct
{
    int attack;
    int defense;
} tPokemon;

tPokemon newPokemon(int attack, int defense) {
    tPokemon pokemon;

    pokemon.attack = attack;
    pokemon.defense = defense;

    return pokemon;
}

double getPower(tPokemon this) {
    return (this.attack + this.defense) / 2.0;
}

tPokemon readPokemon() {
    int attk, def;
    scanf("%d %d", &attk, &def);

    return newPokemon(attk, def);
}

typedef struct
{
    tPokemon pokemon;
    int level;
} tMaster;

tMaster newMaster(tPokemon pokemon, int lvl) {
    tMaster master;

    master.pokemon = pokemon;
    master.level = lvl;

    return master;
}

double getStrength(tMaster this, int bonuses) {
    if (this.level % 2 == 0) {
        return getPower(this.pokemon) + bonuses;
    }
    
    return getPower(this.pokemon);
}

tMaster readMaster() {
    tPokemon pokemon = readPokemon();
    int lvl;
    scanf("%d", &lvl);

    return newMaster(pokemon, lvl);
}

typedef struct
{
    tMaster lucas;
    tMaster luana;
    int bonuses;
} tDuel;

tDuel newDuel(tMaster lucas, tMaster luana, int bonuses) {
    tDuel duel;

    duel.lucas = lucas;
    duel.luana = luana;
    duel.bonuses = bonuses;

    return duel;
}

/* @returns
 *  0: draw
 *  1: lucas wins
 *  2: luana wins
 */
int settleBattle(tDuel this) {
    double lucasPw = getStrength(this.lucas, this.bonuses);
    double luanaPw = getStrength(this.luana, this.bonuses);

    if (lucasPw > luanaPw) {
        return 1;
    }
    else if (luanaPw > lucasPw) {
        return 2;
    }
    else {
        return 0;
    }
}

void printDuel(tDuel this) {
    switch (settleBattle(this))
    {
    case 0:
        printf("Empate");
        break;

    case 1:
        printf("Lucas");
        break;

    case 2:
        printf("Luana");
        break;
    }
    printf("\n");
}

tDuel readDuel() {
    int bonuses;
    scanf("%d", &bonuses);
    tMaster lucas = readMaster();
    tMaster luana = readMaster();

    return newDuel(lucas, luana, bonuses);
}

void main(void) {
    int t;
    scanf("%d", &t);

    while (t--) {
        tDuel curr = readDuel();

        printDuel(curr);
    }
}
