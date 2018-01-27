#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    int dlugosc_tablicy = 101;
    double wartosci_wspolczynnikow[101];
    int najwieksza_potega;
    double argument;
    double wynik = 0;
    int i = 0;
    int j = 1;
    string powtorka1;
    string powtorka2;
    cout<<"Ten program liczy wartosc wielomianu dla konkretnego argumentu."<<endl;
    while (j==1){
        cout<<"Przygotuj wielomian, pogrupuj go potegami x malejaco, jesli ktorejs potegi brakuje pamietaj by podac 0 jako wspolczynnik."<<endl;
        cout<<"Jesli jestes gotowy nacisnij ENTER."<<endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while(i==0){
            cout<<"Podaj najwyzsza potege wielomianu: ";
            cin>>najwieksza_potega;
            if (najwieksza_potega>=dlugosc_tablicy) {
                cout<<"Ten program liczy wartosc tylko dla mniejszych wielomianow, wybierz inny wielomian."<<endl;
            }
            else {
                if (najwieksza_potega<0) {
                    cout<<"Potega nie moze byc mniejsza od zera."<<endl;
                }
                else {
                    i = 1;
                }
            }
        }
        for (int i = 0; i <= najwieksza_potega; i++) {
            if (najwieksza_potega-i>0){
                cout<<"Podaj wspolczynnik stojacy przy x o potedze "<<najwieksza_potega-i<<": ";
            }
            else {
                cout<<"Podaj wyraz wolny: ";
            }
            cin>>wartosci_wspolczynnikow[i];
        }
        cout<<"Podaj argument, dla ktorego chcesz policzyc wartosc funkcji: ";
        cin>>argument;

        for (int i = 0; i <= najwieksza_potega; i++) {
            wynik += wartosci_wspolczynnikow[i];
            if (i != najwieksza_potega){
                wynik *= argument;
            }
        }
        cout<<endl;
        cout<<"Wynik dla argumentu "<<argument<<" wynosi: "<<wynik<<endl;
        cout<<endl;
        cout<<"Aby powtorzyc wpisz 1, aby zakonczyc wpisz 0: ";
        cin>>j;
        i=0;
        cout<<endl;
    }
    return 0;
}
