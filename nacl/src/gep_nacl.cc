// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ppapi/cpp/instance.h"
#include "ppapi/cpp/module.h"
#include "ppapi/cpp/var.h"

#include "Message.h"
#include "../../src/GEP/GEP.h"
#include "../../src/GEP_PARSE/ParserCSV.h"
#include "../../src/GEP_PARSE/Convert.h"


bool LoadDataFromCsvString(GEP::GeneticExpression &geneticExpression,const string &strData) 
{
    std::stringstream ss(strData);
    string line;
    while (std::getline(ss, line)) {
        vector<string> tmp;
        csvLinePopulate(tmp,line,';');
        line.clear();
            
        std::vector<float> variables;
        for(unsigned int j=1;j<tmp.size();j++)
        {
            float value = 0;
            if(!from_string(tmp[j],value))
                return false;
            variables.push_back(value);
        }
        float result = 0;
        if(!from_string(tmp[0],result))
            return false;
        geneticExpression.addData(variables,result);
    }

    return true;
}

class HelloTutorialInstance : public pp::Instance
{
public:
    explicit HelloTutorialInstance(PP_Instance instance)
        : pp::Instance(instance) {}
    virtual ~HelloTutorialInstance() {}
    
    void SendLog(string msg)
    {
        pp::Var var_reply(msg);
        PostMessage(var_reply);
    }
    
    GEP::GeneticExpression geneticExpression;
    
    virtual void HandleMessage(const pp::Var& var_message)
    {
        // Ignore the message if it is not a string.
        if (!var_message.is_string())
            return;
		
		Message message(var_message);
		if(message.type == Message::LOG)
		{
			SendLog(">>"+message.data);
		}
		else if(message.type == Message::DATA)
		{   
            geneticExpression.clearData();
            SendLog("Data Clear!!!");
            if(LoadDataFromCsvString(geneticExpression,message.data))
            {
                int data_size = geneticExpression.sizeData();
                SendLog("Data Load!!! "+to_string(data_size));
                /* Display data in log
                for(auto & testData:geneticExpression.getDatas())
                {
                    string data_str;
                    for(auto data:testData.variable)                    
                        data_str += to_string(data);
                    data_str += to_string(testData.result);
                    SendLog(data_str);
                }
                */
            }
            else
                SendLog("Fail Data Load!!!");
		}
        else if(message.type == Message::RUN)
        {
            SendLog("Begin Run");
            geneticExpression.Run();
            SendLog("End Run");
            
            for(int i=0; i<3; i++)
            {
                auto tree = geneticExpression.GetExpression(i);
                SendLog(ExpressionToString(tree));
                SendLog(ExpressionMathToString(tree));
                SendLog("Fitness = "+to_string(tree.fitness));
                SendLog("");
            }
        }
        else if(message.type == Message::ERROR)
        {
            SendLog("Some error is occurred");
        }
    }
};

class HelloTutorialModule : public pp::Module
{
public:
    HelloTutorialModule() : pp::Module() {}
    virtual ~HelloTutorialModule() {}

    virtual pp::Instance* CreateInstance(PP_Instance instance)
    {
        return new HelloTutorialInstance(instance);
    }
};

namespace pp
{

Module* CreateModule()
{
    return new HelloTutorialModule();
}

}  // namespace pp
