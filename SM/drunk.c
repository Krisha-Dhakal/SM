#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random step
int randomStep() {
    return rand() % 4; // 0: North, 1: South, 2: East, 3: West
}

int main() {
    int n, step; // Number of steps
    int x = 0, y = 0; // Initial position at (0, 0)

    // Seed the random number generator with the current time
    srand(time(NULL));

    printf("Enter the number of steps: ");
    scanf("%d", &n);

    printf("Starting at (0, 0)\n");

    for (step = 1; step <= n; step++) {
        int move = randomStep();

        // Update the position based on the random step
        switch (move) {
            case 0: // North
                y++;
                break;
            case 1: // South
                y--;
                break;
            case 2: // East
                x++;
                break;
            case 3: // West
                x--;
                break;
        }

        printf("Step %d: Moved ", step);
        switch (move) {
            case 0:
                printf("North");
                break;
            case 1:
                printf("South");
                break;
            case 2:
                printf("East");
                break;
            case 3:
                printf("West");
                break;
        }
        printf(" to (%d, %d)\n", x, y);
    }

    printf("Final position: (%d, %d)\n", x, y);

    return 0;
}
