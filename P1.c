#include <stdio.h>
#include<stdlib.h>
#define SIZE 3

int game(int **,char,char);
void board_print(int **);
int check(int **);
int main()
{
    int i,j;
    char p1,p2;
    int **a;
    printf("Game begins\n");
    printf("2 players are  there ie p1,p2\n");
    printf("p1 means you start the round\n");
    printf("Enter your choice x/o\n");
    scanf("%c",&p1);
    if(p1=='o')
    {
        p2='x';
    }
    else
    {
        p2='o';
    }
    printf("Once entered you can't re enter\n");
 
    a=(int **)malloc(SIZE*sizeof(int *));
    for(i=0;i<SIZE;i++)
    *(a+i)=(int *)malloc(SIZE*sizeof(int));
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            a[i][j]='e';
        }
    }

    game(a,p1,p2);
    board_print(a);
    return 0;
}
void board_print(int **a)
{
    printf("     |          |\n");
    printf(" %c   |     %c    |  %c\n",a[0][0],a[0][1],a[0][2]);
    printf("_____|__________|_____\n");
    printf("     |          |\n");
    printf(" %c   |     %c    |  %c\n",a[1][0],a[1][1],a[1][2]);
    printf("_____|__________|_____\n");
    printf("     |          |\n");
    printf(" %c   |     %c    |  %c\n",a[2][0],a[2][1],a[2][2]);
    printf("     |          |\n");
}
int game(int **a,char choice,char choice1)
{
    int i,j;
    int t=0;
    int turn=0;
    char req;
    char k;
    while(turn<=8)
    {
        
    while(t<5)
    {
        board_print(a);
        if(turn%2==0)
        {
            req=choice;
         printf("Player 1 turn choice is %c\n",req);
         printf("Enter the co ordinares at which you want to enter\n");
        scanf("%d %d",&i,&j);
        if(a[i][j]=='e')
         {
         
         a[i][j]=req;
         t++;
         turn++;
         }
         else
         {
             printf("can't enter in this position\n");
         }
        }
        else
        {
            req=choice1;
        printf("Player 2 turn choice is %c\n",req);
         printf("Enter the co ordinares at ywhich you want to enter\n");
        scanf("%d %d",&i,&j);
        if(a[i][j]=='e')
         {
         a[i][j]=req;
         t++;
         turn++;
         }
         else
         {
             printf("can't enter in this position\n");
         }
         
        }
    }  
   k=check(a);
   if(k!='e')
   {
       printf("%c wins\n",k);
       if(k=='x')
       {
           printf("player 1 you win\n");
           printf("congratulations");
           return 0;
       }
       else
       {
           printf("player 2 computer wins\n");
           printf("try hard\n");
           return 0;
       }
      }
     else
     {
         board_print(a);
         if(turn%2==0)
        {
            req=choice;
         printf("Player 1 turn choice is %c\n",req);
         printf("Enter the co ordinares at which you want to enter\n");
        scanf("%d %d",&i,&j);
        if(a[i][j]=='e')
         {
         
         a[i][j]=req;
         t++;
         turn++;
         }
         else
         {
             printf("can't enter in this position\n");
         }
        }
        else
        {
            req=choice1;
        printf("Player 2 turn choice is %c\n",req);
         printf("Enter the co ordinares at which you want to enter\n");
        scanf("%d %d",&i,&j);
        if(a[i][j]=='e')
         {
         a[i][j]=req;
         t++;
         turn++;
         }
         else
         {
             printf("can't enter in this position\n");
         }
     }
     }
    }
    printf("Its a draw\n");
}
int check(int **a)
{
    int i;
    for(i=0;i<SIZE;i++)
    {
    if((a[i][0]==a[i][1])&&(a[i][1]==a[i][2]))
    return a[i][1];
    }
     for(i=0;i<SIZE;i++)
    {
    if((a[0][i]==a[1][i])&&(a[1][i]==a[2][i]))
    return a[1][i];
    }
    if((a[0][0]==a[1][1])&&(a[1][1]==a[2][2]))
    return a[1][1];
    if((a[2][0]==a[1][1])&&(a[1][1]==a[0][2]))
    return a[1][1];
    else
    return 'e';
    
}



