#include <iostream>

using namespace std;

int main()
{
    cout << "Podaj a: ";
    int a;
    cin>>a;
    cout << "Podaj b: ";
    int b;
    cin>>b;
    cout << "Podaj c: ";
    int c;
    cin>>c;
    bool trojkat = true;
    if (a+b<c) trojkat = false;
    if (c+b<a) trojkat = false;
    if (a+c<b) trojkat = false;
    bool prostokatny = false;
    if (trojkat) {
        int maks = a;
        if (maks<b) maks = b;
        if (maks<c) maks = c;
        int minim = a;
        if (minim>b) minim = b;
        if (minim>c) minim = c;
        int sredni = a+b+c;
        sredni -= maks + minim;
        if (minim*minim + sredni*sredni == maks*maks) {
            prostokatny = true;
        }
    }

    if (trojkat) {
        cout<<"Mozna z tego zbudowac trojkat";
        if (prostokatny) {
            cout<<" prostokatny."<<endl;
        }
        else {
            cout<<"."<<endl;
        }
    }
    else {
        cout<<"Nie mozna zbudowac trojkata."<<endl;
    }

    return 0;
}
