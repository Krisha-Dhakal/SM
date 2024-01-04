#include <stdio.h>
#include <math.h>

#define MAX_CATEGORIES_3_VAR 3
#define MAX_CATEGORIES_4_VAR 5
int i;
// Function to calculate the chi-square statistic for 3 variables
float calculateChiSquare3Var(int observed[], float expected[], int categories) {
    float chiSquare = 0.0;

    for (i = 0; i < categories; i++) {
        chiSquare += pow(observed[i] - expected[i], 2) / expected[i];
    }

    return chiSquare;
}

// Function to calculate the chi-square statistic for 4 variables
float calculateChiSquare4Var(int observed[], float expected[], int categories) {
    float chiSquare = 0.0;

    for (i = 0; i < categories; i++) {
        chiSquare += pow(observed[i] - expected[i], 2) / expected[i];
    }

    return chiSquare;
}

// Function to display the table for 3 variables
void displayTable3Var(int observed[], float expected[], int categories) {
    printf("\n-------------------------------------------------");
    printf("\n%5s\t%5s\t%5s\t%-22s\n", "S.No", "Oi", "Ei", "((Oi-Ei)*(Oi-Ei))/Ei");
    for (i = 0; i < categories; i++) {
        printf("%5d\t%5d\t%5.2f\t%10.2f\n", i + 1, observed[i], expected[i],
               ((observed[i] - expected[i]) * (observed[i] - expected[i])) / expected[i]);
    }
    printf("\n-------------------------------------------------");
}

// Function to display the table for 4 variables
void displayTable4Var(int observed[], float expected[], int categories) {
    printf("%5s%5s%5s%-22s\n", "S.No", "Oi", "Ei", "((Oi-Ei)*(Oi-Ei))/Ei");
    for (i = 0; i < categories; i++) {
        printf("%5d%5d%5.2f%10.2f\n", i + 1, observed[i], expected[i],
               ((observed[i] - expected[i]) * (observed[i] - expected[i])) / expected[i]);
    }
}

int main() {
    int observed[MAX_CATEGORIES_4_VAR] = {0};
    float expected[MAX_CATEGORIES_4_VAR] = {0.0};
    int totalSamples = 0;
    int choice;

    // Get user choice for 3-variable or 4-variable scenario
    printf("Choose the number of variables (3 or 4): ");
    scanf("%d", &choice);

    // Input observed frequencies
    printf("\nEnter observed frequencies for each category:\n");

    switch (choice) {
        case 3:
            // 3-variable scenario
            for (i = 0; i < MAX_CATEGORIES_3_VAR; i++) {
                printf("Observed frequency for %s: ", (i == 0) ? "All Same" : (i == 1) ? "All Different" : "One Pair");
                scanf("%d", &observed[i]);
                totalSamples += observed[i];
            }
            float probabilityValues1[MAX_CATEGORIES_3_VAR];
            printf("\nEnter probability values for each category (sum should be 1.0):\n");
            for ( i = 0; i < MAX_CATEGORIES_3_VAR; i++) {
                printf("Probability value for %s: ", (i == 0) ? "All Same" : (i == 1) ? "All Different" : "One Pair");
                scanf("%f", &probabilityValues1[i]);
            }
            // Calculate expected frequencies based on probability values
            for (i = 0; i < MAX_CATEGORIES_3_VAR; i++) {
                expected[i] = totalSamples * probabilityValues1[i];
            }

            break;

        case 4:
            // 4-variable scenario
            for (i = 0; i < MAX_CATEGORIES_4_VAR; i++) {
                printf("Observed frequency for %s: ", (i == 0) ? "All Same" : (i == 1) ? "All Different" :(i==2) ? "One Pair" : (i == 3) ? "Two Pair" : "Three Same");
                scanf("%d", &observed[i]);
                totalSamples += observed[i];
            }
            // Input probability values
            float probabilityValues[MAX_CATEGORIES_4_VAR];
            printf("\nEnter probability values for each category (sum should be 1.0):\n");
            for (i = 0; i < MAX_CATEGORIES_4_VAR; i++) {
                printf("Probability value for %s: ", (i == 0) ? "All Same" : (i == 1) ? "All Different" :(i==2) ? "One Pair" : (i == 3) ? "Two Pair" : "Three Same");
                scanf("%f", &probabilityValues[i]);
            }
            // Calculate expected frequencies based on probability values
            for (i = 0; i < MAX_CATEGORIES_4_VAR; i++) {
                expected[i] = totalSamples * probabilityValues[i];
            }

            break;

        default:
            printf("Invalid choice.\n");
            return 1;
    }

    
   
    // Display the table
    switch (choice) {
        case 3:
            // 3-variable scenario
            displayTable3Var(observed, expected, MAX_CATEGORIES_3_VAR);
            break;

        case 4:
            // 4-variable scenario
            displayTable4Var(observed, expected, MAX_CATEGORIES_4_VAR);
            break;

        default:
            // Invalid choice
            return 1;
    }

    // Calculate chi-square statistic and display the result
    float chiSquare;

    switch (choice) {
        case 3:
            // 3-variable scenario
            chiSquare = calculateChiSquare3Var(observed, expected, MAX_CATEGORIES_3_VAR);
            break;

        case 4:
            // 4-variable scenario
            chiSquare = calculateChiSquare4Var(observed, expected, MAX_CATEGORIES_4_VAR);
            break;

        default:
            // Invalid choice
            return 1;
    }

    printf("\nChi-square statistic: %.4f\n", chiSquare);

    // Perform the test (you may need to adjust the critical value)
    float criticalValue = 5.991; // Adjust this value based on your significance level and degrees of freedom
    if (chiSquare > criticalValue) {
        printf("\nReject the null hypothesis: Variables are not independent.\n");
    } else {
        printf("\nAccept the null hypothesis: Variables are independent.\n");
    }

    return 0;
}
