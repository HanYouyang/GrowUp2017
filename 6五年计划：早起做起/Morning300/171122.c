//
// Created by 韩悠阳 on 2017/11/22.
//

//3.3.1
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define High 25
#define Width 50

int position_x, position_y;
int canvas[High][Width] = {0};

void gotoxy(int x, int y){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

void startup(){
    position_x = High / 2;
    position_y = Width / 2;
    canvas[position_x][position_y] = 1;
}

void show(){
    gotoxy(0, 0);
    int i, j;
    for(i = 0; i < High; i++){
        for(j = 0; j < Width; j++){
            if(canvas[i][j] == 0)
                printf(" ");
            else if(canvas[i][j] == 1)
                printf("*");
        }
        printf("\n");
    }
}

void updateWitoutInput(){
}

void updateWithInput(){
    char input;
    if(kbhit()){
        input = getch();
        if(input == 'a'){
            canvas[position_x][position_y] = 0;
            position_y--;
            canvas[position_x][position_y] = 1;
        }
        else if(input == 'd'){
            canvas[position_x][position_y] = 0;
            position_y++;
            canvas[position_x][position_y] = 1;
        }
        else if(input == 'w'){
            canvas[position_x][position_y] = 0;
            position_x--;
            canvas[position_x][position_y] = 1;
        }
        else if(input == 's'){
            canvas[position_x][position_y] = 0;
            position_x++;
            canvas[position_x][position_y] = 1;
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

//3.3.2
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define High 25
#define Width 50

int position_x, position_y;
int canvas[High][Width] = {0};

void gotoxy(int x, int y){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

void startup(){
    position_x = High / 2;
    position_y = Width / 2;
    canvas[position_x][position_y] = 1;
}

void show(){
    gotoxy(0, 0);
    int i, j;
    for(i = 0; i < High; i++){
        for(j = 0; j < Width; j++){
            if(canvas[i][j] == 0)
                printf(" ");
            else if(canvas[i][j] == 1)
                printf("*");
            else if(canvas[i][j] == 2)
                printf("|");
        }
        printf("\n");
    }
}

void updateWithoutInput(){
    int i, j;
    for(i = 0; i < High; i++){
        for(j = 0; j <Width; j++){
            if(canvas[i][j] == 2){
                canvas[i][j] = 0;
                if(i > 0)
                    canvas[i - 1][j] = 2;
            }
        }
    }
}

void updateWithInput(){
    char input;
    if(kbhit()){
        input = getch();
        if(input == 'a'){
            canvas[position_x][position_y] = 0;
            position_y--;
            canvas[position_x][position_y] = 1;
        }
        else if(input == 'd'){
            canvas[position_x][position_y] = 0;
            position_y++;
            canvas[position_x][position_y] = 1;
        }
        else if(input == 'w'){
            canvas[position_x][position_y] = 0;
            position_x--;
            canvas[position_x][position_y] = 1;
        }
        else if (input == 's')
        {
            canvas[position_x][position_y] = 0;
            position_x++;
            canvas[position_x][position_y] = 1;
        }
        else if (input == ' ')
        {
            canvas[position_x - 1][position_y] = 2;
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

//3.3.3
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define High 15
#define Width 25

int position_x, position_y;
int enemy_x, enemy_y;
int canvas[High][Width] = {0};
int score;

void gotoxy(int x, int y){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = Y;
    SetConsoleCursorPosition(handle, pos);
}

void startup(){
    position_x = High - 1;
    position_y = Width / 2;
    canvas[position_x][position_y] = 1;
    enemy_x = 0;
    enemy_y = position_y;
    canvas[enemy_x][enemy_y] = 3;
    score = 0;
}

void show(){
    gotoxy(0, 0);
    int i, j;
    for(i = 0; i < High; i++){
        for(j = 0; j < Width; j++){
            if(canvas[i][j] == 0)
                printf(" ");
            else if(canvas[i][j] == 1)
                printf("*");
            else if(canvas[i][j] == 2)
                printf("|");
            else if(canvas[i][j] == 3)
                printf("@");
        }
        printf("\n");
    }
    printf("得分：%3d\n", score);
    sleep(20);
}

void updateWithoutInput(){
    int i, j;
    for(i = 0; i < High; i++){
        for(j = 0; j < Width; j++){
            if(canvas[i][j] == 2){
                if((i == enemy_x)&&(i == enemy_y)){
                    score++;
                    canvas[enemy_x][enemy_y] = 0;
                    enemy_x = 0;
                    enemy_y = rand() % Width;
                    canvas[enemy_x][enemy_y] = 3;
                    canvas[i][j] = 0;
                }
                canvas[i][j] = 0;
                if(i > 0)
                    canvas[i - 1][j] = 2;
            }
        }
    }
    if((position_x == enemy_x)&&(position_y == enemy_y)){
        printf("失败！\n");
        sleep(3000);
        system("pause");
        exit(0);
    }
    if(enemy_x > High){
        canvas[enemy_x][enemy_y] = 0;
        enemy_x = 0;
        enemy_y = rand() % Width;
        canvas[enemy_x][enemy_y] = 3;
        score--;
    }

    static int speed = 0;
    if(speed < 10){
        speed++;
    }
    if(speed == 10){
        canvas[enemy_x][enemy_y] = 0;
        enemy_x++;
        speed = 0;
        canvas[enemy_x][enemy_y] = 3;
    }
}

void updateWithInput(){
    char input;
    if(kbhit()){
        input = getch();
        if(input == 'a'){
            canvas[position_x][position_y] = 0;
            position_y--;
            canvas[position_x][position_y] = 1;
        }
        else if(input == 'd'){
            canvas[position_x][position_y] = 0;
            position_y++;
            canvas[position_x][position_y] = 1;
        }
        else if(input == 'w'){
            canvas[position_x][position_y] = 0;
            position_x--;
            canvas[position_x][position_y] = 1;
        }
        else if(input == 's'){
            canvas[position_x][position_y] = 0;
            position_x++;
            canvas[position_x][position_y] = 1;
        else if(input == ' '){
            canvas[position_x - 1][position_y] = 2;
        }
        }
    }
}

int main(){
    startup();
    while(1){
        show();
        updateWithoutInput();
        updateWithInput();    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define High 25
#define Width 50
#define EnemyNum 5

int position_x, position_y;
int enemy_x[EnemyNum], enemy_y[EnemyNum];
int canvas[High][Width] = {0};
int score;

void gotoxy(){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

void startup(){
    position_x = High - 1;
    position_y = Width / 2;
    canvas[position_x][position_y] = 1;
    int k;
    for(k = 0; k < EnemyNum; k++){
        enemy_x[k] = rand()%2;
        enemy_y[k] = rand()%Width;
        canvas[enemy_x[k]][enemy_y[k]] = 3;
    }
    score = 0;
}

void show(){
    gotoxy(0, 0);
    int i, j;
    for(i = 0; i < High; i++){
        for(j = 0; j < Width; j++){
            if(canvas[i][j] == 0)
                printf(" ");
            else if(canvas[i][j] == 1)
                printf("*");
            else if(canvas[i][j] == 2)
                printf("|");
            else if(canvas[i][j] == 3)
                printf("@");
        }
        printf("\n");
    }
    printf("得分：%3d\n", score);
    sleep(20);
}

void updateWithoutInput(){
    int i, j, k;
    for(i = 0; i < High; i++){
        for(j = 0; j < Width; j++){
            if(canvas[i][j] == 2){
                for(k = 0; k < EnemyNum; k++){
                    if((i == enemy_x[k])&&(j == enemy_y)){
                        score++;
                        canvas[enemy_x[k]][enemy_y[k]] = 0;
                        enemy_x[k] = rand()%2;
                        enemy_y[k] = rand()%Width;
                        canvas[enemy_x[k]][enemy_y[k]] = 3;
                        canvas[i][j] = 0;
                    }
                }
                canvas[i][j] = 0;
                if(i > 0)
                    canvas[i - 1][j] = 2;
            }
        }
    }

    static int speed = 0;
    if(speed < 20)
        speed++;
    for(k = 0; k < EnemyNum; k++){
        if((position_x == enemy_x[k])&&(position_y == enemy_y[k])){
            printf("失败！\n");
            sleep(3000);
            system("pause");
            exit(0);
        }
        if(enemy_x[k] > High){
            canvas[enemy_x[k]][enemy_y[k]] = 0;
            enemy_x[k] = rand() % 2;
            enemy_y[k] = rand() % Width;
            canvas[enemy_x[k]][enemy_y[k]] = 3;
            score--;
        }
        if(speed == 20){
            for(k = 0; k < EnemyNum; k++){
                canvas[enemy_x[k]][enemy_y[k]] = 0;
                enemy_x[k]++;
                speed = 0;
                canvas[enemy_x[k]][enemy_y[k]] = 3;
            }
        }
    }
}

void updateWithInput(){
    char input;
    if(kbhit()){
        input = getch();
        if(input == 'a'){
            canvas[position_x][position_y] = 0;
            position_y--;
            canvas[position_x][position_y] = 1;
        }
        else if(input == 'd'){
            canvas[position_x][position_y] = 0;
            position_y++;
            canvas[position_x][position_y] = 3;
        }
        else if(input == 'w'){
            canvas[position_x][position_y] = 0;
            position_x--;
            canvas[position_x][position_y] = 3;
        }
        else if(input == 's'){
            canvas[position_x][position_y] = 0;
            position_x++;
            canvas[position_x][position_y] = 3;
        }
        else if(input == ' '){
            canvas[position_x - 1][position_y] = 2;
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