#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void WPISZ (int TAB[], int n) {
    srand(time(NULL));
    for (int i=0; i<n; i++) TAB[i] = rand();
}
void PISZ (int TAB[], int n) {
    cout<<"Zawartosc tablicy TAB: "<<endl;
    for (int i=0; i<n; i++) cout<<TAB[i]<<endl;
}
void OBLICZ (int TAB[], int n) {
    int T[n];
    int iloczyn = 1;
    for (int i=0; i<n; i++){
        T[i] = TAB[i] * -1;
        iloczyn *= T[i];
    }
    cout<<"Zawartosc tablicy T: "<<endl;
    for (int i=0; i<n; i++) cout<<T[i]<<endl;
    cout<<"Iloczyn wartosci tablicy T: "<<iloczyn<<endl;
}

void ILE (int TAB[], int n) {
    int ilosc_nieparzystych = 0;
    for (int i=0; i<n; i++){
        //int x = TAB[i]/2;
        //int y = x*2;
        //if (y != TAB[i]) ilosc_nieparzystych++;
        if (TAB[i]%2 == 1) ilosc_nieparzystych++;
    }
    cout<<"Ilosc nieparzystych liczb w tablicy TAB: "<<ilosc_nieparzystych<<endl;
}

int ROZ (int TAB[], int n){
    int maks = TAB[0];
    int minim = TAB[0];
    for (int i=1; i<n;i++){
        if (maks < TAB[i]) maks = TAB[i];
        if (minim > TAB[i]) minim = TAB[i];
    }
    int rozpietosc = maks - minim;
    rozpietosc += 1;
    return rozpietosc;
}

int main()
{
    cout<<"Podaj liczbe n: ";
    int n;
    cin>>n;
    int TAB[n];
    WPISZ(TAB, n);
    PISZ(TAB, n);
    OBLICZ(TAB, n);
    ILE(TAB, n);
    int rozpietosc = ROZ(TAB, n);
    cout<<"Rozpietosc tablicy TAB: "<<rozpietosc<<endl;

    return 0;
}
