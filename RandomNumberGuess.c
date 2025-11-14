#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess;
    printf("Please enter a number between 1 and 99: ");
    scanf("%d",&guess);

    srand(time(NULL));
    int randomNumber = (rand() % 90) + 10;

    if (guess == randomNumber) {
        printf("You win!\n");
    }
    else {
        printf("You lose!\n");
    }
}