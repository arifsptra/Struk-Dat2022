#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>

using namespace std;

struct pesan {
    char huruf;
};

struct pesan rahasia[100];
int top = 1;
int max = 100;

void push_inqueue(char x) {
    rahasia[top].huruf = x;
    top++;
}

void tampildata() {
    for(int x = 1; x < top; x++) {
        cout << rahasia[x].huruf << " ";
    }
    cout << endl;
}

void pop() {
    top--;
}

void dequeue() {
    for(int x = 2; x <= top; x++) {
        rahasia[x + 1] = rahasia[x];
        top--;
    }
}

int main()
{                   /* 0123456789012345678901234 */
    char kata[100] = {"1I1H21L1O1R21V1E1Y1L21O1U"};
    int idHuruf = 0;
    do {
        if(kata[idHuruf] == '1') {
            cout << kata[idHuruf] << " - Lakukan Push/Inqueue : ";
            idHuruf++;
            cout << kata[idHuruf] << endl;
            push_inqueue(kata[idHuruf]);
            getch();
        } else if(kata[idHuruf] == '2') {
            cout << kata[idHuruf] << " - Lakukan Pop : ";
            pop();
            getch();
        } else if(kata[idHuruf] == '3') {
            cout << kata[idHuruf] << " - Lakukan DEQUEUE  : ";
            dequeue();
            getch();
        }
        // tampildata();
        idHuruf++;
        tampildata();
    } while(idHuruf < strlen(kata));
    // tampildata();
    return 0;
}
