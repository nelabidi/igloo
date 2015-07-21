//
// main.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>
#include <igloo/igloo_alt.h>

using namespace std;
using namespace igloo;


struct MyListnner : public TestListener
{


    virtual void TestRunStarting()
    {
        cout << ">TestRunStarting..." << endl;
    }

    virtual void TestRunEnded(const TestResults& results)
    {
        cout << ">TestRunEnded..." << endl;
    }

    virtual void ContextRunStarting(const ContextBase& context)
    {
        cout << ">>ContextRunStarting: Context: " << context.Name() << endl;
    }

    virtual void ContextRunEnded(const ContextBase& context)
    {
        cout << ">>ContextRunEnded: Context: " << context.Name() << endl;
    }

    virtual void SpecRunStarting(const ContextBase& context, const std::string& specName)
    {
        cout << ">>>SpecRunStarting: SpecName: " << specName << endl;
    }

    virtual void SpecSucceeded(const ContextBase& context, const std::string& specName)
    {
    }

    virtual void SpecFailed(const ContextBase& context, const std::string& specName)
    {
    }

};

int main(int argc, char *argv[])
{
    //Set Visual Studio output
    VisualStudioResultsOutput output;
    TestRunner runner(output);

    //add our listener
    MyListnner ls;
    runner.AddListener(&ls);
    //run all tests
    return runner.Run();




}