#include "damierexc.h"

DamierExc::DamierExc(int l, int c, int vm, int value)
{
    Alloc(l, c);
    Max = vm;
    Init(value);
}


DamierExc::DamierExc(const DamierExc &D)
{
    Alloc(D.L, D.C);
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            T[i][j] = D.T[i][j];
}


DamierExc::~DamierExc(){
    if (T != NULL) {
        Free();
        T = NULL;
    }
}

void DamierExc::Free(){
    for (int i=0; i<L; i++) {
        delete [] T[i];
    }
    delete [] T;
}

void DamierExc::Alloc(int l, int c){
    L = l;
    C = c;
    T = new int*[L];
    for(int i=0; i<L; i++)
        T[i] = new int[C];
}

void DamierExc::Print(){
    cout << endl;
    for(int i=0; i<L; i++) {
        cout << endl;
        for(int j=0; j<C; j++)
            cout << T[i][j] << ", ";
    }
}

void DamierExc::Init(int value){
    if ((value<0) || (value>=Max)) {
        string file(__FILE__);
        string fonction(__PRETTY_FUNCTION__);
        borne e(value, Max, file, fonction);
        throw(e);
    }
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            T[i][j]=value;
}

void IndiceValide (int x, int y, int l, int c)
{
    if(x<0||x>l||y<0||y>c)
        throw("Acces case du Damier incorrecte");
}

void DamierExc::Set(int x, int y, int value) {

    if (value<0||value>Max)
    {
        string file(__FILE__);
        string fonction(__PRETTY_FUNCTION__);
        borne e(value,Max,file,fonction);
        throw (e);
    }
    IndiceValide(x,y,L,C);
    T[x][y]=value;
}


void DamierExc::ReDim(int l, int c, int vd) {
    Free();
    Alloc(l, c);
    Init(vd);
}

DamierExc& DamierExc::operator= (const DamierExc &D){
    if ( this != &D) { // protection autoréférence
        Free();
        Alloc(D.L, D.C);
        for(int i=0; i<L; i++)
            for(int j=0; j<C; j++)
                T[i][j] = D.T[i][j];
    }
    return *this;
}

bool DamierExc::sameDimensions (const DamierExc &D) {
    if ((L == D.L) && (C == D.C))
        return true;
    return false;
}

DamierExc& DamierExc::operator+= (int c)
{
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            T[i][j] += c;
    return *this;
}

DamierExc& DamierExc::operator+= (const DamierExc &D)
{
    if (!sameDimensions(D)){
        cerr << endl << __PRETTY_FUNCTION__ << " - Dimensions différentes !\n";
        exit(1);
    }
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            T[i][j] += D.T[i][j];
    return *this;
}


DamierExc DamierExc::operator+ (const DamierExc &D1)
{
    if (!sameDimensions(D1)){
        cerr << endl << __PRETTY_FUNCTION__ << " - Dimensions différentes !\n";
        exit(1);
    }

    DamierExc D(D1.L, D1.C,Max);
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            D.T[i][j] = T[i][j]+D1.T[i][j];

    return D;
}

ostream& operator<< (ostream& sortie, DamierExc& V)
{
    sortie << endl;
    for(int i=0; i<V.L; i++) {
        sortie << endl;
        for(int j=0; j<V.C; j++)
            sortie << V.T[i][j] << ", ";
    }

    return sortie;
}
