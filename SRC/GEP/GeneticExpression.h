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
    GeneticExpression();
    GeneticExpression(Setting _setting);
    ~GeneticExpression();

    /////////////////////////////////////////////////
    /// \brief Add data in GEP
    /// This data is value of variable with result of expression that searched.
    /// To accept the data, the data need be same array size.
    /// Size used like reference, is the first data entry.
    ///
    /// \param data_var Varaible
    /// \param result Resultat of epresion with variables' value
    /// \return true if data is accepted, false data is ignored
    ///
    /////////////////////////////////////////////////
    bool addData(std::vector<float> data_var,float result);

    /////////////////////////////////////////////////
    /// \brief Return data array
    ///
    /////////////////////////////////////////////////
    std::vector<TestData> getDatas();

    /////////////////////////////////////////////////
    /// \brief Clear all data
    ///
    /////////////////////////////////////////////////
    void clearData();

    /////////////////////////////////////////////////
    /// \brief Return the number of data samples
    ///
    /////////////////////////////////////////////////
    int sizeData();

    /////////////////////////////////////////////////
    /// \brief Run to search best expression
    ///
    /////////////////////////////////////////////////
    void Run();

    /////////////////////////////////////////////////
    /// \brief Run to search best expression and to fill up the result
    ///
    /////////////////////////////////////////////////
    void RunScoreResult(Result &result);

    /////////////////////////////////////////////////
    /// \brief Return expression from population.
    /// Population containt the expression, this method is access to Expression for
    /// display and compar the resultat of GEP.
    ///
    /// \param i Index of expression in the population.
    /// \return Expression in population at the index i.
    ///
    /////////////////////////////////////////////////
    void CreateFirstGeneration();

    void RunNextGeneration(int nbNextGeneration);

    /////////////////////////////////////////////////
    /// \brief Return expression from population.
    /// Population containt the expression, this method is access to Expression for
    /// display and compar the resultat of GEP.
    ///
    /// \param i Index of expression in the population.
    /// \return Expression in population at the index i.
    ///
    /////////////////////////////////////////////////
    Expression &GetExpression(int i);

private:
    void CalculFinessForTrees();

private:
    Setting                 setting;
    std::vector<TestData>   testData;
    Population              population;

    int                     nb_it_evolve;
    int                     nb_it_improve;
};

} // namespace GEP
#endif // GENETICEXPRESSION_H
