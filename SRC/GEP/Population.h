#ifndef POPULATION_H
#define POPULATION_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <vector>
#include "Expression.h"
#include "Setting.h"

namespace GEP
{
////////////////////////////////////////////////////////////
/// \brief Population is all expressions.
///  This class is used to evolve population.
///  First generation is ramdon expressions.
///  Next generations are expressions who are crossed and mutated.
////////////////////////////////////////////////////////////
class Population
{
public:
    Population(std::vector<Expression> &_trees,Setting &_setting);
    ~Population();

    void FirstGeneration();
    void NextGeneration();
    void ImproveConstante();

    void Sort();
    void InitializeTrees();

    void Crossing(Expression &child,const Expression &mother,const Expression &father);
    void Mutation(Expression &child);


public :
    std::vector<Expression>   &expressions;
    Setting &setting;

    unsigned int tail;
    unsigned int head;
    unsigned int size_tree;

    unsigned int nb_parent; //Number of parents dead each generation

private :
    bool sort = false;
};

} // namespace GEP

#endif // POPULATION_H
