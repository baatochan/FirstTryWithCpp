#include <iostream>

using namespace std;

int main()
{
    string tab[40];
    int n = 0;
    do {
        cout<<"Podaj "<<n+1<<" lancuch znakow: ";
        getline(cin, tab[n]);
        n++;
    }
    while (n < 40 && tab[n-1] != "");
    n--;
    string* tabp[40];
    for (int i = 0; i < n; i++) {
        tabp[i] = &tab[i];
    }

    string* buf;
    for(int i=0; i<n;i++){
        for (int j=0;j<n-i-1;j++){
            if(((*tabp[j]).compare(*tabp[j+1]))>0){
                buf = tabp[j];
                tabp[j]=tabp[j+1];
                tabp[j+1]=buf;
            }
        }
    }
    cout<<"Podane lancuchy posortowane w alfabetycznej kolejnosci: "<<endl;
    for(int i = 0; i < n; i++){
        cout<<i+1<<". "<<*tabp[i]<<endl;
    }



    cout<<"Naciśnij kilkakrtonie ENTER, aby wyjść...";//pisze na linuxie, wiec komenda 'system("pause");' nie dziala
    cin.ignore().get();//pisze na linuxie, wiec komenda 'system("pause");' nie dziala
	return 0;
}
