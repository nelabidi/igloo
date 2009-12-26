#ifndef _ASSERT_H
#define	_ASSERT_H
#include <stack>
#include "itoken.h"
#include "operators/operator.h"
#include "constraints/constraint.h"
#include "operators/notoperator.h"
#include "operators/andoperator.h"
#include "constraints/equaltoconstraint.h"
#include "constraints/greaterthanconstraint.h"
#include "constraints/strings/stringcontainingconstraint.h"
#include "constraints/strings/stringstartingwithconstraint.h"
#include "constraints/strings/stringendingwithconstraint.h"
#include "constraints/lessthanconstraint.h"
#include "expression.h"
#include "../is.h"

namespace igloo {

  class Assert {
  public:

    template <typename T>
    static void That(T actual, SyntaxBase& syntax)
    {
      if (!syntax.GetExpression().Evaluate(actual))
      {
        throw AssertionException(CreateErrorText(syntax.GetExpression(), actual));
      }
    }

    static void That(const char* actual, SyntaxBase& syntax)
    {
      return That<std::string > (std::string(actual), syntax);
    }

    static void That(bool& actual)
    {
      if (!actual)
      {
        throw AssertionException("Expected: true\nActual: false");
      }
    }

  private:
    template <typename T>
    static std::string CreateErrorText(const Expression& expression, const T& actual)
    {
      std::ostringstream str;
      str << "Expected: ";
      str << expression.GetExpectationText();
      str << std::endl;
      str << "Actual: " << actual;
      str << std::endl;

      return str.str();
    }
  };
}
#endif	/* _ASSERT_H */
