#include <iostream>

using namespace std;

int sprawdz1 (string xxx1, string xxx2)
{
    int x1 = xxx1.length();
    int x2 = xxx2.length();
    int xout = 0;
    if (x1 == x2) {
        for (int i = 0; i < x1; i++) {
            if (xxx1[i] != xxx2[i]) {
                xout = i;
                xout++;
                break;
            }
        }
    }
    else {
        xout = -1;
    }
    return xout;
}

int main()
{
    cout << "Podaj pierwsze slowo: ";
    string xxx1, xxx2;
    getline(cin, xxx1);
    cout << "Podaj drugie słowo (ta sama długość co pierwsze): ";
    getline(cin, xxx2);
    int x = sprawdz1(xxx1, xxx2);
    cout << x;
    return 0;
}
