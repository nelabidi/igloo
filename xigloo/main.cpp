// xigloo.cpp : Defines the entry point for the console application.
//

// IglooSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
using namespace std;

#include <igloo/igloo_alt.h>
using namespace igloo;
#if 0
using namespace igloo;
using namespace std;
enum MyEnum
{
    Clean,
    Distorted,
};

class Fuzzbox
{
public:
    MyEnum effect;
    string name;
    Fuzzbox(string n = "none")
        : effect(Clean)
    {
        name = n;
        //cout << "in Fuzzbox::Fuzzbox() " << this << " : " << name << endl;
    }
    void Switch()
    {
        effect = effect == Clean ? Distorted : Clean;
        //cout << "in Fuzzbox::Switch: "  << this << " " << effect << endl;
    }
    MyEnum getEffect()
    {
        // cout << "in Fuzzbox::getEffect() " << this << endl;
        return effect;
    }

};

static Fuzzbox nullFuzz("NULL FUZZ");
class Guitar
{
public:
    //Fuzzbox empty;
    Fuzzbox* mfuzzBox;
    Guitar()
    //:
    //empty("EMPTY"),
    //mfuzzBox(Fuzzbox())
    {
        //cout << "in Guitar::Guitar(): " << this << endl;
    }
    void AddEffect(Fuzzbox& fuzzbox)
    {
        //mfuzzBox.getEffect();
        mfuzzBox = &fuzzbox;
        //mfuzzBox.getEffect();
        //cout << "in Guitar::AddEffect" << endl;
        // cout << "in Guitar::AddEffect: " << this << " " <<  endl;

    }
    MyEnum Sound()
    {
        //cout << "in Guitar::Sound: " << this   << endl;
        return mfuzzBox->getEffect();
    }

};

#define LINE_INFO() __FILE__, __LINE__

Describe(a_guitar_with_a_fuzzbox)
{
    void SetUp()
    {
        // cout << "in a_guitar_with_a_fuzzbox:: Setup" << endl;
        guitar.AddEffect(fuzzbox);
    }

    It(starts_in_clean_mode)
    {
        // cout << "in a_guitar_with_a_fuzzbox::starts_in_clean_mode" << endl;
        Assert::That(guitar.Sound(), Equals(Clean), LINE_INFO());
    }

    Describe(in_distorted_mode)
    {
        void SetUp()
        {
            //cout << "in a_guitar_with_a_fuzzbox::in_distorted_mode:: SetUp" << endl;
            Parent().fuzzbox.Switch();
        }

        It(sounds_distorted)
        {
            //cout << "in in_distorted_mode::sounds_distorted" << endl;
            Assert::That(Parent().guitar.Sound(), Equals(Distorted), LINE_INFO());
        }

        It(sounds_clean_when_I_switch_the_fuzzbox)
        {
            //cout << "in in_distorted_mode::sounds_clean_when_I_switch_the_fuzzbox" << endl;
            Parent().fuzzbox.Switch();
            Assert::That(Parent().guitar.Sound(), Equals(Clean), LINE_INFO());
        }
        It(sounds_clean_when_I_switch_the_fuzzbox_2)
        {
            //cout << "in in_distorted_mode::sounds_clean_when_I_switch_the_fuzzbox_2" << endl;
            Parent().fuzzbox.Switch();
            Assert::That(Parent().guitar.Sound(), Equals(Clean), LINE_INFO());
        }
    };

    Fuzzbox fuzzbox;
    Guitar guitar;
};
#endif
/*
Describe ("A suite name can have spaces in it for example")
{
    It("it's going to have expect function as an expectation/assertion")
    {

    }

};*/
/*
Describe(a_guitar_with_a_fuzzbox)
{
    It(starts_in_clean_mode)
    {
        // cout << "in a_guitar_with_a_fuzzbox::starts_in_clean_mode" << endl;
        //Assert::That(guitar.Sound(), Equals(Clean), LINE_INFO());
    };
};*/


/*
#define R(a,b)\
struct a {\
    a(){\
        str = b;\
    }\
    string str;\
 };

#define D(a) R(GENERATE_NAME(S),a)

D("Hello naoufel");*/


//R(GENERATE_NAME(S), "Hello");

struct MyListnner : public TestListener
{


    virtual void TestRunStarting()
    {
        //throw std::exception("The method or operation is not implemented.");
    }

    virtual void TestRunEnded(const TestResults& results)
    {
        //throw std::exception("The method or operation is not implemented.");
    }

    virtual void ContextRunStarting(const ContextBase& context)
    {
        cout << "ContextRunStarting: " << context.Name() << endl;
    }

    virtual void ContextRunEnded(const ContextBase& context)
    {
        //throw std::exception("The method or operation is not implemented.");
    }

    virtual void SpecRunStarting(const ContextBase& context, const std::string& specName)
    {
        //throw std::exception("The method or operation is not implemented.");
        cout << "SpecRunStarting: " << specName << endl;
    }

    virtual void SpecSucceeded(const ContextBase& context, const std::string& specName)
    {
        //throw std::exception("The method or operation is not implemented.");
    }

    virtual void SpecFailed(const ContextBase& context, const std::string& specName)
    {
        //throw std::exception("The method or operation is not implemented.");
    }

};

int main(int argc, char *argv[])
{
    //return TestRunner::RunAllTests(argc, argv);
    VisualStudioResultsOutput output;
    //XUnitResultsOutput output;
    TestRunner runner(output);
    MyListnner ls;
    runner.AddListener(&ls);

    Assert::That(true);

    return runner.Run();




}