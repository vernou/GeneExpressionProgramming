////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <iostream>
#include <sstream>
#include "GEP/GEP.h"
#include "GEP/Error.h"
#include "GEP_TEST/TestGEP.h"
#include "GEP_PARSE/SettingParse.h"
#include "GEP_PARSE/Convert.h"
#include "GEP_PARSE/ParserCSV.h"

using namespace std;
using namespace GEP;

void DisplayManual()
{
        cout << "To use this command => gep [-r] <file_data.csv>" << endl;
        cout << "Description of CSV data file :" << endl;
        cout << "\t The number of column in row must be same." << endl;
        cout << "\t First column is result of equation." << endl;
        cout << "\t Other column are variables' value." << endl;
        cout << "\t The separator is ';'." << endl;
}

int main(int argc, char **argv)
{
    RunTestUnitaireGEP();
    ///Check command and options
    int argi = 1;
    bool with_result = false;
    if(argc==1)
    {
        DisplayManual();
        return 0;
    }
    if(string(argv[argi])=="-r")
    {
        with_result = true;
        argi++;
        if(argc<3)
        {
            DisplayManual();
            return 0;
        }
    }
    string path_file = argv[argi];

    ///Load setting, operator and data
    Setting setting;
    if(!SettingFromFile(setting))
    {
        Error::FatalError("Setting Load from Setting.csv");
    }
    GeneticExpression geneticExpression(setting);
    cout << "Setting Load!" << endl;

    if(!DataFromFile(geneticExpression,path_file))
    {
        Error::FatalError("Data Load from file "+path_file);
    }
    cout << "Data Load!" << endl << endl << endl;

    ///Run programn
    if(with_result)
    {
        Result result(setting.MaxIteration+setting.NbIterationToImproveConstante);
        geneticExpression.RunScoreResult(result);
        //DisplayResult(result);

        ScoreResult(geneticExpression,result,"Result");
    }
    else
    {
        geneticExpression.Run();
    }

    geneticExpression.DisplayNbBetterExpressions(3);
    return 0;
}
