////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Expression.h"
#include "Factory.h"
#include <iostream>
#include <cmath>
#include <limits>

namespace GEP
{
////////////////////////////////////////////////////////////
Expression::Expression()
{

}

////////////////////////////////////////////////////////////
Expression::Expression(std::vector<Element> _expression):expression(_expression)
{
    Initialize();
}

////////////////////////////////////////////////////////////
void Expression::Add(Element element)
{
    expression.push_back(element);
}

////////////////////////////////////////////////////////////
void Expression::Clear()
{
    expression.clear();
    root = nullptr;
}

////////////////////////////////////////////////////////////
void Expression::Initialize()
{
    fitness = 0;
    root = CreateTreeFromExpression(expression);
}

////////////////////////////////////////////////////////////
void Expression::RunTest(TestData &testData)
{
    fitness += CalculFitnessFrom(testData,root);
    //Some operator have weird result. Then verify result.
    if(!std::isnormal(fitness))
        fitness = std::numeric_limits<float>::max();
}

} // namespace GEP
