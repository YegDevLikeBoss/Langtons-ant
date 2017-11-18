#include <stdio.h>
#include <stdlib.h>

#define SPACE 30

int space[SPACE][SPACE];

void matformat(char at);

int main()
{
    int x=SPACE/2, y=SPACE/2, count=0, init=0, neg=-1, x_num=1, y_num=1;
    matformat('0');
    matformat('d');

    while (init<300)
    {
        if (x<0)
            x=SPACE-1;
            else if (x>=SPACE)
                x=0;
        if (y<0)
            y=SPACE-1;
            else if (y>=SPACE)
                y=0;
        if (space[y][x]==0)
            space[y][x]=1;
            else
                space[y][x]=0;
        init++;
        matformat('d');
        if (count==0)
        {
            count=1;
            y+=y_num;
            if (space[y][x]==0)
                x_num*=neg;
            /*if (y_num==-1)
                x_num*=neg;*/
        } else

        if (count==1)
        {
            count=0;
            x+=x_num;
            if (space[y][x]==0)
                y_num*=neg;
            /*if (x_num==-1)
                y_num*=neg;*/
        }

    }
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
                printf("%d ", space[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
