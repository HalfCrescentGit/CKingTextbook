#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_CARDS 5
#define NUM_RANKS 13

void readCards(int hand[NUM_CARDS][2]);
void analyzeHand(int hand[NUM_CARDS][2], bool *royalP, bool *straightP, bool *flushP, bool *fourP, bool *threeP, int *pairsP);
void printResult(bool *royalP, bool *straightP, bool *flushP, bool *fourP, bool *threeP, int *pairsP);

int main(void) {
    bool royal, straight, flush, four, three;
    bool *royalP = &royal; bool *straightP = &straight; bool *flushP = &flush; bool *fourP = &four; bool *threeP = &three;
    int pairs;
    int *pairsP = &pairs;
    int hand[5][2];

    for (;;) {
        readCards(hand);
        analyzeHand(hand, royalP, straightP, flushP, fourP, threeP, pairsP);
        printResult(royalP, straightP, flushP, fourP, threeP, pairsP);
    }
}

void readCards(int hand[NUM_CARDS][2]) {
    char ch, rankCh, suitCh;
    bool badCard, duplicate;
    int rank, suit;
    int i, j;
    int cardsRead = 0;

    for (i = 0; i < NUM_CARDS; i++) {
        for (j = 0; j < 2; j++)
            hand[i][j] = 0;
    }
    
    while (cardsRead < NUM_CARDS) {
        badCard = false;
        duplicate = false;

        printf("Enter a card: ");

        rankCh = getchar();
        switch (rankCh) {
            case '0': exit(EXIT_SUCCESS);
            case '2': rank = 0; break;
            case '3': rank = 1; break;
            case '4': rank = 2; break;
            case '5': rank = 3; break;
            case '6': rank = 4; break;
            case '7': rank = 5; break;
            case '8': rank = 6; break;
            case '9': rank = 7; break;
            case 't': case 'T': rank = 8; break;
            case 'j': case 'J': rank = 9; break;
            case 'q': case 'Q': rank = 10; break;
            case 'k': case 'K': rank = 11; break;
            case 'a': case 'A': rank = 12; break;
            default: badCard = true;
        }

        suitCh = getchar();
        switch (suitCh) {
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default: badCard = true;
        }

        while ((ch = getchar()) != '\n')
            if (ch != ' ') badCard = true;

        for (i = 0; i < cardsRead; i++)
            if ((hand[i][0] == rank) && (hand[i][1] == suit))
                duplicate = true;
        if (badCard)
            printf("Bad card; ignored.\n");
        else if (duplicate)
            printf("Duplicate card; ignored.\n");
        else {
            hand[cardsRead][0] = rank;
            hand[cardsRead][1] = suit;
            cardsRead++;
        }
    }
}

void analyzeHand(int hand[NUM_CARDS][2], bool *royalP, bool *straightP, bool *flushP, bool *fourP, bool *threeP, int *pairsP) {
    int sameSuit = 1;
    int numConsec = 1;
    int sameNum = 0;
    int ranks[NUM_CARDS];
    int rankCounts[NUM_RANKS] = {0};
    int sorts = 0;
    int i, j, temp;

    *flushP = false;
    *straightP = false;
    *fourP = false;
    *threeP = false;
    *pairsP = 0;

    for (i = 1; i < NUM_CARDS; i++)
        if (hand[i][1] == hand[0][1])
            sameSuit++;
    if (sameSuit == NUM_CARDS)
        *flushP = true;
    
    for (i = 0; i < NUM_CARDS; i++)
        ranks[i] = hand[i][0];
    for (; sorts < NUM_CARDS; sorts++) {
        for (i = 0; i < NUM_CARDS - 1; i++) {
            if (ranks[i] > ranks[i + 1]) {
                temp = ranks[i];
                ranks[i] = ranks[i + 1];
                ranks[i + 1] = temp;
            }
        }
    }

    if (ranks[0] == 8 && ranks[NUM_CARDS - 1] == 12)
        *royalP = true;

    for (i = 0; i < NUM_CARDS - 1; i++) {
        if (ranks[i] == ranks[i + 1] - 1)
            numConsec++;
    }
    if (numConsec == NUM_CARDS - 1 && ranks[0] == 0 && ranks[1] == 1) {
        *straightP = true;
        return;
    }
    if (numConsec == NUM_CARDS) {
        *straightP = true;
        return;
    }

    for (i = 0; i < NUM_CARDS; i++)
        rankCounts[ranks[i]]++;
    
    for (i = 0; i < NUM_RANKS; i++) {
        if (rankCounts[i] == 4) *fourP = true;
        if (rankCounts[i] == 3) *threeP = true;
        if (rankCounts[i] == 2) ++*pairsP;
    }
}

void printResult(bool *royalP, bool *straightP, bool *flushP, bool *fourP, bool *threeP, int *pairsP) {
    if (*straightP && *flushP && *royalP) printf("Royal flush");
    else if (*straightP && *flushP) printf("Straight flush");
    else if (*fourP) printf("Four of a kind");
    else if (*threeP && *pairsP == 1) printf("Full house");
    else if (*flushP) printf("Flush");
    else if (*straightP) printf("Straight");
    else if (*threeP) printf("Three of a kind");
    else if (*pairsP == 2) printf("Two pairs");
    else if (*pairsP == 1) printf("Pair");
    else printf("High card");

    printf("\n\n");
}