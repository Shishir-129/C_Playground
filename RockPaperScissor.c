#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int rps(char you,char comp)
{
    //return 1 for win, -1 for lose, 0 for draw
    //for draw
    if(you==comp)
    return 0;

    //for win or lose
    else if(you=='r'&& comp=='p')
    return -1;

    else if(you=='r'&& comp=='s')
    return 1;

    else if(you=='p'&& comp=='r')
    return 1;

    else if(you=='p'&& comp=='s')
    return -1;

    else if(you=='s'&& comp=='r')
    return -1;

    else if(you=='s'&& comp=='p')
    return 1;

}

int main()
{
    int n,result;
    char you,comp;
    srand(time(0));
    n=rand()%100+1;
    if (n<33)
    comp='r';
    else if (n>33 && n<66)
    comp='p';
    else
    comp='s';

    printf("Welcome to Rock-Paper-Scissors !\n\n");
    printf("Enter 'r' for rock, 'p' for paper, 's' for scissor :");
    scanf("%c",&you);
    result=rps(you,comp);
    printf("You: '%c' and  Computer: '%c'\n",you,comp);
    if(result==1)
    printf("You win!");
    else if(result==-1)
    printf("You lose!");
    else
    printf("Game draw!");
    return 0;
}