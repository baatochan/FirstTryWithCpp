#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

int array[5][5];

int wypelnij() {
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            //cout<<"Podaj "<<j+1<<" wyraz "<<i+1<<" rzedu: ";
            //cin>>array[i][j];
            array[i][j] = rand() % 19 - 9;
            //cout<<array[i][j]<<endl;
        }
    }
    cout<<endl;
}

int main() {
	wypelnij();
	cout << "podaj rzad do usuniecia: ";
	int rzad = 0;
	cin>>rzad;
	cout<<"przed"<<endl;
	for (int i = 0; i<5; i++){
		for (int j = 0; j<5; j++){
		cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}




	for (int i = rzad; i<5; i++){
		for (int j = 0; j<5; j++){
		array[i-1][j] = array[i][j];
		}
	}
	for (int i = 0; i<5; i++){
		array[4][i] = 0;
	}


	cout<<"po"<<endl;
	for (int i = 0; i<5; i++){
		for (int j = 0; j<5; j++){
		cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}






















	return 0;
}
