#include "funkcje.hpp"
#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

void mainmenu()
{
    char w;

    kolor(2);
    cout<<"==========================MENU=========================="<<endl<<endl;
    kolor(15);
    cout<<"Pogram wykonuje obliczenia na podstawie wspolrzednych\n       trojkata a nastepnie go klasyfikuje."<<endl<<endl;
    kolor(2);
    cout<<"Wspolrzedne:\n1. Podane z klawiatury.\n2. Wczytane z pliku.\n3. Losowe.\nESC. Wyjscie."<<endl<<endl;
    cout<<"========================================================"<<endl<<endl;
    kolor(15);

    do{
    kolor(3);
    cout<<"Wybor z menu: ";
    kolor(15);
    w=getch();

    if((int)w==27){
    cout<<"Koniec programu!"<<endl<<endl;
    }
    else if((int)w>=49 && (int)w<=51){
        cout<<w<<endl<<endl;
    }
    else if((int)w==0 || (int)w==-32){
        w=getch();
        cout<<"Nie ma takiej opcji w menu!"<<endl<<endl;
    }
    else{
        cout<<"Nie ma takiej opcji w menu!"<<endl<<endl;
    }

        switch(w){
            case '1':
                menupodanie();
                break;
            case '2':
                menuwczytaj();
                break;
            case '3':
                menulosowe();
                break;
            case 27:
                exit(0);
        }
    }while((int)w!=27);
}
