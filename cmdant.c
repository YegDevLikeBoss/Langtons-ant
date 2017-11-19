#include <stdio.h>
#include <stdlib.h>

#define SPACE 80
#define INIT 10000

int space[SPACE][SPACE];
int x=SPACE/2, y=SPACE/2, init=0;

void matformat(char at);
void up();
void down();
void left();
void right();

int main()
{
    matformat('0');
    up();
    matformat('d');
    return 1;
}

void matformat(char at)
{
    int i, j;
    if (at<='9'&&at>='0')
    {
        at-='0';
        for (i=0;i<SPACE;i++)
        {
            for (j=0;j<SPACE;j++)
            {
                space[i][j]=at;
            }
        }
    }
    if (at=='d'){
        for (i=0;i<SPACE;i++)
        {
            for (j=0;j<SPACE;j++)
            {
                if (space[j][i]!=0)
                    printf("# ");
                    else
                        printf("  ");
            }
            printf("\n");
        }
        printf("\n");
    }
}

void up()
{
    if (init<INIT)
    {
        y--; /*Changing coordinates*/
        if (y<0) /*Looping space*/
            (y=SPACE-1);
        (space[x][y]==0) ? (space[x][y]=1) : (space[x][y]=0) ; /*Inverting cell value*/
        (space[x][y]!=0) ? right() : left() ; /*Recurring to next move*/
        init++; /*Initialization loop*/
    }
    else
        return;

    return;
}
void down()
{
    init++; /*Initialization loop*/
    y++; /*Changing coordinates*/
    if (y==SPACE) /*Looping space*/
            y=0;
    (space[x][y]==0) ? (space[x][y]=1) : (space[x][y]=0) ; /*Inverting cell value*/
    (space[x][y]!=0) ? left() : right() ; /*Recurring to next move*/
}
void left()
{
    init++; /*Initialization loop*/
    x--; /*Changing coordinates*/
    if (x<0) /*Looping space*/
            x=SPACE-1;
    (space[x][y]==0) ? (space[x][y]=1) : (space[x][y]=0) ; /*Inverting cell value*/
    (space[x][y]!=0) ? up() : down() ; /*Recurring to next move*/
}
void right()
{
    init++; /*Initialization loop*/
    x++; /*Changing coordinates*/
    if (x==SPACE) /*Looping space*/
            x=0;
    (space[x][y]==0) ? (space[x][y]=1) : (space[x][y]=0) ; /*Inverting cell value*/
    (space[x][y]!=0) ? down() : up() ; /*Recurring to next move*/
}
