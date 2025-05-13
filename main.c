#include <stdio.h>
char input;
float money;
float grassstockvalue;

int main() {
    printf("You are fully liable to reimburse the market value of all your possesions within 7 days. You currently need to pay off your 1M dollar debt.\n");
    for(int i = 0; i < 1000; i++) { 
        printf("1: Buy NG (Negative Grass) Stocks\n");
        scanf(" %c", &input);
        if (input == '1') {
            money = money - grassstockvalue;
            printf("%f\n", money);
        }
    }
    return 0;
}