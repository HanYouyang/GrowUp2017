//
// Created by 韩悠阳 on 2017/11/19.
//

//模块化
int main(){
    startup();
    while(1){
        show();
        updateWithoutInput();
        updateWithInput();
    }
    return 0;
}

//2.1.1
#include <stdio.h>
#include <stlib.h>
#include <conio.h>

int position_x, position_y;
int high, width;

void startup(){
    high = 20;
    width = 30;
    position_x = high/2;
    position_y = width/2;

}

void show(){
    system("cls");
    int i,j;
    for(i = 0; i < high; i++){
        for(j = 0; j < y; j++){
            if((i == position_x)&&(j == position_y))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void updateWithoutInput(){

}

void updateWithIput(){
    char input;
    if(kbhit()){
        input = getch();
        if(input == 'a')
            position_y--;
        if(input == 'd')
            position_y++;
        if(input == 'w')
            position_x--;
        if(input == x++)
            position_x++;

    }
}

int main(){
    startup();
    while(1){
        show();
        updateWithoutInput();
        updateWithIput();
    }
    return 0;
}

//2.1.2
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int position_x, position_y;
int bullet_x, bullet_y;
int high, widrh;

void startup(){
    high = 20;
    width = 30;
    position_x = high/2;
    position_y = width/2;
    bullet_x = 0;
    bullet_y = position_y;
}

void show(){
    system("cls");
    int i, j;
    for(i = 0; i < high; i++){
        for(j = 0; j < width; j++){
            if((i == position_x)&&(j == position_y))
                printf("*");
            else if ((i == bullet_x) && (j == bullet_y))
                printf("|");
            else
                printf("");
        }
        printf("\n");
    }
}

void updateWithoutInput(){
    if(bullet_x > -1)
        bullet_x--;
}

void updateWithInput(){
    char input;
    if(kbhit()){
        input == getch();
        if(input == 'a')
            position_y--;
        if(input == 'd')
            position_y++;
        if(input == 'w')
            position_x--;
        if(input == 's')
            position_x++;
        if(input == ' '){
            bullet_x = position_x - 1;
            bullet_y = position_y;
        }
    }
}
int main(){
    startup();
    while(1){
        show();
        updateWithoutInput();
        updateWithIput();
    }
    return 0;
}

//2.1.3
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int position_x, position_y;
int bullet_x, bullet_y;
int enemy_x, enemy_y;
int high, width;

void show(){
    system("cls");
    int i,j;
    for(i = 0; i < high; i++){
        for(j = 0; j < width; j++){
            if((i == position_x)&&(j == position_y))
                printf("*");
            else if((i == enemy_x)&&(j == enemy_y))
                printf("@");
            else if((i == bullet_x)&&(j == bullet_y))
                printf("|");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void updateWithoutInput(){
    if(bullet_x > -1)
        bullet_x--;
}

void updateWithInput(){
    char input;
    if(kbhit()){
        input = getch();
        if(input == 'a')
            position_y--;
        if(input == 'd')
            position_y++;
        if(input == 'w')
            position_x--;
        if(input == 's')
            position_x++;
        if(input == ' '){
            bullet_x = position_x - 1;
            bullet_y = position_y;
        }
    }
}

int main(){
    startup();
    while(1){
        show();
        updateWithoutInput();
        updateWithIput();
    }
    return 0;
}

//2.1.4
void updateWithoutInput(){
    if(bullet_x > -1)
        bullet_x--;
    static int speed = 0;
    if(speed < 10)
        speed++;
    if(speed == 10){
        enemy_x++;
        speed = 0;
    }
}

//2.1.5
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int position_x, position_y;
int bullet_x, bullet_y;
int enemy_x, enemy_y;
int high, width;
int score;

void startup(){
    high = 20;
    width = 30;
    position_x = high / 2;
    position_y = width / 2;
    bullet_x = -2;
    bullet_y = position_y;
    enemy_x = 0;
    enemy_y = position_y;
    score = 0;
}

void show(){
    system("cls");
    int i, j;
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            if((i == position_x)&&(j == position_y))
                printf("*");
            else if((i == enemy_x)&&(j == enemy_y))
                printf("@");
            else if((i == bullet_x)&&(j == bullet_y))
                printf("|");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("得分：%d\n", score);
}

void updateWithoutInput(){
    if(bullet_x > -1)
        bullet_x--;
    if((bullet_x == enemy_x) && (bullet_y == enemy_y)){
        score++;
        enemy_x = -1;
        enemy = rand()%width;
        bullet_x = -2;
    }
    if(enemy_x > high){
        enemy_x = -1;
        enemy_y = rand()%width;
    }
    static int speed = 0;
    if(speed < 10)
        speed++;
    if(speed == 10){
        enemy_x++;
        speed = 0;
    }
}

void updateWithInput(){
    char input;
    if(kbhit()){
        input = getch();
        if(input == 'a')
            position_y--;
        if(input == 'd')
            position_y++;
        if(input == 'w')
            position_x--;
        if(input == 's')
            position_x++;
        if(input == ' '){
            bullet_x = position_x - 1;
            bullet_y = position_y;
        }
    }
}

int main(){
    startup();
    while(1){
        show();
        updateWithoutInput();
        updateWithIput();
    }
    return 0;
}

//2.1.6
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y){
    HANDLE handel = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPostion(handel, pos);
}

void show(){
    gotoxy(0, 0);
    int i, j;
    for(i = 0; i < high; i++){
        for(j = 0; j < width; j++){
            if((i == position_x)&&(j == position_y))
                printf("*");
            else if((i == enemy_x)&&(j == enemy_y))
                printf("@");
            else if((i == bullet_x)&&(j == bullet_y))
                printf("|");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("得分：%d\n", score);
}

// 光标闪烁
#include <stdio.h>
#include <windows.h>

void HideCursor(){
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

int main(){
    HideCursor();
    return 0;
}

