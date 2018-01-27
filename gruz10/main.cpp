#include <iostream>
#include <math.h>
#include <fstream>
#include <string>

using namespace std;

void odl_pkt_od_prostej() {
    double A, B, C, x, y;
    cout<<"Podaj A wzoru prostej: ";
    cin>>A;
    cout<<"Podaj B wzoru prostej: ";
    cin>>B;
    cout<<"Podaj C wzoru prostej: ";
    cin>>C;
    cout<<"Podaj x punktu: ";
    cin>>x;
    cout<<"Podaj y punktu: ";
    cin>>y;
    double odl = A*x;
    odl += B*y;
    odl += C;
    if (odl<0) {
        odl *= -1;
    }
    double mianownik = A*A;
    mianownik += B*B;
    mianownik = sqrt(mianownik);
    odl /= mianownik;
    cout<<"Odleglosc wynosi: "<<odl;
}

void czy_element_jest_w_ciagu() {
    //string sciezka;
    //cout<<"Podaj sciezke bezwzgledna pliku z ciagiem: ";
    //cin.ignore();
    //getline(cin, sciezka);
    ifstream plik("xxx.txt");
    if (!plik.is_open()) {
        cout<<"Plik nie istnieje, sprawdz sciezke";
    }
    else {
        int tablica[100];
        int linia;
        int i = 0;
        while (!plik.eof()) {
            plik >> tablica[i];
            i++;
        }
        int liczba;
        cout<<"Podaj liczbe do sprawdzenia: ";
        cin>>liczba;
        int k=1;
        for(int j = 0; j<100; j++){
            if (tablica[j] == liczba){
                cout<<"Liczba wystepuje "<<k<<" raz";
                k++;
            }
        }
        if (k==0) {
            cout<<"Liczba nie wystepuje."
        }
    }
}

int main()
{
    czy_element_jest_w_ciagu();
    return 0;
}
