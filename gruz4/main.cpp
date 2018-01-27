#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool palindron(string pal){
	double x = pal.length();
	double y = x/2;
	for(int i =0; i<y; i++){
        if (pal[i] != pal[x-1-i]) {
            return false;
        }
	}
	return true;
}

bool znak(string ciag, char znak){
    int x = ciag.length();
    for (int i = 0; i<x; i++){
        if (ciag[i] == znak){
            return true;
        }
    }
    return false;
}

bool pierwsza(int liczba){
    int x = sqrt(liczba);
    for(int i = 2; i <= x; i++){
        if (liczba%i==0){
            return false;
        }
    }
    return true;
}

bool wzg_pierwsze(int licz1, int licz2){
    int x;
    while(licz1!=0){
        x=licz2%licz1;
        licz2=licz1;
        licz1=x;
    }
    if (licz2 > 1){
        return false;
    }
    else {
        return true;
    }

}

int fibonaczi(int numer){
    int fib[numer];
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i<numer; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[numer-1];
}

int menu(){
    int y;
    cout<<"Zadania: "<<endl;
    cout<<"1. Sprawdz czy ciag to palindrom"<<endl;
    cout<<"2. Sprawdz czy ciag zawiera znak"<<endl;
    cout<<"3. Sprawdz czy liczba jest pierwsza"<<endl;
    cout<<"4. Sprawdz czy liczby sa wzgledie pierwsze"<<endl;
    cout<<"5. Zdobadz x element ciagu fibonacziego"<<endl;
    cout<<"0. Wyjscie"<<endl;
    cout<<"Podaj numer zadania: "<<endl;
    cin>>y;
    return y;
}

int main() {
	int wybor;
	bool bool1;
	char char1;
	int int1;
	int int2;
    string string1;
    string string2;
	menu1:
	wybor = menu();
	switch (wybor) {
		case 0: {
			return 0;
			break;
		}
		case 1:
			cout << "Podaj ciag do sprawdzenia: "<<endl;
			cin.ignore();
			getline(cin, string1);
			if (palindron(string1)) {
				cout<<"Podales palindron, hurra!"<<endl;
			}
			else {
				cout<<"Nie podales palindronu, popraw sie :)"<<endl;
			}
            cout<< " "<<endl;
			goto menu1;
			break;
		case 2:
			cout << "Podaj ciag do sprawdzenia: "<<endl;
			cin.ignore();
			getline(cin, string2);
			cout << "Podaj znak do sprawdzenia: "<<endl;
			cin>>char1;
			if (znak(string2, char1)) {
				cout<<"Podany ciag zawiera znak, weeee!"<<endl;
			}
			else {
				cout<<"Podany ciag nie zawiera znaku, dopisz go na koncu :)"<<endl;
			}
            cout<< " "<<endl;
			goto menu1;
			break;
		case 3:
			cout << "Podaj liczbe do sprawdzenia: "<<endl;
			cin>>int1;
			if (pierwsza(int1)) {
				cout<<"Liczba pierwsza..."<<endl;
			}
			else {
				cout<<"Liczba nie pierwsza ;)"<<endl;
			}
            cout<< " "<<endl;
			goto menu1;
			break;
		case 4:
			cout << "Podaj liczbe do sprawdzenia: "<<endl;
			cin>>int1;
			cout << "Podaj druga liczbe do sprawdzenia: "<<endl;
			cin>>int2;
			if (wzg_pierwsze(int1, int2)) {
				cout<<"Liczby wzglednie pierwsze"<<endl;
			}
			else {
				cout<<"Nie sa wzglednie pierwsze, no cos ty..."<<endl;
			}
            cout<< " "<<endl;
			goto menu1;
			break;
		case 5:
			cout << "Podaj interesujacy cie wyraz ciagu: "<<endl;
			cin>>int1;
			int2 = fibonaczi(int1);
			cout<<int2;
            cout<< " "<<endl;
			goto menu1;
			break;
		default:
			goto menu1;
			break;
	}
}
