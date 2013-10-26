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
std::string ExpressionToString(Expression &expression)
{
    std::ostringstream os;
    for(auto element:expression.expression)
    {
        os<<ElementToString(element)<<"|";
    }
    return os.str();
}

////////////////////////////////////////////////////////////
void DisplayExpression(Expression &expression)
{
    std::cout<<ExpressionToString(expression);
    std::cout<<""<<std::endl;
}

////////////////////////////////////////////////////////////
void DisplayExpressionMath(Expression &expression)
{
    std::cout<<ExpressionMathToString(expression);
    std::cout<<std::endl;
}
////////////////////////////////////////////////////////////
std::string ExpressionMathToString(Expression &expression)
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
std::string ElementToString(Element &element)
{
    std::ostringstream os;
    switch(element.type)
    {
    case Element::CONSTANTE :
        os<<element.value.constante;
        return os.str();
    case Element::VARIABLE  :
        return std::string()+static_cast<char>((element.value.variable)+'A');
    case Element::OPERATOR :
        os<<element.value.operator_->sign;
        return os.str();;
    }
    return "Uk";
}

} // namespace GEP
