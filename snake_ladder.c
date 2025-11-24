#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checkSnakeOrLadder(int position) {
    // Ladders
    if (position == 3)  return 22;
    if (position == 5)  return 8;
    if (position == 11) return 26;
    if (position == 20) return 29;

    // Snakes
    if (position == 27) return 1;
    if (position == 21) return 9;
    if (position == 17) return 4;
    if (position == 19) return 7;

    return position;
}

int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    int playerPosition = 1, dice;

    srand(time(0)); // seed random generator

    printf("=== Snake and Ladder Game ===\n");

    while (playerPosition < 100) {
        printf("\nPress ENTER to roll the dice...");
        getchar();

        dice = rollDice();
        printf("You rolled: %d\n", dice);

        playerPosition += dice;

        if (playerPosition > 100) {
            playerPosition -= dice; // cannot go beyond 100
            printf("You need exact number to reach 100!\n");
            continue;
        }

        printf("Moved to %d\n", playerPosition);

        int newPosition = checkSnakeOrLadder(playerPosition);

        if (newPosition > playerPosition) {
            printf("Great! You climbed a ladder to %d!\n", newPosition);
        } else if (newPosition < playerPosition) {
            printf("Oops! A snake brought you down to %d!\n", newPosition);
        }

        playerPosition = newPosition;
    }

    printf("\n🎉 Congratulations! You reached 100 and won the game!\n");

    return 0;
}
