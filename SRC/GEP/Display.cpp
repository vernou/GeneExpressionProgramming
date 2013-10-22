////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Display.h"
#include <iostream>
#include <sstream>

namespace GEP
{

void TreeToString(PtrNode node,std::ostringstream& os);

////////////////////////////////////////////////////////////
void DisplayExpression(Expression &expression)
{
    for(auto element:expression.expression)
    {
        std::cout<<ElementToString(element)<<"|";
    }
    std::cout<<""<<std::endl;
}

////////////////////////////////////////////////////////////
void DisplayExpressionMath(Expression &expression)
{
    std::cout<<ExpressionToString(expression);
    std::cout<<std::endl;
}

std::string ExpressionToString(Expression &expression)
{
    std::ostringstream os;
    TreeToString(expression.root,os);
    return os.str();
}

////////////////////////////////////////////////////////////
void TreeToString(PtrNode node,std::ostringstream& os)
{
    if(node==nullptr)
        return;
    if(node->element.type == Element::OPERATOR)
    {
        os<<'(';
        TreeToString(node->left,os);
        os<<ElementToString(node->element);
        TreeToString(node->right,os);
        os<<')';
    }
    else
        os<<ElementToString(node->element);
}

////////////////////////////////////////////////////////////
void DisplayResult(Result &result)
{
    for(unsigned int i=0;i<result.min.size();i++)
    {
        std::cout<<result.min[i]<<"\t"<<result.avg[i]<<"\t"<<result.max[i]<<std::endl;
    }
}

////////////////////////////////////////////////////////////
std::string ElementToString(Element &element)
{
    std::ostringstream os;
    switch(element.type)
    {
    case Element::CONSTANTE :
        os<<element.value.constante;
        return os.str();
    case Element::VARIABLE  :
        os<<element.value.variable;
        return "V"+os.str();
    case Element::OPERATOR :
        os<<element.value.operator_->sign;
        return os.str();;
    }
    return "Uk";
}

} // namespace GEP
