#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

int main()
{
    double x;
    int n;
    cout<<"Podaj x: ";
    cin>>x;
    cout<<"Podaj n: ";
    cin>>n;
    double xxx;
    switch (n){
        case 1:
            xxx = 2*x;
            xxx = sqrt(xxx);
            break;
        case 2:
            xxx = x*x*x;
            xxx -= 5;
            break;
        case 3:
            xxx = cos(x);
            xxx += 1;
            break;
        default:
            xxx = 1;
            break;
    }
    cout<<xxx;
}
