#include <iostream>
#include <string>
#include <fstream>

using namespace std;

char szyfr[2][27] = {
    {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'r', 's', 't', 'u', 'w', 'x', 'y', 'z', ' ', '.', ','
    },
    {
        'z', 'o', 'm', 'f', '.', 'a', 'r', 'n', 'k', 'b', 'e', 'l', 'c', 'p', 's', 'd', 'w', 'y', 'x', 'j', ',', 'u', 'h', 't', ' ', 'g', 'i'
    }
};


int main()
{
    cout << "Ten program zaszyfruje tekst z pliku tekst.txt do pliku krypt.txt. Upewnij sie ze oba pliki istnieja!" << endl;
    string tekst;
    fstream plik("tekst.txt");
    if (!plik.is_open()) {
        cout<<"Problem z plikiem, upewnij sie ze istnieje (tekst.txt w folderze solucji)!";
    }
    else {
        while (!plik.eof()) {
            getline(plik, tekst);
            break;
        }
    }
    string wynik = tekst;
    int dlugosc = tekst.length();
    for (int i = 0; i<dlugosc ;i++) {
        char znak = tekst[i];
        for (int j=0; j<27; j++){
            if (znak == szyfr[0][j]){
                wynik[i] = szyfr[1][j];
            }
        }
    }
    fstream plik2("krypt.txt");
    if (!plik.is_open()) {
        cout<<"Problem z plikiem, upewnij sie ze istnieje (krypt.txt w folderze solucji)!"<<endl;
    }
    else {
        plik2<<wynik;
    }
    return 0;
}
