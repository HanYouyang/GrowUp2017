//3.4.1
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define High 20
#define Width 30

int canvas[High][Width] = {0};

void gotoxy(int x, int y){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

void startup(){
    int i, j;

    for(i = 0; i < High; i++){
        canvas[i][0] = -1;
        canvas[i][Width - 1] = -1;
    }
    for(j = 0; j < Width; j++){
        canvas[0][j] = -1
        canvas[High - 1][j] = -1;
    }

    canvas[High/2][Width/2] = 1;

    for(i = 1; i <= 4; i++){
        canvas[High/2][Width/2 - i] = i + 1;
    }
}

void show(){
    gotoxy(0, 0);
    int i, j;
    for(i = 0; i < High; i++){
        for(j = 0; j < Width; j++){
            if(canvas[i][j] == 0)
                printf(" ");
            else if(canvas[i][j] == -1)
                printf("#");
            else if(canvas[i][j] == 1)
                printf("@");
            else if(canvas[i][j] > 1)
                printf("*");
        }
        printf("\n");
    }
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

