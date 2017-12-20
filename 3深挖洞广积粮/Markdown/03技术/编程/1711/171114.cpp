#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{   
    int i,j;
    int x = 0;
    int y = 5;

    int velocity_x = 1;
    int velocity_y = 1;
    int left = 0;
    int right = 20;
    int top = 0;
    int bottom = 10;

    while(1)
    {
        x = x + velocity_x;
        y = y + velocity_y;

        system("cls");
        for( i = 0; i < x; i++)
            printf("\n");
        for (j = 0; i < y; j++)
            printf(" ");
        printf("o");
        printf("\n");
        Sleep(50);

        if ((x == top )||(x == bottom))
            velocity_x = -velocity_x;
        if ((y == left)||(y == right))
            velocity_y = -velocity_y;

    }
    return 0;

}

#1
#include <stdio.h>

void main(){
    int i, j;
    int x = 5;
    int j = 10;
    for(i = 0; i < x; i++)
        printf("\n");
    for(j = 0; i < y; j++)
        printf(" ");
    printf("o");
    printf("\n");

}

#2 
#include <stdio.h>
#include <stdlib.h>
void main(){
    int i,j;
    int x = 1;
    int y = 10;
    for(x = 1; x < 10; x++){
        system("cls");
        for(i = 0; i < x; i++)
            printf("\n");
        for(j = 0; j < y; j++)
            printf(" ");
    }

}

#3
#include <stdio.h>
#include <stdlib.h>
void main(){
    int i, j;
    int x = 5;
    int y = 10;

    int hight = 20;
    int velocity = 1;

    while(1){
        x = x +velocity
        system("cls");
        for(i = 0; i < x; i++)
            printf("\n");
        for(j = 0; j < y; j++)
            printf(" ");
        printf("o");
        printf("\n");

        if(x == height){
            velocity = -velocity;
        }
        if(x == 0){
            velocity = -velocity;
        }

    }
}

#4
#include <stdio.h>
#include <stdlib.h>
void main(){
    int i,j;
    int i = 0;
    int y = 5;

    int velocity_x = 1;
    int velocity_y = 1;
    int left = 0;
    int right = 20;
    int top = 0;
    int bottom = 10;

    while(1){
        x = x + velocity_x;
        y = y + velocity_y;
        system("cls");
        for(i = 0; i < x; i++)
            printf("\n");
        for(j = 0; j < y; j++)
            printf(" ");

        printf("o");
        printf("\n");

        if((x == top)||(x == bottom))
            velocity_x = -velocity_x;
        if((y == left)||(y == right))
            velocity_y = -velocity_y;
    }
}

#5
#include <stdio.h>
#include <stdlib.h>
#