#ifndef SETTING_H_INCLUDED
#define SETTING_H_INCLUDED

#include <vector>
#include "Operator.h"

namespace GEP
{

struct Setting
{
    //Number of variable in datas
    int NbVariable;
    //Max iteration to evolut population
    int MaxIteration;
    //Number of iteration to improve only constante
    int NbIterationToImproveConstante;
    //Number of expression or tree who evolve each generation
    int NbTree;
    //Size of header
    int HeaderSize;
    //Por cent of expression who will replace by other expression
    int PorCentDead;
    //Probility element is switch in child
    int ProbaMutation;
    //Value minimun of random constante
    float Cmin;
    //Value maximun of random constante
    float Cmax;
    //Step improve constante
    float Cstep;
    //List of operators
    std::vector<Operator>   operators;
};

void DefaultSetting(GEP::Setting &setting);

} // namespace GEP

#endif // SETTING_H_INCLUDED
