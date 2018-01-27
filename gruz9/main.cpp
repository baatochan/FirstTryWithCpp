#include <iostream>
#include <fstream>

using namespace std;

ifstream file("data.txt");
string data;

int main() {
	if(!file.good()){
		cout<<"Plik nie istnieje!";
		return 1;
	}
	int j = 0;
	while (!file.eof()){
		getline(file, data);
		cout<<"Linijka "<<j+1<<": "<<data<<endl;
		j++;
	}
	return 0;
}
