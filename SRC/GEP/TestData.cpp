////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "TestData.h"
#include <cmath>
#include <limits>

namespace GEP
{
////////////////////////////////////////////////////////////
float Calcul(TestData & testData,PtrNode node)
{
    Element & ele = node->element;
    switch(ele.type)
    {
    case Element::CONSTANTE :
        return ele.value.constante;
    case Element::VARIABLE  :
        return testData.variable.at(ele.value.variable);
    case Element::OPERATOR  :
    {
        float value1 = Calcul(testData,node->left);
        float value2 = Calcul(testData,node->right);
        switch(ele.value.operator_)
        {
        case Element::PLUS  :
            return value1 + value2;
        case Element::MINUS :
            return value1 - value2;
        case Element::MULT  :
            return value1 * value2;
        case Element::DIVI  :
            if(value2==0) return std::numeric_limits<float>::max();
            else return value1 / value2;
        case Element::POW  :
            return pow(value1, value2);
        case Element::EXP  :
            return exp(value2);
        default :
            break;
        }
    }
    break;
    }
    return 0;
}

////////////////////////////////////////////////////////////
float CalculFitnessFrom(TestData & testData,PtrNode root)
{
    return std::abs(testData.result - Calcul(testData,root));
}

} // namespace GEP
