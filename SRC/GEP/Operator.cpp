#include "Operator.h"
#include <cmath>
#include <limits>

namespace GEP
{

float Add(float a,float b)
{
    return a+b;
}

float Mul(float a,float b)
{
    return a*b;
}

float Div(float a,float b)
{
    if(b==0) return std::numeric_limits<float>::max();
    else return a / b;
}

Operator Addition()
{
    Operator ope;
    ope.nbParameter = 2;
    ope.sign = '+';
    ope.Calcul = &Add;
    return ope;
}

Operator Multiplication()
{
    Operator ope;
    ope.nbParameter = 2;
    ope.sign = '*';
    ope.Calcul = &Mul;
    return ope;
}

Operator Division()
{
    Operator ope;
    ope.nbParameter = 2;
    ope.sign = '/';
    ope.Calcul = &Div;
    return ope;
}

Operator Power()
{
    Operator ope;
    ope.nbParameter = 2;
    ope.sign = '^';
    ope.Calcul = &powf;
    return ope;
}

} // namespace GEP
