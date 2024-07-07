#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int number, guess, nguess=1;
    srand(time(0));
    number = rand()%100 + 1; // Generates a random number between 1 and 100
    
    printf("Welcome to Guess_The_Number Game!!\n\n");
    // Keeps running the loop until the number is guessed
    do{
        printf("Guess the number between 1 to 100 :");
        scanf("%d", &guess);
        if(guess>number){
            printf("Lower number please!\n");
        }
        else if(guess<number){
            printf("Higher number please!\n");
        }
        else{
            printf("You guessed it in %d attempts!!\n", nguess);
        }
        nguess++;
    }while(guess!=number);
    
    return 0;
}