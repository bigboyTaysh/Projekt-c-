#include "funkcje.hpp"
#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

void menuwczytaj()
{
    wsp a,b,c;
    bok x;
    kat k;
    wysokosci h;
    char w,w2,w3;
    string n;

    odczytplik(a,b,c,n);

    dlugosc(a,b,c,x);
    katy(a,b,c,x,k);
    wysokosc(a,b,c,h);

    kolor(2);
    cout<<"==========KLASYFIKACJA=========="<<endl<<endl;
    cout<<"1. Dlugosci bokow.\n2. Katy wewnetrzne.\n3. Rodzaj trojkata.\n4. Srodek geometryczny.\n5. Wysokosci trojkata.\n6. Pole powierzchni.\n7. Czyszczenie ekranu.\n8. Wczytanie innego trojkata.\nESC. Wyjscie."<<endl<<endl;
    cout<<"================================"<<endl<<endl;
    kolor(15);

    do{

    kolor(3);
    cout<<"Wybor z menu: ";
    kolor(15);

    w=getch();

    if((int)w>=49 && (int)w<=55){
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
            kolor(2);
            cout<<"1. Dlugosc bokow."<<endl<<endl;
            kolor(15);
            dlugoscOdczyt(x);
            cout<<endl;
            break;

        case '2':
            kolor(2);
            cout<<"2.Katy ABC,BCA,CAB(radiany,stopnie,grady)."<<endl<<endl;
            kolor(15);
            cout<<"1. Kat w radianach.\n2. Kat w stopniach.\n3. Kat w gradach.\n4. Wyjscie do menu."<<endl<<endl;

            do{
            kolor(8);
            cout<<"Wybor: ";
            kolor(15);
            w2=getch();

            if(w2>=49 && w2<=51){
                cout<<w2<<endl<<endl;
            }
            else if(w2==52){
                cout<<"Wyjscie do menu."<<endl<<endl;
            }
            else if(w2==0 || w2==-32){
                w2=getch();
                cout<<"Nie ma takiej opcji! Wyjscie do menu."<<endl<<endl;
            }
            else{
                cout<<"Nie ma takiej opcji! Wyjscie do menu."<<endl<<endl;
            }

            switch(w2){
                case '1':
                    katyOdczytRad(k);
                    break;
                case '2':
                    katyOdczytDeg(k);
                    break;
                case '3':
                    katyOdczytGrad(k);
                    break;
                case '4':
                    break;
            }
            }while(w2!=52);

            break;
            break;

        case '3':
            kolor(2);
            cout<<"3.Rodzaj trojkata ze wgledu na: "<<endl;
            kolor(15);
            rodzajkaty(k);
            rodzajboki(x);
            cout<<endl;
            break;

        case '4':
            kolor(2);
            cout<<"4.Srodek geometryczny: "<<endl;
            kolor(15);
            barycentrum(a,b,c);
            break;

        case '5':
            kolor(2);
            cout<<"5.Wysokosc trojkata przechodzaca przez punkt: "<<endl<<endl;
            kolor(15);
            wysokoscOdczyt(h);
            break;

        case '6':
            kolor(2);
            cout<<"6.Pole powierzchni: "<<endl<<endl;
            cout<<"Przyjmujac dla trojkata ABC nastepujace oznaczenia\nx, y, z - dlugosci bokow odpowiednio |AB|, |BC|, |AC|;\nhx, hy, hz - wysokosci opuszczone na boki odpowiednio x, y, z;\nS- pole powierzchni"<<endl<<endl;
            kolor(15);
            cout<<"1. Pole obliczone za pomoca boku i wysokosci na niego padajacej.\n2. Pole obliczone za pomoca dwoch bokow i katu miedzy nimi.\n3. Pole obliczone za pomoca wzoru Herona.\n4. Wyjscie do menu."<<endl<<endl;

            do{
            kolor(8);
            cout<<"Wybor: ";
            kolor(15);
            w3=getch();

            if(w3>=49 && w3<=51){
                cout<<w3<<endl<<endl;
            }
            else if(w3==52){
                cout<<"Wyjscie do menu."<<endl<<endl;
            }
            else if(w3==0){
                w3=getch();
                cout<<"Nie ma takiej opcji! Wyjscie do menu."<<endl<<endl;
            }
            else{
                cout<<"Nie ma takiej opcji! Wyjscie do menu."<<endl<<endl;
            }

            switch(w3){
                case '1':
                    polezwysokosci(x,h);
                    break;
                case '2':
                    polezkatu(x,k);
                    break;
                case '3':
                    poleherona(x);
                    break;
                case '4':
                    break;
            }
            }while(w3!=52);

            break;

        case '7':
            system ("cls");
            odczytgot(a,b,c);

            kolor(2);
            cout<<"==========KLASYFIKACJA=========="<<endl<<endl;
            cout<<"1. Dlugosci bokow.\n2. Katy wewnetrzne.\n3. Rodzaj trojkata.\n4. Srodek geometryczny.\n5. Wysokosci trojkata.\n6. Pole powierzchni.\n7. Czyszczenie ekranu.\n8. Wczytanie innego trojkata.\nESC. Wyjscie."<<endl<<endl;
            cout<<"================================"<<endl<<endl;
            kolor(15);
            break;

        case '8':
            system ("cls");
            odczytplik2(a,b,c,n);

            kolor(2);
            cout<<"==========KLASYFIKACJA=========="<<endl<<endl;
            cout<<"1. Dlugosci bokow.\n2. Katy wewnetrzne.\n3. Rodzaj trojkata.\n4. Srodek geometryczny.\n5. Wysokosci trojkata.\n6. Pole powierzchni.\n7. Czyszczenie ekranu.\n8. Wczytanie innego trojkata.\nESC. Wyjscie."<<endl<<endl;
            cout<<"================================"<<endl<<endl;
            kolor(15);
            break;

        case 27:
            system ("cls");
            mainmenu();
            break;

        default:
            break;
        }

    }while((int)w!=27);
}
