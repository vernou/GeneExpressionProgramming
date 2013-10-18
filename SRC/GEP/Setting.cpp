#include "Setting.h"
#include "../GEP_PARSE/Convert.h"
#include "../GEP_PARSE/ParserCSV.h"

namespace GEP
{

void DefaultSetting(GEP::Setting &setting)
{
    setting.NbVariable = 7;
    setting.MaxIteration = 200;
    setting.NbIterationToImproveConstante = 200;
    setting.NbTree = 100;
    setting.MaxTreeDeep = 10;
    setting.PorCentDead = 70;
    setting.ProbaMutation = 10;
    setting.Cmax = 10.f;
    setting.Cmin = -10.f;
    setting.Cstep = 5.f;
}

} // namespace GEP
