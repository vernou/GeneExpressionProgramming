////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Factory.h"
#include <cstdlib>
#include <ctime>
#include <queue>

namespace GEP
{
////////////////////////////////////////////////////////////
void CreateRamdonExpression(Expression &expression,std::vector<Operator> &operators,int head,int tail,int nb_var,float c_max,float c_min)
{
    expression.Clear();
    int size_tree = tail+head;

    for(int i=0; i<size_tree; i++)
    {
        bool in_head = (i<head);
        expression.Add(RamdonElement(operators,nb_var,c_max,c_min,in_head));
    }

    expression.Initialize();
}

////////////////////////////////////////////////////////////
Element RamdonElement(std::vector<Operator> &operators,int nb_var,float c_max,float c_min,bool in_head)
{
    Element element(0);
    Element::Type type = RamdonType();
    //Tail can only take constante or variable
    if(!in_head && type == Element::OPERATOR)
        type = Element::CONSTANTE;

    if(type == Element::CONSTANTE)
    {
        float constante = RamdonConstante(c_max,c_min);
        element = Element(constante);
    }
    else if(type == Element::VARIABLE)
    {
        int n_var = RamdonVariable(nb_var);
        element = Element(n_var);
    }
    else if(type == Element::OPERATOR)
    {
        int rm_ope = RamdonVariable(operators.size());
        element = Element(&operators[rm_ope]);
    }
    return element;
}

////////////////////////////////////////////////////////////
PtrNode CreateTreeFromExpression(std::vector<Element> expression)
{
    //If expresion is empty, tree can not create
    if(expression.size())
    {
        PtrNode root;
        std::queue<PtrNode> fifo;

        //Initialize root
        root=PtrNode(new Node(expression[0]));
        //If root is not operator, it is finish
        if(expression[0].type == Element::Type::OPERATOR)
        {
            fifo.push(root);
            auto it = expression.begin(); //Cursor to element in expresion
            it++; //Begin is second element
            //Create tree, when fifo is empty to stop
            while(fifo.size()>0)
            {
                PtrNode ITnode(new Node(*it));
                Element &ele  = *it;
                //If element is operator, them is add in fifo
                if(ele.type == Element::Type::OPERATOR)
                    fifo.push(ITnode);
                //Add element in operator front of fifo
                if(fifo.front()->left == nullptr)
                    fifo.front()->left = ITnode;
                else
                {
                    fifo.front()->right = ITnode;
                    //Operator is full, it is removed of fifo
                    fifo.pop();
                }
                it++;
            }
        }
        return root;
    }
    else
        return nullptr;
}

////////////////////////////////////////////////////////////
Element::Type RamdonType()
{
    return static_cast<Element::Type> (rand()%3);
}

////////////////////////////////////////////////////////////
float RamdonConstante(float c_max,float c_min)
{
    return((static_cast<float>(rand())/static_cast<float>(RAND_MAX))*(c_max-c_min))-c_min;
}

////////////////////////////////////////////////////////////
int RamdonVariable(int nb_var)
{
    return (rand()%nb_var);
}

////////////////////////////////////////////////////////////
void RefineConstante(float &current,float step)
{
    current+=(step*RamdonConstante(1.f,-1.f));
}

} // namespace GEP
