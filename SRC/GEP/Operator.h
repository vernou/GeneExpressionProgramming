#ifndef OPERATOR_H
#define OPERATOR_H

namespace GEP
{
struct Operator
{
    int nbParameter;
    char sign;
    float (*Calcul)(float a,float b);
};

float Add(float a,float b);
float Mul(float a,float b);
float Div(float a,float b);

Operator Addition();
Operator Multiplication();
Operator Division();
} // namespace GEP

#endif // OPERATOR_H
