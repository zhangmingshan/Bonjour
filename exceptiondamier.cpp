#include "exceptiondamier.h"

borne::borne(int x, int max,string filename, string fctname) throw()
{
    Vm = max, X = x, FileName = filename, FctName = fctname;

    Answer += "Borne = " + to_string(Vm) + "\n";
    Answer += "Valeur rejetee : " + to_string(X) + "\n";
    Answer += "Fichier : " + filename + "\n";
    Answer += "Fonction : " + fctname + "\n";
}

const char* borne::what() const throw()
{
    return Answer.c_str();
}

