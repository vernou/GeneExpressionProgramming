#include "Setting.h"
#include "../GEP_PARSE/Convert.h"
#include "../GEP_PARSE/ParserCSV.h"

namespace GEP
{

Setting::Setting()
{
    NbVariable = 7;
    MaxIteration = 200;
    NbIterationToImproveConstante = 200;
    NbTree = 20;
    HeaderSize = 5;
    PorCentDead = 70;
    ProbaMutation = 10;
    Cmax = 10.f;
    Cmin = -10.f;
    Cstep = 5.f;

    operators.push_back(Addition());
    operators.push_back(Multiplication());
    operators.push_back(Division());
}

} // namespace GEP
