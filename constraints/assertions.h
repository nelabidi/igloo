#ifndef _ASSERTIONS_H
#define	_ASSERTIONS_H
#include <stack>
#include "ioperator.h"
#include "logicaloperator.h"
#include "constraint.h"
#include "notoperator.h"
#include "equaltoconstraint.h"
#include "operatorstack.h"
#include "expression.h"
#include "is.h"

class Assert
{
public:

  template <typename T>
  static void That(T actual, Expression& constraint)
  {
    stack<bool> operatorResultsStack;

    IOperator* op;
    while ((op = constraint.PopOperator()) != NULL)
    {
      PerformOperation(op, actual, operatorResultsStack);
    }

    if (!operatorResultsStack.top())
    {
      throw AssertionException("WTF!?");
    }
  }

  static void That(bool& actual)
  {
    if (!actual)
    {
      throw AssertionException("Expected condition to be true");
    }
  }

private:
  template <typename T>
  static void PerformOperation(IOperator * op, T actual, stack<bool>& resultStack)
  {
    if (op->IsLogicalOperator())
    {
      LogicalOperator* logical = dynamic_cast<LogicalOperator*> (op);
      logical->Evaluate(resultStack);
    }
    else
    {
      Constraint<T>* constraint = dynamic_cast<Constraint<T>*> (op);
      resultStack.push(constraint->Evaluate(actual));
    }

    delete op;
  }
};

#endif	/* _ASSERTIONS_H */
