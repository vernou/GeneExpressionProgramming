#ifndef SETTINGPARSE_H
#define SETTINGPARSE_H

#include "../GEP/GEP.h"
#include "../GEP/Setting.h"

#include <string>

namespace GEP
{
//Read
bool SettingFromFile(GEP::Setting &setting);
bool DataFromFile(GeneticExpression &geneticExpression,std::string path);

//Write
/** \brief
 * Write min,avg,max fitness each iteration in csv file.
 * This file can be open with Excel to draw graphe.
 * Write also three better expressions in txt file.
 *
 * \param geneticExpression GEP proccess
 * \param result result of GEP proccess
 * \param file name of cvs and txt file
 *
 */
void ScoreResult(GeneticExpression &geneticExpression,Result& result,const std::string& file);

} // namespace GEP

#endif // SETTINGPARSE_H
