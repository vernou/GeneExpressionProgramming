////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "GeneticExpression.h"
#include "Factory.h"
#include "Display.h"
#include "Setting.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace GEP
{
////////////////////////////////////////////////////////////
GeneticExpression::GeneticExpression(Setting _setting):
    setting(_setting),population(setting),nb_it_evolve(0),nb_it_improve(0)
{
    srand(std::time(0));
}

////////////////////////////////////////////////////////////
GeneticExpression::~GeneticExpression()
{
    //dtor
}

////////////////////////////////////////////////////////////
void GeneticExpression::addData(std::vector<float> data_var,int result)
{
    if(setting.NbVariable == 0)
        setting.NbVariable = data_var.size();
    if((int)data_var.size() == setting.NbVariable)
        testData.push_back(TestData {data_var,result});
    else
        std::cout<<"Error GeneticExpression::addData => miss variable in data? "<<data_var.size()<<std::endl;
}

////////////////////////////////////////////////////////////
void GeneticExpression::Run()
{
    //1)Generate first population
    CreateFirstGeneration();
    //2)Evolve population
    RunNextGeneration(setting.MaxIteration);
    //3)Improve constante in population
    for(nb_it_improve=0; nb_it_improve<setting.NbIterationToImproveConstante; nb_it_improve++)
    {
        population.ImproveConstante();
        CalculFinessForTrees();
    }
    population.Sort();
}

////////////////////////////////////////////////////////////
void GeneticExpression::CreateFirstGeneration()
{
    population.FirstGeneration();
    CalculFinessForTrees();
    population.Sort();
}

////////////////////////////////////////////////////////////
void GeneticExpression::RunNextGeneration(int nbNextGeneration)
{
    int limit = std::min(setting.MaxIteration,nbNextGeneration+nb_it_evolve);
    for(; nb_it_evolve<limit; nb_it_evolve++)
    {
        population.NextGeneration();
        CalculFinessForTrees();
    }
    population.Sort();
}

////////////////////////////////////////////////////////////
void GeneticExpression::RunScoreResult(Result &result)
{
    //1)Generate first population
    population.FirstGeneration();
    CalculFinessForTrees();
    //2)Evolve population
    for(nb_it_evolve=0; nb_it_evolve<setting.MaxIteration; nb_it_evolve++)
    {
        population.NextGeneration();
        CalculFinessForTrees();
        result.ScoreStep(population);
    }
    //3)Improve constante in population
    for(int nb_it_improve=0; nb_it_improve<setting.NbIterationToImproveConstante; nb_it_improve++)
    {
        population.ImproveConstante();
        CalculFinessForTrees();
        result.ScoreStep(population);
    }
    population.Sort();
}

////////////////////////////////////////////////////////////
void GeneticExpression::CalculFinessForTrees()
{
    if(testData.size())
        for(auto &tree:population.expressions)
        {
            for(auto data:testData)
                tree.RunTest(data);
            tree.fitness/=testData.size();
        }
}

////////////////////////////////////////////////////////////
Expression &GeneticExpression::GetExpression(int i)
{
    return population.expressions[i];
}

} // namespace GEP
