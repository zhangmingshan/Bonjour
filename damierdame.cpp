#include "damierdame.h"

DamierDame::DamierDame() :DamierExc(10,10,3,0)
{
    InitJeu();
}

void DamierDame::InitJeu()
{
    for(int l = 0;l<4;l++)
        for(int c = 1-l%2;c<C;c+=2)
            Set(l,c,1);

    for(int l = L-4;l<L;l++)
        for(int c = 1-l%2;c<C;c+=2)
            Set(l,c,2);
}
