//
// Created by 韩悠阳 on 2017/11/21.
//

//2.3.2
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cwindow.h>

int high, width;
int bird_x, bird_y;
int bar1_y, bar1_xDown, bar1_xTop;

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
    bird_x = 0;
    bird_y = width / 3;
    bar1_y = width / 2;
    bar1_xDown = high / 3;
    bar1_xTop = high / 2;
}

void show(){
    gotoxy(0, 0);
    int i, j;

    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            if((i == bird_x)&& (j == bird_y))
                printf("@");
            else if((j == bar1_y)&&((i < bar1_xDown)||(i  > bar1_xTop)))
                printf("*");
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

void updateWithInput{
    char input;
    if(kbhit()){
        input = getch();
        if(input == '')
            bird_x = bird_x - 2;
    }
}

int main(){
    startup();
    while(1){
        show();
        updateWithoutInput();
        updateWithInput;
    }
    return 0;
}

//2.3.3
void updateWithoutInput(){
    bird_x++;
    bar1_y;
    sleep(150);
}

//2.3.4
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cwindow.h>

int high, width;
int bird_x, bird_y;
int bar1_y, bar1_xDown, bar1_xTop;
int score;

void gotoxy(int x, int y){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

void startup(){
    high = 20;
    width = 50;
    bird_x = high / 2;
    bird_y = width / 3;
    bar1_y = width / 2;
    bar1_xDown = high / 3;
    bar1_xTop = high / 2;
    score = 0;
}

void show(){
    gotoxy(0, 0);
    int i, j;

    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            if((i == bird_x)&&(j == bird_y))
                printf("@");
            else if((j == bar1_y)&&((i < bar1_xDown)||(i > bar1_xTop)))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("得分：%d", score);
}

void updateWithoutInput(){
    bird_x++;
    bar1_y--;
    if(bird_y == bar1_y){
        if((bird_x >= bar1_xDown)&&(bird_x <= bar1_xTop))
            score++;
        else{
            printf("游戏失败\n");
            system("pause");
            exit(0);
        }
    }
    sleep(150);
}

void updateWithInput(){
    char input;
    if(kbhit()){
        input = getch();
        if(input == ' ')
            bird_x = bird_x -2;
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

//2.3.5
void updateWithoutInput(){
    bird_x++;
    bar1_y--;
    if(bird_y == bar1_y){
        if((bird_x >= bar1_xDown)&&(bird_x <= bar1_xTop))
            score++;
        else{
            printf("游戏失败\n");
            system("pause");
            exit(0);
        }
    }
    if(bar1_y <= 0){
        bar1_y = width;
        int temp = rand() % int(high * 0.8);
        bar1_xDown = temp - high / 10;
        bar1_xTop = temp + high / 10;
    }
    sleep(150);
}

//3.1.1
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define High 25
#define Width 50

int cells[High][Width];

void gotoxy(int x, int y){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

void startup(){
    int i, j;
    for(i = 0; i < High; i++)
        for(j = 0; j < Width; j++){
            cells[i][j] = rand()%2;
        }
}

void show(){
    gotoxy(0, 0);
    int i, j;
    for(i = 0; i <= High; i++){
        for(j = 0; j <= Width; j++){
            if(cells[i][j] == 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    sleep(50);
}

void updateWithoutInput(){

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

//3.1.2
void startup(){
    int i, j;
    for(i = 0; i < High; i++)
        for(j = 0; j < Width; j++){
            cells[i][j] = 1;
        }
}

void updateWithoutInput(){
    int NewCells[High][Width];
    int NeibourNumber;
    int i, j;
    for(i = 1; i <= High - 1; i++){
        for(j = 1; j <= Width - 1; j++){
            NeibourNumber = cells[i - 1][j - 1] + cells[i - 1][j] + cells[i - 1][j + 1]
                    +cells[i][j - 1] + cells[i][j] + cells[i][j+1]
                    +cells[i + 1][i - 1]+ cells[i + 1][i] + cells[i + 1][i + 1];
            if(NeibourNumber == 3)
                NewCells[i][j] = 1;
            else if(NeibourNumber == 2)
                NewCells[i][j] = cells[i][j];
            else
                NewCells[i][j] = 0;
        }
    }
    for(i = 0; i <= High; i++)
        for(j = 0; j <= Width; j++)
            cells[i][j] = NewCells[i][j];
}\

//3.2.1
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cwindow.h>

#define High 15
#define Width 20

int ball_x,ball_y;
int ball_vx, ball_vy;
int canvas[High][width] = {0};

void gotoxy(int x, int y){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

void startup(){
    ball_x = 0;
    ball_y = Width / 2;
    ball_vx = 1;
    ball_vy = 1;
    canvas[ball_x][ball_y] = 1;
}

void show(){
    gotoxy(0, 0);
    int i, j;
    for(i = 0; i < High; i++){
        for(j = 0; j < Width; j++){
            if(canvas[i][j] == 0)
                printf(" ");
            else if(canvas[i][j] == 1)
                printf("o");
        }
        printf("|\n");
    }
    for(j = 0; j < Width; j++)
        printf("-");
}

void updateWithoutInput(){
    canvas[ball_x][ball_y] = 0;

    ball_x = ball_x + ball_vx;
    ball_y = ball_y + ball_vy;

    if((ball_x == 0)||(ball_x == High - 1))
        ball_vx = -ball_vx;
    if((ball_y == 0)||(ball_y == Width - 1))
        ball_vy = -ball_vy;

    canvas[ball_x][ball_y] = 1;

    sleep(50);
}

void updateWithInput(){

}

int main(){
    startup();
    while (1){
        show();
        updateWithoutInput();
        updateWithInput();
    }
    return 0;
}

//3.2.2
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cwindow.h>

#define High 15
#define Width 20

int ball_x, ball_y;
int ball_vx, ball_vy;
int position_x, position_y;
int ridus;
int left, right;
int canvas[High][Width] = {0};

void gotoxy(int x, int y){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE;
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

void startup(){
    ball_x = 0;
    ball_y = Width / 2;
    ball_vx = 1;
    ball_vy = 1;
    canvas[ball_x][ball_y] = 1;

    ridus = 5;
    position_x = High - 1;
    position_y = Width / 2;
    left = position_y - ridus;
    right = position_y + ridus;

    int k;
    for(k = left; k <= right; k++)
        canvas[position_x][k] = 2;
}

void show(){
    gotoxy(0, 0);
    int i, j;
    for(i = 0; i < High; i++){
        for(j = 0; j < Width; j++){
            if(canvas[i][j] == 0)
                printf(" ");
            else if(canvas[i][j] == 1)
                printf("o");
            else if(canvas[i][j] == 2)
                printf("*");
        }
        printf("|\n");
    }
    for(j = 0; j < Width; j++)
        printf("-");
    printf("\n");
}

void updateWithoutInput(){
    if(ball_x == High - 2){
        if((ball_y >= left)&&(ball_y <= right)){
            printf("\a");
        }
        else{
            printf("游戏失败\n");
            system("pause");
            exit(0);
        }
    }
    canvas[ball_x][ball_y] = 0;

    ball_x = ball_x + ball_vx;
    ball_y = ball_y + ball_vy;

    if((ball_x == 0)||(ball_x == High - 2))
        ball_vx = -ball_vx;
    if((ball_y == 0)||(ball_y == Width - 1))
        ball_vy = -ball_vy;

    canvas[ball_x][ball_y] = 1;

    sleep(50);
}

void updateWithInput(){
    char input;
    if(kbhit()){
        input = getch();
        if(input == 'a'&& left > 0){
            canvas[position_x][right] = 0;
            position_y--;
            left = position_y - ridus;
            right = position_y + ridus;
            canvas[position_x][left] = 2;
        }
        if(input == 'd'&& right < Width - 1)){
            canvas[position_x][left] = 0;
            position_y++;
            left = position_y - ridus;
            right = position_y + ridus;
            canvas[position_x][right] = 2;
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

//3.2.3
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cwindow.h>

#define High 15
#define Width 20

int ball_x, ball_y;
int ball_vx, ball_vy;
int position_x, position_y;
int ridus;
int left, right;
int canvas[High][Width] = {0};

void gotoxy(int x, int y){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

void startup(){
    ridus = 5;
    position_x = High - 1;
    position_y = Width / 2;
    left = position_y - ridus;
    right = position_y + ridus;

    ball_x = position_x - 1;
    ball_y = position_y;
    ball_vx = -1;
    ball_vy = 1;
    canvas[ball_x][ball_y] = 1;

    int k, i;
    for(k = left; k <= right; k++)
        canvas[position_x][k] = 2;

    for(k = 0; k < Width; k++)
        for(i = 0; i < High/4; i++)
            canvas[i][k] = 3;
}

void show(){
    gotoxy(0, 0);
    int i, j;
    for(i = 0; i < High; i++){
        for(j = 0; j < Width; j++){
            if(canvas[i][j] == 0)
                printf(" ");
            else if(canvas[i][j] == 1)
                printf("o");
            else if(canvan[i][j] == 2)
                printf("*");
            else if(canvas[i][j] == 3)
                printf("#");
        }
        printf("|\n");
    }
    for(j = 0; j < Width; j++)
        printf("-");
    printf("\n");
}

void updateWithoutInput(){
    if(ball_x == High - 2){
        if((ball_y >= left)&&(ball_y <= right)){

        }
        else {
            printf("游戏失败\n");
            system("pause");
            exit(0);
        }
    }

    static int speed = 0;
    if(speed < 7)
        speed++;
    if(speed = 7){
        speed = 0;

        canvas[ball_x][ball_y] = 0;
        ball_x = ball_x + ball_vx;
        ball_y = ball_y + ball_vy;
        canvas[ball_x][ball_y] = 1;

        if((ball_x == 0)||(ball_x == High - 2))
            ball_vx = -ball_vx;
        if((ball_y == 0)||(ball_y == Width - 1))
            ball_vy = -ball_vy;

        if(canvas[ball_x - 1][ball_y] == 3){
            ball_vx = -ball_vx;
            canvas[ball_x - 1][ball_y] = 0;
            printf("\a");
        }
    }
}

void updateWithInput(){
    char input;
    if(kbhit()){
        input = getch();
        if(input == 'a'&& left > 0){
            canvas[position_x][right] = 0;
            position_y--;
            left = position_y - ridus;
            right = position_y + ridus;
            canvas[position_x][left] = 2;
        }
        if(input == 'd'&& right < Width - 1){
            canvas[position_x][left] = 0;
            position_y++;
            left = position_y - ridus;
            right = position_y + ridus;
            canvas[position_x][right] = 2;
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

