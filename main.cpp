#include <iostream>
using namespace std;

#include "damierexc.h"
#include "exceptiondamier.h"
#include "damierdame.h"
#include "damiergo.h"
#include "damierechec.h"

int main()
{
    /*
    DamierExc D(3,5,4);
    try
    {
        D.Set(2,1,2);
        D.Print();
        cout<<endl;
    }catch (const char* message)
    { // origine : IndiceValide
        cerr << "Probleme: " << message << endl;
    }

    DamierExc D1(3,5,4);
    try
    {
        D1.Set(1,2,3);
        D1.Print();
        cout<<endl;
    }catch ( const borne & b ){
        cerr << b.what() << "\n";
    }

    DamierExc D2(3,5,4);
    try
    {
        D2.Init(2);
        D2.Set(1,2,6);
        D2.Print();
    }catch ( const borne & b ){
        cerr << b.what() << "\n";
    }
    */
    DamierDame JeuDame;
    cout<<JeuDame;
    cout << endl;

    DamierGo JeuGo;
    cout<<JeuGo;
    cout<<endl;

    DamierEchec JeuEchec;
    cout<<JeuEchec;
    cout<<endl;

}
