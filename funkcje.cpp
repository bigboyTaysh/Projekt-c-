#include "funkcje.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <math.h>
#include <iomanip>
#include <conio.h>

using namespace std;

void kolor(int i)
{
    HANDLE kolor;
    kolor=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(kolor, i);

}

void zapisilosowanie(wsp& a, wsp& b, wsp& c)
{
    system ("cls");
    cout<<"Trwa losowanie wspolrzednych i zapisywanie do pliku..."<<endl;
    Sleep(250);

    srand(GetTickCount());
    a.x=(-1+200000*rand()/(RAND_MAX))/100.0;
    a.y=(-1+200000*rand()/(RAND_MAX))/100.0;
    b.x=(-1+200000*rand()/(RAND_MAX))/100.0;
    b.y=(-1+200000*rand()/(RAND_MAX))/100.0;
    c.x=(-1+200000*rand()/(RAND_MAX))/100.0;
    c.y=(-1+200000*rand()/(RAND_MAX))/100.0;

    ofstream zapis;
    zapis.open("dane.txt");

    zapis<<a.x<<endl<<a.y<<endl<<b.x<<endl<<b.y<<endl<<c.x<<endl<<c.y<<endl;
    zapis.close();

    cout<<"Gotowe!"<<endl<<endl;
}

void odczytlos(wsp& a, wsp& b, wsp& c)
{
    int pom,nr=1;
    string linia;

    fstream odczyt;

    odczyt.open("dane.txt", ios::in);

    if(odczyt.good()==false){
        cout<<"Plik nie istnieje lub nie znajduje sie w katalogu z projektem!"<<endl<<endl;
        exit(0);
    }

    cout<<"Wczytane dane:"<<endl<<endl;

    while(getline(odczyt,linia)){
        switch(nr){
            case 1: a.x= atof(linia.c_str());
            case 2: a.y= atof(linia.c_str());
            case 3: b.x= atof(linia.c_str());
            case 4: b.y= atof(linia.c_str());
            case 5: c.x= atof(linia.c_str());
            case 6: c.y= atof(linia.c_str());
        }
        nr++;
    }
    odczyt.close();

    cout<<"Punkt A(x,y): ("<<a.x<<", "<<a.y<<")."<<endl;
    cout<<"Punkt B(x,y): ("<<b.x<<", "<<b.y<<")."<<endl;
    cout<<"Punkt C(x,y): ("<<c.x<<", "<<c.y<<")."<<endl;
}

void odczytplik(wsp& a, wsp& b, wsp& c,string& n)
{
    system ("cls");
    string linia,pom2;
    int nr=1,pom=0,nrLinii=0;

    fstream odczyt;

    kolor(7);
    cout<<"Aby program mogl pomyslnie wczytac dane z pliku tekstowego plik\npowinien znajdowac sie w katalogu z programem. Format podanych\ndanych w pliku dla jednego trojkata powinien byc nastepujacy:\n\nax\nay\nbx\nby\ncx\ncy\n\nDla wiecej trojkatow niz jeden podobnie.\n\n";
    kolor(15);

    do{
        cout<<"Podaj nazwe pliku";
        kolor(7);
        cout<<"(*.txt)";
        kolor(15);
        cout<<": ";

        cin>>n;
        pom2=n;
        n=n+".txt";

        odczyt.open(n.c_str(), ios::in);

        if(odczyt.good()==false){
            cout<<"Plik nie istnieje lub nie znajduje sie w katalogu z projektem!"<<endl<<endl;
            pom=1;
        }
        else{
            pom=0;
        }

        if(pom==0){
            break;
        }

    }while(pom==1);

    n=pom2;

    system ("cls");

    cout<<"Ktory trojkat wczytac? Podaj numer: ";
    cin>>nrLinii;

    cout<<"Wczytane dane z pliku "<<n<<":"<<endl<<endl;

    for( int i = 0; i<(nrLinii-1)*6 ; i++ ){
        getline(odczyt,linia);
    }

    while(getline(odczyt,linia)){
        switch(nr){
            case 1: a.x= atof(linia.c_str());
            case 2: a.y= atof(linia.c_str());
            case 3: b.x= atof(linia.c_str());
            case 4: b.y= atof(linia.c_str());
            case 5: c.x= atof(linia.c_str());
            case 6: c.y= atof(linia.c_str());
        }
        nr++;
    }
    odczyt.close();

    cout<<"Punkt A(x,y): ("<<a.x<<", "<<a.y<<")."<<endl;
    cout<<"Punkt B(x,y): ("<<b.x<<", "<<b.y<<")."<<endl;
    cout<<"Punkt C(x,y): ("<<c.x<<", "<<c.y<<")."<<endl;

}

