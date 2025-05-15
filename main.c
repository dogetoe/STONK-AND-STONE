#include <stdio.h>
#include <unistd.h>

// player variables
char input; // used for general menu navigation
float money = 15000; // player's money
int inputstock; // input for buying stock
int inputstocksell; // input for selling stock

// neg grass variables
float grassstockvalue = 3985.8;
int grassstocktotal = 26000;
int grassstockcirculation = 2584;
int grassstocksowned = 0;


int main() {
    printf("Welcome to STONKS AND STONES!\n");
    sleep(2);
    printf("\n");
    printf("You are fully liable to reimburse the market value of all your possesions within 7 days. You currently need to pay off your 1M dollar debt.\n");
    sleep(4);
    for(int i = 0; i < 1000; i++) { 
        // begin game loop
        printf("1: Negative Grass (NG) Options\n");
        printf("2: Eat & Eat LLC (E&E LLC) Options\n");
        printf("3: AlphaTest (AT) Options\n");
        printf("4: DogeWare (DW) Options\n");
        printf("5: Horrible Games (HG) Options\n");
        printf("6: Exit\n");
        printf("\n");
        printf("Your current balance: %f\n", money);
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
            printf("\n");
            scanf(" %c", &input);
            if (input == '1') {
                printf("How many stocks do you want to buy?\n");
                scanf(" %d", &inputstock);
                if (money >= grassstockvalue) {
                    if (inputstock <= grassstockcirculation) {
                        if (money >= grassstockvalue * inputstock) {
                            money -= grassstockvalue * inputstock;
                            grassstocksowned += inputstock;
                            grassstockcirculation -= inputstock;
                            printf("Your balance is now: %f\n", money);
                            printf("The amount of stocks for this company you own is: %d\n", grassstocksowned);
                            sleep(2);
                            continue;
                        } else {
                            printf("You do not have enough money. Current money: %f\n", money);
                            sleep(2);
                            continue;
                        }
                    } else {
                        printf("There is not enough stocks. Current amount of stocks in circulation: %d\n", grassstockcirculation);
                        sleep(2);
                        continue;
                    }
                } else {
                    printf("You do not have enough money. Current money: %f\n", money);
                    sleep(2);
                    continue;
                }
            }
            if (input == '2') {
                printf("How many stocks do you want to sell?\n");
                scanf(" %d", &inputstocksell);
                if (inputstocksell <= grassstocksowned) {
                    money += grassstockvalue * inputstocksell;
                    grassstocksowned -= inputstocksell;
                    grassstockcirculation += inputstocksell;
                    printf("Your current balance is: %f. The amount of stocks you now own under this company is: %d\n", money, grassstocksowned);
                    sleep(2);
                    continue;
                } else {
                    printf("Invalid input of stocks that you want to sell. Please input an integer. Current amount of stocks owned under this company: %d\n", grassstocksowned);
                    sleep(2);
                    continue;
                }
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