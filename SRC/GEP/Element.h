#ifndef ELEMENT_H
#define ELEMENT_H


namespace GEP
{
////////////////////////////////////////////////////////////
/// \brief It is element in expression(operator, variable, constante)
////////////////////////////////////////////////////////////
struct Element
{
    enum Type
    {
        CONSTANTE,
        OPERATOR,
        VARIABLE
    };

    enum Operator
    {
        PLUS  ,
        MINUS ,
        MULT  ,
        DIVI  ,
        COUNT ,     //Operator under are ignored
        POW   ,
        EXP   ,
    };

    union Value
    {
        Operator    operator_;
        float       constante;
        int         variable;
    };

    Element(int variable):type(VARIABLE)
    {
        value.variable=variable;
    }
    Element(float constante):type(CONSTANTE)
    {
        value.constante=constante;
    }
    Element(Operator _operator):type(OPERATOR)
    {
        value.operator_=_operator;
    }

    Type type;
    Value value;
};

} // namespace GEP

#endif // ELEMENT_H
