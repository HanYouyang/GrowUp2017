//
// Created by 韩悠阳 on 2017/11/20.
//

//2.2.1
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cwindow.h>

int high, width;
int ball_x, ball_y;
int ball_vx, ball_vy;

void gotoxy(){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

void startup(){
    high = 15;
    width = 20;
    ball_x = 0;
    ball_y = width / 2;
    ball_vx = 1;
    ball_vy = 1;
}

void show(){
    gotoxy(0, 0);
    int i,j;
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            if((i == ball_x)&&(j == ball_y))
                printf("o");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void updateWithoutInput(){
    ball_x = ball_x + ball_vx;
    ball_y = ball_y + ball_vy;

    if((ball_x == 0)||(ball_x == high -1))
        ball_vx = -ball_vx;
    if((ball_y == 0)||(ball_y == width -1))
        ball_vy = -ball_vy;

    sleep(50);
}

void updateWithInput(){

}

int main(){
    startup();
    while(1){
        show();
        updateWithoutInput();
        updateWithInput();
    }
    return 0;

}

//2.2.2
void show(){
    gotoxy(0. 0);
    int i, j;
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            if((i == ball_x)&&(j == ball_y))
                printf("o");
            else if(j == width)
                printf("|");
            else if(i == high)
                printf("-");
            else
                printf(" ");
        }
        printf("\n");
    }
}

//2.2.3
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <cwindow.h>

int high, width;
int ball_x, ball_y;
int ball_vx, ball_vy;
int position_x, position_y;
int ridus;
int left, right;

void gotoxy(int x, int y){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = Y;
    SetConsoleCursorPosition(handle, pos);
}

void startup(){
    high = 15;
    width = 20;
    ball_x = 0;
    ball_y = width / 2;
    ball_vx = 1;
    ball_vy = 1;
    ridus = 5;
    position_x = high;
    position_y = width / 2;
    left = position_y - ridus;
    right = position_y + ridus;
}

