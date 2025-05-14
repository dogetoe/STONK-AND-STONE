#include <stdio.h>

// player variables
char input;
float money = 100;
int inputstock;

// neg grass variables
float grassstockvalue = 3985.8;
int grassstocktotal = 26000;
int grassstockcirculation = 2584;
int grassstocksowned = 0;


int main() {
    printf("Welcome to STONKS AND STONES!");
    printf("You are fully liable to reimburse the market value of all your possesions within 7 days. You currently need to pay off your 1M dollar debt.\n");
    for(int i = 0; i < 1000; i++) { 
        // begin game loop
        printf("1: Negative Grass (NG) Options\n");
        printf("2: Eat & Eat LLC (E&E LLC) Options\n");
        printf("3: AlphaTest (AT) Options\n");
        printf("4: DogeWare (DW) Options\n");
        printf("5: Horrible Games (HG) Options\n");
        printf("6: Exit\n");
        printf("\n");
        scanf(" %c", &input);

        // all of this is negative grass menu
        if (input == '1') {
            printf("Negative Grass (NG) Stocks:\n");
            printf("Current Stock Value: %f\n", grassstockvalue);
            printf("Total amount of stocks (including unavailable ones): %d\n", grassstocktotal);
            printf("Total amount of stocks available for purchase: %d\n", grassstockcirculation);
            printf("Amount of stocks you own: %d\n", grassstocksowned);
            printf("1: Buy Stock\n");
            printf("2: Sell Stock\n");
            printf("3: Back\n");
            scanf(" %c", &input);
            if (input == '1') {
                printf("How many stocks do you want to buy?\n");
                scanf(" %d", &inputstock);
                if (money >= grassstockvalue) {
                    if (inputstock <= grassstockcirculation) {
                        if (money >= grassstockvalue * inputstock) {
                            money = money - grassstockvalue * inputstock;
                            printf("%f\n", money);
                            continue;
                        } else {
                            printf("You do not have enough money. Current money: %f\n", money);
                            continue;
                        }
                    } else {
                        printf("There is not enough stocks. Current amount of stocks in circulation: %d\n", grassstockcirculation);
                        continue;
                    }
                } else {
                    printf("You do not have enough money. Current money: %f\n", money);
                    continue;
                }
            }
            if (input == '2') {
                // put sell mechanic when stock system done
                continue;
            }
            if (input == '3') {
                continue;
            }
        }
        if (input == '6') {
            break;
        }
    }
    return 0;
}