#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int ilosc_wierszy = 5;
int ilosc_kolumn = 5;
int tablica[5][5]; //ilosc elementow

int zaladuj_tablice() {
    for (int i=0; i<ilosc_wierszy; i++) {
        for (int j=0; j<ilosc_kolumn; j++) {
            cout<<"Podaj "<<j+1<<" wyraz "<<i+1<<" rzedu: ";
            //tablica[i][j] = rand() % 19 - 9;
            cin>>tablica[i][j];
            //cout<<tablica[i][j]<<endl;
        }
    }
    cout<<endl;
}

void wypisz_zawartosc() {
    for (int i=0; i<ilosc_wierszy; i++) {
        cout<<"Wyrazy "<<i+1<<" rzedu:";
        for (int j=0; j<ilosc_kolumn; j++) {
            cout<<" "<<tablica[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

int policz_sume_pierwszej_przekatnej() {
    int suma = 0;
    for (int i=0; i<ilosc_wierszy; i++) {
        suma += tablica[i][i];
    }
    return suma;
}
int policz_sume_drugiej_przekatnej() {
    int suma = 0;
    for (int i=0; i<ilosc_wierszy; i++) {
        suma += tablica[i][ilosc_kolumn-i-1];
    }
    return suma;
}
int policz_sume_nad_przekatna() {
    int suma = 0;
    for (int i=0; i<ilosc_wierszy; i++) {
        for (int j=i+1; j<ilosc_kolumn; j++) {
            suma += tablica[i][j];
        }
    }
    return suma;
}
int policz_sume_pod_przekatna() {
    int suma = 0;
    for (int i=0; i<ilosc_wierszy; i++) {
        for (int j=0; j<i; j++) {
            suma += tablica[i][j];
        }
    }
    return suma;
}
int wyznacz_minimum() {
    int minimum = tablica[0][0];
    for (int i=0; i<ilosc_wierszy; i++) {
        for (int j=0; j<ilosc_kolumn; j++) {
            if (minimum > tablica[i][j]) {
                minimum = tablica[i][j];
            }
        }
    }
    return minimum;
}

int menu() {
    int wybrany;
    cout<<"Zadania: "<<endl;
    cout<<"1. Wypisz zawartosc tabeli"<<endl;
    cout<<"2. Policz sume pierwszej przekatnej (lewy-gora - prawy-dol)"<<endl;
    cout<<"3. Policz sume drugiej przekatnej (lewy-dol - prawy-gora)"<<endl;
    cout<<"4. Policz sume nad pierwsza przekatna"<<endl;
    cout<<"5. Policz sume pod pierwsza przekatna"<<endl;
    cout<<"6. Wyznacz najmniejszy wyraz tabeli"<<endl;
    cout<<endl;
    cout<<"9. Zaladuj tabele ponownie"<<endl;
    cout<<"0. Wyjscie"<<endl;
    cout<<"Podaj numer zadania: ";
    cin>>wybrany;
    cout<<endl;
    return wybrany;
}

int main()
{
    reset:
        int wybor_menu;
        zaladuj_tablice();
    start_menu:
        wybor_menu = menu();
        switch (wybor_menu) {
            case 0: {
                goto exit;
                break;
            }
            case 1: {
                wypisz_zawartosc();
                break;
            }
            case 2: {
                int suma_pierwszej = policz_sume_pierwszej_przekatnej();
                cout<<"Suma pierwszej przekatnej: "<<suma_pierwszej<<endl;
                cout<<endl;
                break;
            }
            case 3: {
                int suma_drugiej = policz_sume_drugiej_przekatnej();
                cout<<"Suma drugiej przekatnej: "<<suma_drugiej<<endl;
                cout<<endl;
                break;
            }
            case 4: {
                int suma_nad = policz_sume_nad_przekatna();
                cout<<"Suma nad przekatna: "<<suma_nad<<endl;
                cout<<endl;
                break;
            }
            case 5: {
                int suma_pod = policz_sume_pod_przekatna();
                cout<<"Suma pod przekatna: "<<suma_pod<<endl;
                cout<<endl;
                break;
            }
            case 6: {
                int minimum = wyznacz_minimum();
                cout<<"Najmniejszy wyraz: "<<minimum<<endl;
                cout<<endl;
                break;
            }
            case 9: {
                goto reset;
                break;
            }
            default: {
                cout<<"///////////////////////////////////////////////"<<endl;
                cout<<"///Takie zadanie nie istnieje, wybierz inne.///"<<endl;
                cout<<"///////////////////////////////////////////////"<<endl;
                cout<<endl;
                goto start_menu;
                break;
            }
        }
        goto start_menu;
    exit:
        return 0;
}
