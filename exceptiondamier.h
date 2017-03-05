#ifndef EXCEPTIONDAMIER_H
#define EXCEPTIONDAMIER_H

#include <iostream>
#include <sstream>
#include <exception>
using namespace std;

class borne: public exception
{
public:
    borne(int x, int max,string filename, string fctname) throw();
    virtual const char* what() const throw();
private:
    int X;
    int Vm;
    string Answer;
    string FileName;
    string FctName;
};

#endif // EXCEPTIONDAMIER_H

