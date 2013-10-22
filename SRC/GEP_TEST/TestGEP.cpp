#include "TestGEP.h"
#include <iostream>
#include "..\GEP\GEP.h"

using namespace std;

namespace GEP
{

void TestTree();

void RunTestUnitaireGEP()
{
    cout<<"GEP Test unitaire begin"<<endl;
    cout<<endl;
    TestTree();
    cout<<endl;
    cout<<"GEP Test unitaire end"<<endl;
}

void TestTree()
{
    cout << "Test tree" << endl;
    Operator addition = Addition();
    Operator multiplication = Multiplication();
    Operator division = Division();
    {
        Expression expression;
        expression.Add(Element(&multiplication));
        expression.Add(Element(&addition));
        expression.Add(Element(2.f));
        expression.Add(Element(3.f));
        expression.Add(Element(0));
        expression.Initialize();
        TestData testData;
        testData.variable.push_back(4.f);
        testData.result = 2;
        float fitness = CalculFitnessFrom(testData,expression.root);
        cout<<"Display Tree"<<endl;
        DisplayExpression(expression);
        cout << "Fitness want = 12   fitness result = " <<fitness<< endl;
    }
    {
        Expression expression;
        expression.Add(Element(&addition));
        expression.Add(Element(&multiplication));
        expression.Add(Element(&division));
        expression.Add(Element(2.f));
        expression.Add(Element(4.f));
        expression.Add(Element(1));
        expression.Add(Element(0));
        expression.Initialize();
        TestData testData;
        testData.variable.push_back(100.f);
        testData.variable.push_back(0.f);
        testData.result = 10;
        float fitness = CalculFitnessFrom(testData,expression.root);
        cout<<"Display Tree"<<endl;
        DisplayExpression(expression);
        cout << "Fitness want = 2   fitness result = " <<fitness<< endl;
    }
}

} // namespace GEP
