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
float dogestockvalue = 386;\
int dogestockcirculation = 1275;

// horrible games variables
float horriblestockvalue =  184929;

void WorstHorribleGame() {
    printf("BREAKING NEWS: Horrible Games hyped over 6 million fans for a new AAA game, only for it to be their worst game yet!\n");
    printf("Even though it had over 7 million sales in the first day, players were so disappointed that investors are divesting!\n");
    printf("Here's what the game looks like, it doesn't even have any actual graphics!\n");
    printf("        _________\n");
    printf("       /        /\n");
    printf("     __         |\n");
    printf("     |         /\n");
    printf("      |        |\n");
    printf("       _______/\n");
    printf("\n");
    printf("                      _\n");
    printf("                     |_|\n");
    printf("                    --|--\n");
    printf("                      |\n");
    printf("                     | |\n");
    printf("                     | |\n");
    printf("----------------------------------------\n");
    printf("                                       |\n");
    printf("                                       |\n");
    printf("                                       |\n");
    printf("                                       |\n");
    printf("                                       |\n");
    printf("\n");
    printf("\n");
    printf("Horrible Games' share value dropped almost to half of what it had been!\n");
    horriblestockvalue /= 1.5;
    printf("Current Horrible Games share value: %f\n", horriblestockvalue);
    printf("\n");
    printf("\n");
    sleep(1);
}

// event that crashes stock market
void Asteroid() {
    printf("\n");
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
    printf("Current Negative Grass share value: %f\n", grassstockvalue);
    sleep(1);
}

// event that increases DogeWare stock value by a lot
void DogeWareSpreadSheet() {
    printf("\n");
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
    printf("Current DogeWare share value: %f\n", dogestockvalue);
    sleep(1);
}

// negative grass increases
void GrassDecrease() {
    printf("\n");
    printf("BREAKING NEWS: Sudden decrease in grass has people questioning Negative Grass while investors are investing by the second, eager to get a share of the company's profits!\n");
    grassstockvalue *= 3;
    printf("Current Negative Grass share value: %f\n", grassstockvalue);
    sleep(1);
}

// DogeWare circulation decreases
void BuyStockCrashMarket() {
    printf("\n");
    printf("\n");
    printf("BREAKING NEWS: CEO of AlphaTest has decided to invest in all of DogeWare's shares, rendering DogeWare's share circulation near 0!\n");
    if (dogestockcirculation <= 290) {
        dogestockcirculation -= 100;
        if (dogestockcirculation <= 0) {
            dogestockcirculation = 27;
            printf("\n");
            printf("Current DogeWare shares in circulation: %d", dogestockcirculation);
            printf("\n");
        } else {
            printf("\n");
            printf("Current DogeWare shares in circulation: %d", dogestockcirculation);
            printf("\n");
        }
    } else {
        dogestockcirculation = 84;
        printf("\n");
        printf("Current DogeWare shares in circulation: %d", dogestockcirculation);
        printf("\n");
    }
    printf("\n");
    printf("\n");
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
    } else if (randomevent == 2) {
        GrassDecrease(); // increases Neg Grass value bc grass disappears
    } else if (randomevent == 3) {
        WorstHorribleGame();
    } else if (randomevent == 4) {
        BuyStockCrashMarket();
    }
    
}


int main() {
    int min = 0;
    int max = 7;
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