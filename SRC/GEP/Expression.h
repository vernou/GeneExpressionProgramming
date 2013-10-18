#ifndef TREE_H
#define TREE_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <vector>
#include "Node.h"
#include "TestData.h"


namespace GEP
{
////////////////////////////////////////////////////////////
/// \brief Expression is array element. A expression create
/// tree to calculate fitness. Fitness is validation of expression.
/// Perfect expression has fitness = 0.
///
////////////////////////////////////////////////////////////
class Expression
{
public:
    /////////////////////////////////////////////////
    /// \brief Used to sort expression from them fitness
    ///
    /// \param lhs expression in left
    /// \param rhs expression in right
    /// \return bool true if lhs.fitness < rhs.fitness, else false
    ///
    /////////////////////////////////////////////////
    friend bool operator < (const Expression & lhs, const Expression & rhs)
    {
        return (lhs.fitness < rhs.fitness ? true : false);
    }

public:
    /////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    /////////////////////////////////////////////////
    Expression();

    /////////////////////////////////////////////////
    /// \brief Constructor from expression
    ///
    /////////////////////////////////////////////////
    Expression(std::vector<Element> _expression);


    /////////////////////////////////////////////////
    /// \brief  Add element in expression
    ///
    /// \param element element is add in last position in expression
    ///
    /////////////////////////////////////////////////
    void Add(Element element);

    /////////////////////////////////////////////////
    /// \brief Clear expression and tree
    ///
    /////////////////////////////////////////////////
    void Clear();

    /////////////////////////////////////////////////
    /// \brief Initialize tree and fitness(0)
    ///
    /////////////////////////////////////////////////
    void Initialize();

    /////////////////////////////////////////////////
    /// \brief Calcule fitness from data
    /// After fitness = old_fitness+calcul_fitness
    ///
    /// \param testData data to calcul fitness
    ///
    /////////////////////////////////////////////////
    void RunTest(TestData &testData);


public:
    std::vector<Element>    expression;             ///< GEP is array of element
    PtrNode                 root    = nullptr;
    float                   fitness = 0;
};

}// namespace GEP
#endif // TREE_H
