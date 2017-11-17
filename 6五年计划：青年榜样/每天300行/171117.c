//1.2最简单的飞机游戏

//1.2.1控制飞机移动

#include <stdio.h>
#include <stdlib.h>
int main(){
    int i,j;
    int x = 5;
    int y = 10;
    char input;

    while(1){
        system("cls");
        for(i = 0; i < x; i++)
            printf("\n");
        for(j = 0; j < y; j++)
            printf(" ");
        printf("*");
        printf("\n");

        scanf("%c", &input);
        if(input == 'a')
            y--;
        if(input == 'd')
            y++;
        if(input == 'w')
            x--;
        if(input == 's')
            x++;
    }
    return 0;
}

//1.2.2getch控制飞机移动
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(){
    int i,j;
    int x = 5;
    int y = 10;
    char input;
    while(1){
        system("cls");


    }




}
