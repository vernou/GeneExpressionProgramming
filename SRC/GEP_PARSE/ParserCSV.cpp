#include "ParserCSV.h"
#include <sstream>

using namespace std;

void csvWriteFile(vector<vector<string>> &record, const string& file, char delimiter)
{
    vector<string> row;
    string line;
    ofstream out(file);
    if (out.fail())
    {
        cout << "File not found" <<endl;
        return ;
    }
    for(auto row:record)
    {
        for(unsigned int i=0;i<row.size()-1;i++)
            out<<row[i]<<delimiter;
        out<<row[row.size()-1];
        out<<line<<endl;
    }

}

void csvReadFile(vector<vector<string>> &record, const string& file, char delimiter)
{
    vector<string> row;
    string line;
    ifstream in(file);
    if (in.fail())
    {
        cout << "File not found" <<endl;
        return ;
    }

    while(getline(in, line)  && in.good() )
    {
        csvLinePopulate(row, line, delimiter);
        record.push_back(row);
    }
    in.close();
}

void csvLinePopulate(vector<string> &record, const string& line, char delimiter)
{
    int linepos=0;
    int inquotes=false;
    char c;
    int linemax=line.length();
    string curstring;
    record.clear();

    while(line[linepos]!=0 && linepos < linemax)
    {

        c = line[linepos];

        if (!inquotes && curstring.length()==0 && c=='"')
        {
            //beginquotechar
            inquotes=true;
        }
        else if (inquotes && c=='"')
        {
            //quotechar
            if ( (linepos+1 <linemax) && (line[linepos+1]=='"') )
            {
                //encountered 2 double quotes in a row (resolves to 1 double quote)
                curstring.push_back(c);
                linepos++;
            }
            else
            {
                //endquotechar
                inquotes=false;
            }
        }
        else if (!inquotes && c==delimiter)
        {
            //end of field
            record.push_back( curstring );
            curstring="";
        }
        else if (!inquotes && (c=='\r' || c=='\n') )
        {
            record.push_back( curstring );
            return;
        }
        else
        {
            curstring.push_back(c);
        }
        linepos++;
    }
    record.push_back( curstring );
    return;
}

void DisplayCSV(vector<vector<string>> &record)
{
    for(auto row:record)
    {
        for(auto ele:row)
        {
            cout<<ele<<endl;
        }
        cout<<"Fin de ligne"<<endl;
    }
}
