//
// This is an implementation of the example on igloo website
// http://igloo-testing.org/
//
/////////////////////////////////////////////////////////////


#include "stdafx.h"
#include <iostream>
#include <string>
#include <igloo/igloo_alt.h>

using namespace igloo;
using namespace std;


#define LINE_INFO() __FILE__, __LINE__

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
    }
    void Switch()
    {
        effect = effect == Clean ? Distorted : Clean;
    }
    MyEnum getEffect()
    {
        return effect;
    }

};

static Fuzzbox nullFuzz("NULL FUZZ");
class Guitar
{
public:
    Fuzzbox* mfuzzBox;
    Guitar()
    {
        //cout << "in Guitar::Guitar(): " << this << endl;
    }
    void AddEffect(Fuzzbox& fuzzbox)
    {
        mfuzzBox = &fuzzbox;
        // cout << "in Guitar::AddEffect: " << this << " " <<  endl;

    }
    MyEnum Sound()
    {
        //cout << "in Guitar::Sound: " << this   << endl;
        return mfuzzBox->getEffect();
    }

};



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
            //cout << "in in_distorted_mode::sounds_clean_when_I_switch_the_fuzzbox" << endl;
            Parent().fuzzbox.Switch();
            Assert::That(Parent().guitar.Sound(), Equals(Clean), LINE_INFO());
        }
        It(sounds_clean_when_I_switch_the_fuzzbox_1)
        {
            //cout << "in in_distorted_mode::sounds_clean_when_I_switch_the_fuzzbox_2" << endl;
            Parent().fuzzbox.Switch();
            Assert::That(Parent().guitar.Sound(), Equals(Clean), LINE_INFO());
        }
    };

    Fuzzbox fuzzbox;
    Guitar guitar;
};


