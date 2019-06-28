#ifndef funkcje_hpp
#define funkcje_hpp

#include <string>
using namespace std;

struct wsp
{
    float x,y;
};

struct bok
{
    float ab,bc,ac;
};

struct rodzajkata
{
    float x,rad,deg,grad;
};

struct kat
{
    rodzajkata CAB, ABC, BCA;

};

struct wysokosci
{
    float hx,hy,hz;
};

void mainmenu();
void menuwczytaj();
void menulosowe();
void menupodanie();
void kolor(int i);
void boki(wsp& a, wsp& b, wsp& c);
void zapisilosowanie(wsp& a, wsp& b, wsp& c);
void odczytlos(wsp& a, wsp& b, wsp& c);
void odczytplik(wsp& a, wsp& b, wsp& c, string& n);
void odczytplik2(wsp& a, wsp& b, wsp& c, string& n);
void odczytklaw(wsp& a, wsp& b, wsp& c);
void odczytgot(wsp& a, wsp& b, wsp& c);
void dlugosc(wsp& a, wsp& b, wsp& c, bok& x);
void dlugoscOdczyt(bok& x);
void katy(wsp& a, wsp& b, wsp& c, bok& x, kat& k);
void katyOdczytRad(kat& k);
void katyOdczytDeg(kat& k);
void katyOdczytGrad(kat& k);
void rodzajkaty(kat& k);
void rodzajboki(bok& x);
void barycentrum(wsp& a, wsp& b, wsp& c);
void wysokosc(wsp& A, wsp& B, wsp& C, wysokosci& h);
void wysokoscOdczyt(wysokosci& d);
void polezwysokosci(bok& x, wysokosci& d);
void poleherona(bok& x);
void polezkatu(bok& x,kat& k);

#endif
