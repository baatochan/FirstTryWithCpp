#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int a = 3;
int b = 0;
bool szyfrator;

string szyfruj (bool szyfator, string tekst) {
    string wynik = tekst;
    int j = -1;
    int dlugosc = tekst.size();
    for (int i=0; i<dlugosc; i++){
        char znak = tekst[i];
        if (znak>=65&&znak<=90) {
            j++;
            if (szyfrator){
                znak += a;
                znak += (j*b);
                while(znak>90){
                    znak -= 26;
                }
            }
            else {
                znak -= a;
                znak -= (j*b);
                while(znak<65){
                    znak += 26;
                }
            }
        }
        else if (znak >= 97 && znak <= 122){
            j++;
            if (szyfrator){
                znak += a;
                znak += (j*b);
                while(znak>122){
                    znak -= 26;
                }
            }
            else {
                znak -= a;
                znak -= (j*b);
                while(znak<97){
                    znak += 26;
                }
            }
        }
        else if (znak >= 48 && znak <= 57){
            j++;
            if (szyfrator){
                znak += a;
                znak += (j*b);
                while(znak>57){
                    znak -= 10;
                }
            }
            else {
                znak -= a;
                znak -= (j*b);
                while(znak<48){
                    znak += 10;
                }
            }
        }
        wynik[i]=znak;
    }
    return wynik;
}

void settings() {
    cout<<"Szyfr dzial wg wzoru litera_zaszyfrowana = litera_poczatkowa + a + b*(i-1)"<<endl;
    cout<<"Podaj a: ";
    cin>>a;
    cout<<"Podaj b: ";
    cin>>b;
}

int main()
{
    char wybor;
    bool petla;
    cout<<"Szyfrator/deszyfrator szyfru cezara." << endl;
    cout<<"Szyfrator przesuwa litery o a znakow + b*(i-1) znakow, gdzie n i z jest zmienna ustalona przez uzytkownika a i numerem litery badz cyfry w wiadomosci (inne znaki nie sa brane w ogole pod uwage)" <<endl;
    petla = true;
    while (petla){
        cout<<"Czy chcesz ustalic a i b? [y/n]: ";
        wybor = NULL;
        cin>>wybor;
        if (wybor == 'y') {
            settings();
            petla = false;
        }
        else if (wybor == 'n') {
            petla = false;
        }
    }
    petla = true;
    while (petla){
        cout<<"Szyfrator czy deszyfrator? [s/d]: ";
        wybor = NULL;
        cin>>wybor;
        if (wybor == 's') {
            szyfrator = true;
            petla = false;
        }
        else if (wybor == 'd') {
            szyfrator = false;
            petla = false;
        }
    }

    string tekst[9999];
    fstream plik("dane.txt");
    if (!plik.is_open()) {
        cout<<"Plik nie istnieje, sprawdz sciezke";
    }
    else {
        int i = 0;
        while (!plik.eof()) {
            getline(plik, tekst[i]);
            i++;
        }
    }
    string wynik[9999];
    int j=0;
    for (int i=0;i<9999;i++){
        string linia = tekst[i];
        wynik[i] = szyfruj(szyfrator, linia);
        if (linia == ""){
            j++;
            if (j==10){
                break;
            }
        }
    }
    petla = true;
    while (petla){
        cout<<"Czy plik 'wynik.txt' istnieje? [y/n]: ";
        wybor = NULL;
        cin>>wybor;
        if (wybor == 'y') {
            petla = false;
        }
        else if (wybor == 'n') {
            cout<<"Stworz plik przed kontynuacja"<<endl;
            petla == true;
        }
    }
    fstream plik2("wynik.txt");
    if (!plik.is_open()) {
        cout<<"Problem z plikiem"<<endl;
    }
    else {
        int j = 0;
        for (int i=0;i<9999;i++){
            plik2<<wynik[i]<<endl;
            if (wynik[i]==""){
                j++;
                if (j>10) break;
            }
        }
    }
    return 0;
}
