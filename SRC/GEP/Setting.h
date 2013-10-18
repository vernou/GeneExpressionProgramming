#ifndef SETTING_H_INCLUDED
#define SETTING_H_INCLUDED

//Value minimun of random constante
#define GEP_C_MIN                       -10.f
//Value maximun of random constante
#define GEP_C_MAX                       10.f
//Step improve constante
#define GEP_STEP_CONSTANTE              5.f

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
    //Deep max in tree
    int MaxTreeDeep;
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
};

void DefaultSetting(GEP::Setting &setting);

} // namespace GEP

#endif // SETTING_H_INCLUDED
