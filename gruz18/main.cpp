#include <iostream>

using namespace std;

int potega3 (int potega) {
    int wynik = 1;
    for (int i=0; i<potega; i++) wynik *= 3;
    return wynik;
}

int main()
{
    cout<<"Podaj smax: ";
    int smax;
    cin>>smax;
    int wynik = 0;
    int i = 0;
    while (wynik<smax){
        wynik += potega3(i);
        i++;
    }
    cout<<"Suma kolejnych poteg 3 do potegi "<<i<<" wynosi: "<<wynik<<endl;




    return 0;
}
