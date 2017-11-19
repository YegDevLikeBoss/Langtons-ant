#include <stdio.h>
#include <stdlib.h>

#define SPACE 30
#define INIT 10

int space[SPACE][SPACE];
int x=SPACE/2, y=SPACE/2, ant_up, init=0;

void matformat(char at);
int up()
{
    if (init>INIT)
    {
        return 1;
    }
    y--;
    if (space[x][y]==0)
        space[x][y]=1;
        else space[x][y]=0;
    matformat('d');


    if (space[x][y]!=0) {

        right(); }
        else
            left();
    init++;


}
void down()
{
    y++;
    if (space[x][y]==0)
        space[x][y]=1;
        else space[x][y]=0;
    matformat('d');


    if (space[x][y]!=0) {

        left(); }
        else
            right();
    init++;


}
void left()
{
    x--;
    if (space[x][y]==0)
        space[x][y]=1;
        else space[x][y]=0;
    matformat('d');


    if (space[x][y]!=0) {

        up(); }
        else
            down();

    init++;


}
void right()
{
    x++;
    if (space[x][y]==0)
        space[x][y]=1;
        else space[x][y]=0;
    matformat('d');


    if (space[x][y]!=0) {

        down(); }
        else
            up();

    init++;


}


int main()
{
    matformat('0');
    matformat('d');
    up();

    if (init>INIT)
        return 1;
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
                printf("%d ", space[j][i]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

