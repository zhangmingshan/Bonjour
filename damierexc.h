#ifndef DAMIEREXC_H
#define DAMIEREXC_H
#include <iostream>
using namespace std;

#include "exceptiondamier.h"


class DamierExc
{
public:
    DamierExc(int l, int c, int vm, int value = 0);
    DamierExc(const DamierExc &D);
    ~DamierExc();

    DamierExc& operator=  (const DamierExc &D); // opérateur d'affectation
    DamierExc& operator+= (const DamierExc &D);
    DamierExc& operator+= (int c);
    DamierExc  operator+  (const DamierExc &D);
    friend ostream& operator<< (ostream& sortie, DamierExc& V);

    void Print();
    void Init(int value);
    void Set(int x, int y, int value);
    void ReDim(int l, int c, int vd = 7);

private:

    // Méthode privée (factorisation  de code)
    void Alloc(int l, int c);
    void Free();
    bool sameDimensions (const DamierExc &D);
protected:
    int L;
    int C;
    int** T;
    int Max;
};

#endif // DAMIEREXC_H
