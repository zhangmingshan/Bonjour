#include "damierechec.h"

DamierEchec::DamierEchec():DamierExc(8,8,3,0)
{
    InitEchec();
}

void DamierEchec::InitEchec()
{
    DamierExc::Init(0);
}
