////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Result.h"
#include "Setting.h"

namespace GEP
{
////////////////////////////////////////////////////////////
Result::Result(int nb_result)
{
    min.reserve(nb_result);
    max.reserve(nb_result);
    avg.reserve(nb_result);
}

////////////////////////////////////////////////////////////
void Result::ScoreStep(Population &population)
{
    population.Sort();
    int nb = population.nb_parent;
    max.push_back(population.expressions[nb-1].fitness);
    min.push_back(population.expressions[0].fitness);
    float avg = 0;
    for(int i =0;i<nb;i++)
        avg += population.expressions[i].fitness;
    avg /= nb;
    this->avg.push_back(avg);
}

} // namespace GEP
