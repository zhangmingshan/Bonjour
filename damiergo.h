#ifndef DAMIERGO_H
#define DAMIERGO_H

#include "damierexc.h"

class DamierGo :public DamierExc
{
public:
    DamierGo();
protected:
    void InitJeu();
};

#endif // DAMIERGO_H
