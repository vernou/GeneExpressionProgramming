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
        return ele.value.operator_->Calcul(value1,value2);
        return 0;
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
