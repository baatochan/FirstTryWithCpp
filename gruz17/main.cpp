#include <iostream>

using namespace std;

int main()
{
    cout<<"Podaj a: ";
    int a;
    cin>>a;
    cout<<"Podaj b: ";
    int b;
    cin>>b;
    if (a>b){
        int x = a;
        a = b;
        b = x;
    }
    /*int xxx;
    int yyy;
    if (a==b){
        xxx = 0;
        yyy = xxx;
        if (a%3 == 0) {
            xxx++;
        }
        if (a%5 == 0) {
            yyy++;
        }
        cout<<"Ilosc liczb podzilenych przez 3 w przedziale wynosi: "<<xxx<<endl;
        cout<<"Ilosc liczb podzilenych przez 5 w przedziale wynosi: "<<yyy<<endl;
        return 0;
    }
    if (a%3 == 0){
        xxx = b-a;
        xxx /= 3;
        xxx++;
    }
    if (a%5 == 0){
        yyy = b-a;
        yyy /= 5;
        yyy++;
    }*/
    int xxx = a + 3 - (a%3);
    int ilosc3 = 0;
    if (a%3 == 0) xxx -= 3;
    while (xxx <= b) {
        xxx +=3;
        ilosc3++;
    }
    int yyy = a + 5 - (a%5);
    int ilosc5 = 0;
    if (a%5 == 0) yyy -= 5;
    while (yyy <= b) {
        yyy +=5;
        ilosc5++;
    }
    cout<<"Ilosc liczb podzilenych przez 3 w przedziale wynosi: "<<ilosc3<<endl;
    cout<<"Ilosc liczb podzilenych przez 5 w przedziale wynosi: "<<ilosc5<<endl;

    return 0;
}
