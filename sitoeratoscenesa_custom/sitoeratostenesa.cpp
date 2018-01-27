#include <iostream>
#include <fstream>

using namespace std;

const int n = 10000;

bool numbersTable[n + 3]; // tablica o indeksach od 0 do 100 | wszystkie false (czyli: 0);

int main()
{
    for (int i = 2; i*i <= n; i++ ) // przeszukuj liczby od 2 do sqrt(n), 0 i 1 nie są liczbami pierwszymi
    {
        if (numbersTable[i] == true) // jeżeli dana liczba jest już wykreślona
            continue; // to przejdź do kolejnej
        for (int j = 2*i ; j <= n; j += i) // przejdź od liczby 2*i do n przesuwając się o i
            numbersTable[j+2] = true; // i każdą z nich usuwaj ze zbioru
    }
    for (int i =0; i<n+2; i++) {
        if (numbersTable[i] == false) continue;
        if (i%2==0) {numbersTable[i]=false;}
    }

    cout << "Liczby pierwsze z przedziału od 2 do " << n << ":" << endl;
    
    for (int i = 2; i <= n; i++){ // przeszukaj liczby od 2 do n
        if (numbersTable[i] == true){ // jeśli liczba nie została usunięta ze zbioru
            cout << i << endl;}} // to ją wypisz
    ofstream plik("private/sitoeratoscenesa_custom/output.txt");
        for (int i = 2; i <= n; i++) // przeszukaj liczby od 2 do n
        if (numbersTable[i] == true) // jeśli liczba nie została usunięta ze zbioru
            plik << i << endl;
    return 0;
}