void odczytplik2(wsp& a, wsp& b, wsp& c,string& n)
{
    system ("cls");
    string linia,pom2;
    int nr=1,pom=0, nrLinii=0;

    fstream odczyt;

    do{
        pom2=n;
        n=n+".txt";

        odczyt.open(n.c_str(), ios::in);

        if(odczyt.good()==false){
            cout<<"Plik nie istnieje lub nie znajduje sie w katalogu z projektem!"<<endl<<endl;
            pom=1;
        }
        else{
            pom=0;
        }

        if(pom==0){
            break;
        }

    }while(pom==1);

    n=pom2;

    cout<<"Ktory trojkat wczytac? Podaj numer: ";
    cin>>nrLinii;

    cout<<"Wczytane dane z pliku "<<n<<":"<<endl<<endl;

    for( int i = 0; i<(nrLinii-1)*6 ; i++ ){
        getline(odczyt,linia);
    }

    while(getline(odczyt,linia)){
        switch(nr){
            case 1: a.x= atof(linia.c_str());
            case 2: a.y= atof(linia.c_str());
            case 3: b.x= atof(linia.c_str());
            case 4: b.y= atof(linia.c_str());
            case 5: c.x= atof(linia.c_str());
            case 6: c.y= atof(linia.c_str());
        }
        nr++;
    }
    odczyt.close();

    cout<<"Punkt A(x,y): ("<<a.x<<", "<<a.y<<")."<<endl;
    cout<<"Punkt B(x,y): ("<<b.x<<", "<<b.y<<")."<<endl;
    cout<<"Punkt C(x,y): ("<<c.x<<", "<<c.y<<")."<<endl;
}

void odczytklaw(wsp& a, wsp& b, wsp& c)
{
    system("cls");
    cout<<"Podaj wspolrzedne punktow."<<endl<<endl;
    cout<<"Punkt A: "<<endl;
    cout<<"x: "; cin>>a.x;
    cout<<"y: "; cin>>a.y;
    cout<<"Punkt B: "<<endl;
    cout<<"x: "; cin>>b.x;
    cout<<"y: "; cin>>b.y;
    cout<<"Punkt C: "<<endl;
    cout<<"x: "; cin>>c.x;
    cout<<"y: "; cin>>c.y;
    cout<<endl;

    cout<<"Punkt A(x,y): ("<<a.x<<", "<<a.y<<")."<<endl;
    cout<<"Punkt B(x,y): ("<<b.x<<", "<<b.y<<")."<<endl;
    cout<<"Punkt C(x,y): ("<<c.x<<", "<<c.y<<")."<<endl;
}

void odczytgot(wsp& a, wsp& b, wsp& c)
{
    cout<<"Wczytane dane z pliku: "<<endl<<endl;
    cout<<"Punkt A(x,y): ("<<a.x<<", "<<a.y<<")."<<endl;
    cout<<"Punkt B(x,y): ("<<b.x<<", "<<b.y<<")."<<endl;
    cout<<"Punkt C(x,y): ("<<c.x<<", "<<c.y<<")."<<endl;
}

void dlugosc(wsp& a, wsp& b, wsp& c, bok& x)
{
    x.ab=sqrt(pow(a.x-b.x,2.0)+pow(a.y-b.y,2.0));
    x.bc= sqrt(pow(b.x-c.x,2.0)+pow(b.y-c.y,2.0));
    x.ac= sqrt(pow(a.x-c.x,2.0)+pow(a.y-c.y,2.0));
}

void dlugoscOdczyt(bok& x)
{
    cout<<"Dlugosc boku x(AB): "<<x.ab<<endl;
    cout<<"Dlugosc boku y(BC): "<<x.bc<<endl;
    cout<<"Dlugosc boku z(AC): "<<x.ac<<endl<<endl;
}

void katy(wsp& a, wsp& b, wsp& c, bok& x, kat& k)
{
    dlugosc(a,b,c,x);

    k.CAB.x=(pow(x.ab,2.0)+pow(x.ac,2.0)-pow(x.bc,2.0))/(2.0*x.ab*x.ac);
    k.CAB.rad=acos(k.CAB.x);
    k.CAB.deg=acos(k.CAB.x)/M_PI*180.0;
    k.CAB.grad=acos(k.CAB.x)/M_PI*180*10.0/9.0;


    k.ABC.x=(pow(x.ab,2.0)+pow(x.bc,2.0)-pow(x.ac,2.0))/(2.0*x.ab*x.bc);
    k.ABC.rad=acos(k.ABC.x);
    k.ABC.deg=acos(k.ABC.x)/M_PI*180;
    k.ABC.grad=acos(k.ABC.x)/M_PI*180.0*10.0/9.0;

    k.BCA.x=(pow(x.bc,2.0)+pow(x.ac,2.0)-pow(x.ab,2.0))/(2.0*x.bc*x.ac);
    k.BCA.rad=acos(k.BCA.x);
    k.BCA.deg=acos(k.BCA.x)/M_PI*180.0;
    k.BCA.grad=acos(k.BCA.x)/M_PI*180.0*10.0/9.0;
}

void katyOdczytRad(kat& k)
{
    cout<<"Kat CAB w radianach wynosi: "<<k.CAB.rad<<endl;

    cout<<"Kat ABC w radianach wynosi: "<<k.ABC.rad<<endl;

    cout<<"Kat BCA w radianach wynosi: "<<k.BCA.rad<<endl<<endl;
}

