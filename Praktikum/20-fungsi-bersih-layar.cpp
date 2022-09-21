#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void bersihLayar(){
    for(int a=0; a<80; a++){
        for(int b=1; b<=24; b++){
            cout << " ";
        }
    }
}

void delay(){
    int delay=1;
    while(delay<200000000){
        delay++;
    }
}

int main(){
    bersihLayar();
    for(int a=1; a<=20; a++){
        gotoxy(a, 10); cout << " ARIF SAPUTRA";
        delay();
    }
    getch();
    return 0;
}