void show(){
    gotoxy(0, 0);
    int i, j;
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            if((i == ball_x)&&(j == ball_y))
                printf("o");
            else if((i == high + 1))
                printf("-");
            else if((j == width))
                printf("|");
            else if((i== high)&&(j >= left)&&(j <= right))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void updateWithoutInput(){
    ball_x = ball_x + ball_vx;
    ball_y = ball_y + ball_vy;
    if((ball_x == 0)||(ball_x == high - 1))
        ball_vx = - ball_vx;
    if((ball_y == 0)||(ball_y == width - 1))
        ball_vy = - ball_vy;
    sleep(50);
}

void updateWithInput(){
    char input;
    if(kbhit()){
        input = getch();
        if(input == 'a'){
            position_y--;
            left = position_y - ridus;
            right = position_y + ridus;
        }
        if(input == 'd'){
            position_y++;
            left = position_y - ridus;
            right = position_y + ridus;
        }
    }
}

int main(){
    startup();
    while(1){
        show();
        updateWithoutInput();
        updateWithInput();
    }
    return 0;
}

//2.2.4
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cwindow.h>

int high, width;
int ball_x, ball_y;
int ball_vx, ball_vy;
int position_x, position_y;
int ridus;
int left, right;
int ball_number;

void gotoxy(int x, int y){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

void startup(){
    high = 15;
    width = 30;
    ball_x = 0;
    ball_y = width / 2;
    ball_vx = 1;
    ball_vy = 1;
    ridus = 5;
    position_x = high;
    position_y = width;
    left = position_y - ridus;
    right = position_y + ridus;
    ball_number = 0;
}

void show(){
    gotoxy(0, 0);
    int i, j;
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            if((i == ball_x)&&(j == ball_y))
                printf("o");
            else if((j == width))
                printf("|");
            else if((i == high + 1))
                printf("-");
            else if((i == high)&&(j >= left)&&(j <= right))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("反弹小球数：%d\n", ball_number);
}

void updateWithoutInput(){
    if(ball_x == high - 1){
        if((ball_y >= left)&&(ball_y <= right)){
            ball_number++;
            printf("\a");
        }
        else{
            printf("游戏失败\n");
            system("pause");
            exit(0);
        }
    }
    ball_x = ball_x + ball_vx;
    ball_y = ball_y + ball_vy;
    if((ball_x == 0)||(ball_x == high - 1))
        ball_vx = -ball_vx;
    if((ball_y == 0)||(ball_y == width - 1))
        ball_vy = -ball_vy;
    sleep(50);
}

void updateWithInput(){
    char input;
    if(kbhit()){
        input = getch();
        if(input == 'a'){
            position_y--;
            left = position_y - ridus;
            right = position_y + ridus;
        }
        if(input == 'd'){
            position_y++;
            left = position_y - ridus;
            right = position_y + ridus;
        }
    }
}

int main(){
    startup();
    while(1){
        show();
        updateWithoutInput();
        updateWithInput();
    }
    return 0;
}
//2.2.5
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cwindow.h>

int high,width;
int ball_x, ball_y;
int ball_vx, ball_vy;
int position_x, position_y;
int ridus;
int left, right;
int ball_number;
int block_x, bolck_y;
int score;

void gotoxy(int x, int y){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

void startup(){
    high = 13;
    width = 17;
    ball_x = 0;
    ball_y = width / 2;
    ball_vx = 1;
    ball_vy = 1;
    ridus = 6;
    position_x = high;
    position_y = width / 2;
    left = position_y - ridus;
    right = position_y + ridus;
    ball_number = 0;
    block_x = 0;
    block_y = width / 2 + 1;
    score;
}

void show(){
    gotoxy(0, 0);
    int i, j;
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            if((i == ball_x)&&(j == ball_y))
                printf("o");
            else if(j == width)
                printf("|");
            else if(i == high + 1)
                printf("-");
            else if((i == high)&&(j > left)&&(j < right))
                printf("*");
            else if((i == block_x)&&(j ==block_y))
                printf("B");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("反弹小球数：%d\n", ball_number);
    printf("消掉的砖块数：%d\n", score);
}

void updateWithoutInput(){
    if(ball_x == high - 1){
        if((ball_y >= left)&&(ball_y <= right)){
            ball_number++;
            printf("\a");
            //ball_y = ball_y + rand()%4 -2;
        }
        else{
            printf("游戏失败\n");
            system("pause");
            exit(0);
        }
    }
    if((ball_x == block_x)&&(ball_y == block_y)){
        score++;
        block_y = rand() % width;
    }

    ball_x = ball_x + ball_vx;
    ball_y = ball_y + ball_vy;
    if((ball_x == 0)||(ball_x == high - 1))
        ball_vx = -ball_vx;
    if((ball_y == 0)||(ball_y == width - 1))
        ball_vy = -ball_vy;
    sleep(80);
}

void updateWithInput(){
    char input;
    if(kbhit()){
        input = getch();
        if(input == 'a'){
            position_y--;
            left = position_y - ridus;
            right = position_y + ridus;
        }
        if(input == 'd'){
            position_y++;
            left = position_y - ridus;
            right = position_y + ridus;
        }
    }
}

int main(){
    startup();
    while(1){
        show();
        updateWithoutInput();
        updateWithInput();
    }
    return 0;
}

//2.3.1
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cwindow.h>

int high, width;
int bird_x, bird_y;
int bar1_y, bar1_xDown, bar1_xTop;

void gotoxy(int x, int y){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD POS;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

void startup(){
    high = 15;
    width = 20;
    bird_x = 0;
    bird_y = width / 3;
}

void show(){
    gotoxy(0, 0);
    int i, j;
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            if((i == bird_x)&&(j == bird_y))
                printf(("@");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void updateWithoutInput(){
    bird_x++;
    sleep(150);
}

void updateWithInput(){
    char input;
    if(kbhit()){
        input = getch();
        if(input == ' ')
            bird_x = bird_x - 2;
    }
}

int main(){
    startup();
    while(1){
        show();
        updateWithoutInput();
        updateWithInput();
    }
    return 0;
}
