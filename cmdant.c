#include <stdio.h>
#include <stdlib.h>

#define SPACE 80
#define INIT 8300

int space[SPACE][SPACE];
int x=SPACE/2, y=SPACE/2, ant_up, init=0, f;

void matformat(char at);
int up();
void down();
void left();
void right();

int main()
{
    matformat('0');
    f=up();
    printf("%d\n", f);
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

int up()
{
    if (init<INIT)
    {

    y--;
    if (space[x][y]==0)
        space[x][y]=1;
        else space[x][y]=0;
    /*matformat('d');*/


    if (space[x][y]!=0) {

        right(); }
        else
            left();
    init++;
    }
    else
        return 7;

}
void down()
{
    init++;
    y++;
    if (space[x][y]==0)
        space[x][y]=1;
        else space[x][y]=0;
    /*matformat('d');*/


    if (space[x][y]!=0) {

        left(); }
        else
            right();




}
void left()
{
    init++;
    x--;
    if (space[x][y]==0)
        space[x][y]=1;
        else space[x][y]=0;
    /*matformat('d');*/


    if (space[x][y]!=0) {

        up(); }
        else
            down();




}
void right()
{
    init++;
    x++;
    if (space[x][y]==0)
        space[x][y]=1;
        else space[x][y]=0;
    /*matformat('d');*/


    if (space[x][y]!=0) {

        down(); }
        else
            up();




}
