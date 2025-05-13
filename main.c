#include <stdio.h>
char input;
float money = 100;
float grassstockvalue = 3985.8;

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
        printf("\n");
        scanf(" %c", &input);

        // all of this is negative grass menu
        if (input == '1') {
            printf("Negative Grass (NG) Stocks:\n");
            printf("Current Stock Value: %f\n", grassstockvalue);
            printf("1: Buy Stock\n");
            printf("2: Sell Stock\n");
            printf("3: Back\n");
            scanf(" %c", &input);
            if (input == '1') {
                if (money >= grassstockvalue) {
                    money = money - grassstockvalue;
                    printf("%f\n", money);
                    break;
                } else {
                    break;
                }
            }
            if (input == '2') {
                // put sell mechanic when stock system done
            }
            if (input == '3') {
                break;
            }
        }
    }
    return 0;
}