#include<iostream>
using namespace std;

struct date
{
	int tgl, bln, thn;
};

tanggalnya(struct date x)
{
	if(x.bln==1) cout<<x.tgl<<" Januari "<<x.thn;	
	if(x.bln==2) cout<<x.tgl<<" Februari "<<x.thn;	
	if(x.bln==3) cout<<x.tgl<<" Maret "<<x.thn;	
	if(x.bln==4) cout<<x.tgl<<" April "<<x.thn;	
	if(x.bln==5) cout<<x.tgl<<" Mei "<<x.thn;	
	if(x.bln==6) cout<<x.tgl<<" Juni "<<x.thn;	
	if(x.bln==7) cout<<x.tgl<<" Juli "<<x.thn;	
	if(x.bln==8) cout<<x.tgl<<" Agustus "<<x.thn;	
	if(x.bln==9) cout<<x.tgl<<" September "<<x.thn;	
	if(x.bln==10) cout<<x.tgl<<" Oktober "<<x.thn;	
	if(x.bln==11) cout<<x.tgl<<" Nopember "<<x.thn;	
	if(x.bln==12) cout<<x.tgl<<" Desember "<<x.thn;	
	cout<<endl;
}

int akhirtgl(struct date y)
{
	if(y.bln==1 || y.bln==3 || y.bln==5 || y.bln==7 || y.bln==8 || y.bln==10 || y.bln==12)
		return 31;
	else
		if(y.bln==2 && (y.thn%4)==0)
			return 29;
		else
			if(y.bln==2 && (y.thn%4)!=0)
				return 28;
			else
				return 30;
}

besok(struct date x)
{
	int tglakhir=akhirtgl(x);
	if(x.tgl==31 && x.bln==12)
	{
		x.tgl=1;
		x.bln=1;
		x.thn++;
	}	
	else
		if(x.tgl!=tglakhir)
			x.tgl++;
		else
		{
			x.tgl=1;
			x.bln++;
		}
		
		
	tanggalnya(x);
	
}

struct date now;
int main()
{
	now.tgl=31;
	now.bln=12;
	now.thn=2022;
	cout<<"Tanggal Sekarang   :"; tanggalnya(now);
	cout<<"Tanggal Besok      :"; besok(now);
	
	return 0;
}
