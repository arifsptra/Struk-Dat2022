#include <iostream>

using namespace std;

typedef struct antrian{
    char name[30];
    char sex;
    int age;
};

antrian pasien[100];
int n=1, mx=5;

inQueue(int x){
    cout << "Input your name    : ";
    cin >> pasien[x].name;
    cout << "Input your sex     : ";
    cin >> pasien[x].sex;
    cout << "Input your age     : ";
    cin >> pasien[x].age; 
    n++;
}

maju(int x){
    for(int i=x; i<=n; i++){
        pasien[i] = pasien[i+1];
    }
}

deQueue(int x){
    cout << "Get Well Son: " << pasien[x].name << endl;
    maju(x);
    n--;
}

showQueue(){
    for(int i=1; i<n; i++){
        cout << i << " " << pasien[i].name << " " << pasien[i].sex << " " << pasien[i].age << endl;
    }
}

specialQueue(int x){
    for(int i=n; i>x; i--){
        pasien[i] = pasien[i-1];
    }
    inQueue(x);
}

int main(){
    int choose;
    do{
        cout << "QUEUE IMPLEMENTATION" << endl;
        cout << "1. INQUEUE" << endl;
        cout << "2. DEQUEUE" << endl;
        cout << "3. SHOWQUEUE" << endl;
        cout << "4. SPECIALQUEUE" << endl;
        cout << "9. EXIT" << endl;
        cout << "Your choosen [1-9]: ";
        cin >> choose;
        if(choose==1){
            if(n>mx){
                cout << "Queue is Full!";
            }else {
                inQueue(n);
            }
        }else if(choose==2){
            int x;
            cout << "Patient Number: ";
            cin >> x;
            deQueue(x);
        }else if(choose==3){
            if(n==1){
                cout << "Queue is Empty!";
            }else{
                showQueue();
            }
        }else if(choose==4){
            int x;
            cout << "Boking Number: ";
            cin >> x;
            specialQueue(x);
        }
        cout << endl << endl;
    }while(choose!=9);
    return 0;
}