void katyOdczytDeg(kat& k)
{
    float suma;

    cout<<"Kat CAB w stopniach wynosi: "<<k.CAB.deg<<endl;

    cout<<"Kat ABC w stopniach wynosi: "<<k.ABC.deg<<endl;

    cout<<"Kat BCA w stopniach wynosi: "<<k.BCA.deg<<endl<<endl;

    suma=k.CAB.deg+k.ABC.deg+k.BCA.deg;
    cout<<"Suma stopni: "<<suma<<endl<<endl;
}

void katyOdczytGrad(kat& k)
{
    float suma;

    cout<<"Kat CAB w gradach wynosi:   "<<k.CAB.grad<<endl;

    cout<<"Kat ABC w gradach wynosi:   "<<k.ABC.grad<<endl;

    cout<<"Kat BCA w gradach wynosi:   "<<k.BCA.grad<<endl<<endl;

    suma=k.CAB.grad+k.ABC.grad+k.BCA.grad;
    cout<<"Suma gradow: "<<suma<<endl<<endl;
}

void rodzajkaty(kat& k)
{
    cout<<"Katy: ";
    if(k.CAB.grad>100 || k.ABC.grad>100 || k.BCA.grad>100){
        cout<<"trojkat rozwartokatny."<<endl;
    }
    else if(k.CAB.grad<100 && k.ABC.grad<100 && k.BCA.grad<100){
        cout<<"trojkat ostrokatny."<<endl;
    }
    else if(k.CAB.grad==100 || k.ABC.grad==100 || k.BCA.grad==100){
        cout<<"trojkat prostokatny."<<endl;
    }
}

void rodzajboki(bok& x)
{
    cout<<"Boki: ";
    if(x.ab==x.bc || x.ab==x.ac || x.ac==x.bc){
        cout<<"trojkat rownoramienny."<<endl;
    }
    else if(x.ab==x.bc && x.ab==x.ac && x.ac==x.bc){
        cout<<"trojkat rownoboczny."<<endl;
    }
    else{
        cout<<"trojkat roznoboczny."<<endl;
    }
}

void barycentrum(wsp& a, wsp& b, wsp& c)
{
    float bx,by;
    bx=(a.x+b.x+c.x)/3.0;
    by=(a.y+b.y+c.y)/3.0;
    cout<<"Q("<<bx<<", "<<by<<")"<<endl<<endl;
}

void wysokosc(wsp& A, wsp& B, wsp& C, wysokosci& d)
{
    float a,b;

    a=(B.y-C.y)/(B.x-C.x);
    b=B.y-a*B.x;
    d.hy=(fabs(a*A.x-A.y+b))/sqrt(pow(a,2.0)+pow(1.0,2.0));

    a=(A.y-C.y)/(A.x-C.x);
    b=A.y-a*A.x;
    d.hz=(fabs(a*B.x-B.y+b))/sqrt(pow(a,2.0)+pow(1.0,2.0));

    a=(A.y-B.y)/(A.x-B.x);
    b=A.y-a*A.x;
    d.hx=(fabs(a*C.x-C.y+b))/sqrt(pow(a,2.0)+pow(1.0,2.0));
}

void wysokoscOdczyt(wysokosci& d)
{
    cout<<"A padajaca na bok y: h= "<<d.hy<<endl<<endl;
    cout<<"B padajaca na bok z: h= "<<d.hz<<endl<<endl;
    cout<<"C padajaca na bok x: h= "<<d.hx<<endl<<endl;
}

void polezwysokosci(bok& x, wysokosci& d)
{
    float s;

    s=(x.ab*d.hx)/2.0;
    cout<<"Pole z wysokosci hx opadajacej na bok x: "<<s<<endl;

    s=(x.bc*d.hy)/2.0;
    cout<<"Pole z wysokosci hy opadajacej na bok y: "<<s<<endl;

    s=(x.ac*d.hz)/2.0;
    cout<<"Pole z wysokosci hz opadajacej na bok z: "<<s<<endl<<endl;
}

void polezkatu(bok& x,kat& k)
{
    float s;

    s=(x.ab*x.ac*sin(k.CAB.rad))/2.0;
    cout<<"Pole z bokow x i z oraz katu miedzy nimi: "<<s<<endl;

    s=(x.ab*x.bc*sin(k.ABC.rad))/2.0;
    cout<<"Pole z bokow x i y oraz katu miedzy nimi: "<<s<<endl;

    s=(x.bc*x.ac*sin(k.BCA.rad))/2.0;
    cout<<"Pole z bokow y i z oraz katu miedzy nimi: "<<s<<endl<<endl;
}

void poleherona(bok& x)
{
    float p,s;
    p=(x.ab+x.ac+x.bc)/2.0;
    s=sqrt(p*(p-x.ab)*(p-x.ac)*(p-x.bc));
    cout<<"Pole obliczone ze wzoru Herona: "<<s<<endl<<endl;
}
