#ifndef GENETICEXPRESSION_H
#define GENETICEXPRESSION_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <vector>
#include "Operator.h"
#include "Expression.h"
#include "Population.h"
#include "Result.h"
#include "Setting.h"

namespace GEP
{
////////////////////////////////////////////////////////////
/// \brief Main engine class to search expression
///
////////////////////////////////////////////////////////////
class GeneticExpression
{
public:
    GeneticExpression(Setting _setting);
    ~GeneticExpression();

    /////////////////////////////////////////////////
    /// \brief Add data in GEP
    /// This data is value of variable with result of expression that searched
    ///
    /// \param data_var Varaible
    /// \param
    /// \return
    ///
    /////////////////////////////////////////////////
    void addData(std::vector<float> data_var,int result);
    void Run();
    void RunScoreResult(Result &result);
    void DisplayExpressions();
    void DisplayNbBetterExpressions(int n,bool math_form=true);

private:
    void CalculFinessForTrees();

public :
    std::vector<Expression> trees;
    std::vector<Operator>   operators;

private:
    Setting                 setting;
    std::vector<TestData>   testData;
    Population              population;

    int                     nb_it_evolve;
    int                     nb_it_improve;
};

} // namespace GEP
#endif // GENETICEXPRESSION_H
