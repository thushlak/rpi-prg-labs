#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    printf("***********************************************************\n");
    printf("**----------------Welcome to Guessing Game---------------**\n");
    printf("**---------You can guess if you understand the MATH -----**\n");
    printf("**---------------------------------------------------------\n");
    printf("\n\n");

    const int MAX_CHANCES = 7;

    int computer_guess;

    long seed = time(NULL);
    srand(seed);

    computer_guess = rand() % 100;

    printf("Program has guessed a number, what you need to do is match it.\n");
    printf("Remember, you have only 7 chances.\n");
    printf("Best wishes...\n\n");

    int user_guess;

    int chance_count = 1;
    int match = 0;

    while (match == 0 && chance_count <= MAX_CHANCES)
    {
        printf("Enter your number: ");
        scanf("%d", &user_guess);

        if (user_guess > computer_guess)
        {
            printf("Your guess is high\n");

            printf(
                "Chances remaining: %d\n",
                MAX_CHANCES - chance_count
            );
        }
        else if (user_guess < computer_guess)
        {
            printf("Your guess is low\n");

            printf(
                "Chances remaining: %d\n",
                MAX_CHANCES - chance_count
            );
        }
        else
        {
            printf("Bingo!! You have won the game.\n");

            printf(
                "You found the number in %d step(s).\n",
                chance_count
            );

            match = 1;
        }

        if (match == 0)
        {
            chance_count++;
        }

        printf("\n");
    }

    if (match == 0)
    {
        printf("Game Over!!! Try to be Mathematical.\n");
        printf("The number was %d\n", computer_guess);
    }

    return 0;
}