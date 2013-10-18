#ifndef PARSER_CSV_H_INCLUDED
#define PARSER_CSV_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


/*
http://www.zedwood.com/article/112/cpp-csv-parser
Source to code to read CSV. I make a lot of modification.
*/
void csvReadFile(vector<vector<string>> &record, const string& file, char delimiter);
void csvLinePopulate(vector<string> &record, const string& line, char delimiter);
void DisplayCSV(vector<vector<string>> &record);

//My function CSV to display result in tableur
void csvWriteFile(vector<vector<string>> &record, const string& file, char delimiter);


#endif // PARSER_CSV_H_INCLUDED
