#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

// player variables
char input; // used for general menu navigation
float money = 15000; // player's money
int inputstock; // input for buying stock
int inputstocksell; // input for selling stock

// event variables
int randomevent = 0; // random events are based on an int, triggering certain events if within a certain range

// neg grass variables
float grassstockvalue = 3985.8;
int grassstocktotal = 26000;
int grassstockcirculation = 2584;
int grassstocksowned = 0;

// dogeware variables
float dogestockvalue = 386;

// event that crashes stock market
void Asteroid() {
    printf("\n");
    printf("    ____\n");
    printf("  /  o  \\ \n");
    printf("/        \\______\n");
    printf(" \\      o      |\n");
    printf("   \\         O/\n");
    printf("    \\ o      /\n");
    printf("     | ___ o / \n");
    printf("          |_|\n");
    printf("\n");
    printf("BREAKING NEWS: ASTEROID INCOMING; STOCK MARKET CRASHING DUE TO INVESTORS DIVESTING.\n");
    printf("It is advisable to divest assets prior to entering bankruptcy to ensure optimal financial outcome. Remember: corporate failure is a temporary condition. Bankruptcy is usually not.\n");
    printf("\n");
    grassstockvalue -= 1291;
    printf("Current Negative Grass stock value: %f\n", grassstockvalue);
    sleep(1);
}

// event that increases DogeWare stock value by a lot
void DogeWareSpreadSheet() {
    printf("BREAKING NEWS: DogeWare just released a new popular spreadsheet program that has increased their share value by 100 percent!\n");
    printf("Heres what the program looks like:\n");
    printf("_____________________________\n");
    printf("| _ | _ | _ | _ | _ | _ | _ |\n");
    printf("| _ | _ | _ | _ | _ | _ | _ |\n");
    printf("| _ | _ | _ | _ | _ | _ | _ |\n");
    printf("| _ | _ | _ | _ | _ | _ | _ |\n");
    printf("| _ | _ | _ | _ | _ | _ | _ |\n");
    printf("| _ | _ | _ | _ | _ | _ | _ |\n");
    printf("| _ | _ | _ | _ | _ | _ | _ |\n");
    printf("| _ | _ | _ | _ | _ | _ | _ |\n");
    printf("| _ | _ | _ | _ | _ | _ | _ |\n");
    printf("| _ | _ | _ | _ | _ | _ | _ |\n");
    printf("| _ | _ | _ | _ | _ | _ | _ |\n");
    printf("-----------------------------\n");
    dogestockvalue *= 2;
    printf("Current DogeWare stock value: %f\n", dogestockvalue);
    sleep(1);
}

// event randomizer
void RandomEvent(int min, int max, int count) {

    // taking current time as seed
    unsigned int seed = time(0);

    // generate a random number in the range [min, max]
    int rd_num = rand_r(&seed) % (max - min + 1) + min;
    
    randomevent = rd_num;
    if (randomevent == 0) {
        Asteroid();
    } else if (randomevent == 1) {
        DogeWareSpreadSheet();
    } else {
        
    }
    
}


int main() {
    int min = 0;
    int max = 3;
    int count = 1;
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
                            RandomEvent(min, max, count);
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