#ifndef RESULT_H
#define RESULT_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Population.h"

namespace GEP
{

/** \brief Result score min,avg,max fitness each iteration.
 */

class Result
{
public:
    Result(int nb_result);

    void ScoreStep(Population &population);

public:
    std::vector<float> min;
    std::vector<float> max;
    std::vector<float> avg;
};

} // namespace GEP

#endif // RESULT_H
