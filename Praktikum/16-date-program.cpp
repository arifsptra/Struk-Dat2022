#include <iostream>

using namespace std;

typedef struct date{
    int tgl, bln, thn;
};

date now;

displayDate(date x){
    if(x.bln == 1) cout << x.tgl << " January " << x.thn;
    else if(x.bln == 2) cout << x.tgl << " February " << x.thn;
    else if(x.bln == 3) cout << x.tgl << " March " << x.thn;
    else if(x.bln == 4) cout << x.tgl << " April " << x.thn;
    else if(x.bln == 5) cout << x.tgl << " May " << x.thn;
    else if(x.bln == 6) cout << x.tgl << " June " << x.thn;
    else if(x.bln == 7) cout << x.tgl << " July " << x.thn;
    else if(x.bln == 8) cout << x.tgl << " August " << x.thn;
    else if(x.bln == 9) cout << x.tgl << " September " << x.thn;
    else if(x.bln == 10) cout << x.tgl << " October " << x.thn;
    else if(x.bln == 11) cout << x.tgl << " November " << x.thn;
    else if(x.bln == 12) cout << x.tgl << " December " << x.thn;
    cout << endl;
}

int endDateTomorrow(date x){
    if(x.bln==1 || x.bln==3 || x.bln==5 || x.bln==7 || x.bln==8 || x.bln==10 || x.bln==12){
        return 31;
    }else if(x.bln==2 && (x.thn%=4)==0){
        return 29;
    }else if(x.bln==2 && (x.thn%=4)!=0){
        return 28;
    }else {
        return 30;
    }
}

int endDateYesterday(date x){
    x.bln--;
    if(x.bln==1 || x.bln==3 || x.bln==5 || x.bln==7 || x.bln==8 || x.bln==10 || x.bln==12){
        return 31;
    }else if(x.bln==2 && (x.thn%=4)==0){
        return 29;
    }else if(x.bln==2 && (x.thn%=4)!=0){
        return 28;
    }else {
        return 30;
    }
}

tomorrow(date x){
    int endDate = endDateTomorrow(x);
    if(x.tgl==31 && x.bln==12){
        x.tgl = 1;
        x.bln = 1;
        x.thn++;
    }else if(x.tgl!=endDate){
        x.tgl++;
    }else{
        x.tgl=1;
        x.bln++;
    }
    displayDate(x);
}

yesterday(date x){
    int endDate = endDateYesterday(x);
    if(x.tgl==1 && x.bln==1){
        x.tgl = 31;
        x.bln = 12;
        x.thn--;
    }else if(x.tgl==1){
        x.tgl = endDate;
        x.bln--;
    }else {
        x.tgl--;
    }
    displayDate(x);
}

int main(){
    now.tgl = 20;
    now.bln = 1;
    now.thn = 2023;

    cout << "Today's Date       : "; displayDate(now);
    cout << "Tomorrow's Date    : "; tomorrow(now);
    cout << "Yesterday's Date   : "; yesterday(now);

    return 0;
}