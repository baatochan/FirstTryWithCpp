#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

bool zawiera(int pozycja, int pozycje[], int pozycje_length)
{
    for (int i=0; i<pozycje_length; i++)
    {
        if (pozycja==pozycje[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    srand( time( NULL ) );
    //cout << "Hello world!" << endl;
    fstream plik1;
    plik1.open("in.pbm");
    if (plik1.is_open() == false)
    {
        cout<<"Problem"<<endl;
        return 0;
    }
    string in[4];
    for (int i=0; i<4; i++)
    {
        plik1>>in[i];
    }

    istringstream buffer1(in[2]);
    istringstream buffer2(in[3]);
    int x1;
    int x2;

    buffer1>>x1;
    buffer2>>x2;



    const int dlugosc = x1*x2;

    const int dlugosc_datas = (dlugosc/70) + 1;

    string datas[dlugosc_datas];

    for (int i=0; i<dlugosc_datas; i++)
    {
        plik1>>datas[i];
    }
    //cout


    //string datas = in[3];
    //cout<<datas<<endl;
    //cout<<datas.length()<<endl;
    int datai[dlugosc];
    //if (datas.length()<=9999){
    for (int i=0; i<dlugosc_datas; i++)
    {
        string xxx = datas[i];
        for (int j=0; j<70; j++)
        {
            char a = xxx[j];
            int b;
            //cout<<a<<endl;
            if (a=='1')
            {
                b=1;
            }
            else if (a=='0')
            {
                b=0;
            }
            else
            {
                cout<<"Problem2"<<endl;
                return 0;
            }
            datai[(70*i)+j]=b;
            if (i==(dlugosc_datas-1)&&j==((dlugosc-(70*i))-1))
            {
                break;
            }
        }
        //cout<<datai[i]<<endl;
    }
    //}
    //else{
    //    cout<<"Problem3"<<endl;
    //    return 0;
    //}
    //cout<<in[0]<<endl;
    //cout<<in[1]<<endl;
    //cout<<in[2]<<endl;
    //for (int i = 0; i<20; i++){
    //    cout<<datai[i]<<endl;
    //}



























    double procent;
    cout<<"Podaj ilosc procentow do uszkodzenia: ";
    cin>>procent;



    procent /= 100;
    int procilosc = procent*dlugosc;
    const int prociloscc = procilosc;
    int pozycje[prociloscc];
    //cout<<procilosc;
    int j=0;
    for (int i=0; i<procilosc; i++)
    {
        int pozycja = (rand()%(dlugosc));
        //cout<<pozycja<<endl;
        if (zawiera(pozycja, pozycje, prociloscc)==false)
        {
            //cout<<"false"<<endl;
            //cout<<j<<endl;
            pozycje[j]=pozycja;
            j++;
            if (datai[pozycja] == 1)
            {
                datai[pozycja] = 0;
            }
            else if (datai[pozycja] == 0)
            {
                datai[pozycja] = 1;
            }
            else
            {
                cout<<"Problem5"<<endl;
                return 0;
            }
        }
        else
        {
            procilosc++;
            //cout<<"true"<<endl;
        }
    }





























http://nudist-teen.org/













    fstream plik2;
    plik2.open("out.pbm");
    if (plik2.is_open() == false)
    {
        cout<<"Problem3"<<endl;
        return 0;
    }
    string linia2 = in[2] + " " + in[3];
    string linia3;
    for (int i=0; i<dlugosc; i++)
    {
        //linia3+=datai[i];
        int x = datai[i];
        //cout<<x<<endl;
        if (x==1)
        {
            linia3 += '1';
        }
        else if (x==0)
        {
            linia3 += '0';
        }
        else
        {
            cout<<"Problem4"<<endl;
        }
    }
    plik2<<in[0]<<endl;
    plik2<<linia2<<endl;
    plik2<<linia3<<endl;
    //cout<<in[0]<<endl;
    //cout<<linia2<<endl;
    //cout<<linia3<<endl;
    //cout<<prociloscc<<endl;
    //cout<<dlugosc<<endl;
    double procilosccd = prociloscc;
    double dlugoscd = dlugosc;
    double zniszczenia = procilosccd/dlugoscd;
    //cout<<zniszczenia<<endl;
    zniszczenia*=100;
    cout<<"Zniczone zostalo "<<zniszczenia<<"% danych."<<endl<<"Operacja wykonana poprawnie :)"<<endl;















    return 0;
}
