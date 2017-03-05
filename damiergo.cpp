#include "damiergo.h"

DamierGo::DamierGo():DamierExc(19,19,3,0)
{
    InitJeu();
}

void DamierGo::InitJeu()
{
    DamierExc::Init(0);
}
