#include "SettingParse.h"
#include "ParserCSV.h"
#include "Convert.h"
#include "../GEP/Error.h"

namespace GEP
{
////////////////////////////////////////////////////////////
bool SettingFromFile(GEP::Setting &setting)
{
    vector<vector<string>> tmp;
    csvReadFile(tmp,"./Setting.csv",'\t');
    //Check if file is correctely load
    if(tmp.size()<9)
        return false;
    for(int i=0;i<9;i++)
        if(tmp[i].size()<2)
            return false;

    //Load setting
    setting.NbVariable = 0;
    from_string(tmp[0][1],setting.MaxIteration);
    from_string(tmp[1][1],setting.NbIterationToImproveConstante);
    from_string(tmp[2][1],setting.NbTree);
    from_string(tmp[3][1],setting.HeaderSize);
    from_string(tmp[4][1],setting.PorCentDead);
    from_string(tmp[5][1],setting.ProbaMutation);
    from_string(tmp[6][1],setting.Cmax);
    from_string(tmp[7][1],setting.Cmin);
    from_string(tmp[8][1],setting.Cstep);
    OperatorFrom(setting.operators,tmp[9][1]);
    return true;
}
////////////////////////////////////////////////////////////
bool OperatorFrom(std::vector<GEP::Operator> &operators,std::string select)
{
    operators.clear();
    std::string::iterator it;
    for(it = select.begin();it != select.end();it++)
    {
        switch(*it)
        {
        case '+' :
            operators.push_back(Addition());
            break;
        case '*' :
            operators.push_back(Multiplication());
            break;
        case '/' :
            operators.push_back(Division());
            break;
        case '^' :
            operators.push_back(Power());
            break;
        default :
            Error::FatalError("Unknow Operator, "+*it);
            break;
        }
    }
    return true;
}
////////////////////////////////////////////////////////////
bool DataFromFile(GeneticExpression &geneticExpression,std::string path)
{
    vector<vector<string>> tmp;
    csvReadFile(tmp,path,';');
    if(tmp.size()==0)
    {
        return false;
    }
    for(unsigned int i=0; i<tmp.size(); i++)
    {
        std::vector<float> variables;
        for(unsigned int j=1;j<tmp[i].size();j++)
        {
            float value = 0;
            from_string(tmp[i][j],value);
            variables.push_back(value);
        }
        float result = 0;
        from_string(tmp[i][0],result);
        geneticExpression.addData(variables,result);
    }
    return true;
}
////////////////////////////////////////////////////////////
void ScoreResult(GeneticExpression &geneticExpression,Result& result,const string& file)
{
    ///Write result in CSV file
    //Excel, 255 points max
    unsigned int next = result.min.size()/250;
    if(next==0)
        next=1;
    vector<vector<string>> score(1);
    score[0] = {"","max","avg","min"};
    unsigned int i;
    for(i=0;i<result.min.size();i+=next)
    {
        vector<string> row;
        row.push_back(IntToString(i));
        row.push_back(FloatToString(result.max[i]));
        row.push_back(FloatToString(result.avg[i]));
        row.push_back(FloatToString(result.min[i]));
        score.push_back(row);
    }
    //For final point
    if(i>=result.min.size())
    {
        i=result.min.size()-1;
        vector<string> row;
        row.push_back(IntToString(i));
        row.push_back(FloatToString(result.max[i]));
        row.push_back(FloatToString(result.avg[i]));
        row.push_back(FloatToString(result.min[i]));
        score.push_back(row);
    }
    csvWriteFile(score,file+".csv",';');

    ///Write better expression in texte file
    ofstream out(file+".txt");
    if (out.fail())
    {
        cout << "File not found" <<endl;
        return ;
    }
    for(unsigned int i=0;i<3;i++)
    {
        Expression &exp = geneticExpression.GetExpression(i);
        out<<ExpressionToString(exp);
        out<<endl;
        out<<exp.fitness;
        out<<endl;
    }
}

} // namespace GEP
