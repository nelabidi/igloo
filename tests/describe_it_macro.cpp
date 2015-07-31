
#include <tests/igloo_self_test.h>
#include <igloo/xigloo.h>
using namespace igloo;

namespace {

describe("an entity")
{
    bool its_true;

    void SetUp()
    {
        its_true = true;
    }

    it("should do something")
    {
        Assert::That(its_true, IsTrue());
    }

    describe("a more detailed description")
    {
        void SetUp()
        {
            Parent().its_true = false;
        }

        it("should do something")
        {
            Assert::That(Parent().its_true, IsFalse());
        }

        describe("even more nesting with direct access to root")
        {
            void SetUp()
            {
                Root().its_true = true;
            }

            it("should have direct access to the root context")
            {
                Assert::That(Root().its_true, IsTrue());
            }
        };
    };
};

} // end namespace

