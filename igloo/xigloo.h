//          Copyright Joakim Karlsson & Kim Gräsman 2010-2013.
//          Copyright naoufel el abidi 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef XIGLOO_H
#define XIGLOO_H

// LINE_INFO macro
//
#ifndef LINE_INFO
#define LINE_INFO() __FILE__, __LINE__
#endif

#define IGLOO_VERSION "1.1.1"

#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <stack>
#include <list>
#include <memory>
#include <algorithm>
#include <iterator>


#include <igloo/external/snowhouse/snowhouse/snowhouse.h>

#include <igloo/core/contextbase.h>
#include <igloo/core/testresult.h>
#include <igloo/core/testresultfactory.h>
#include <igloo/core/testresults.h>
#include <igloo/core/testlistener.h>
#include <igloo/core/testlisteneraggregator.h>
#include <igloo/core/outputters/outputters.h>
#include <igloo/core/context.h>
#include <igloo/core/contextregistry.h>
#include <igloo/core/contextrunner.h>
#include <igloo/core/testrunner.h>
#include <igloo/core/contextprovider.h>
#include <igloo/core/testlisteners/testlisteners.h>

namespace igloo
{
using namespace snowhouse;
}


//
// These typedefs are used when registering contexts. For root
// contexts, these are the types available. When a context is
// registered it will redefine these so that any nested contexts
// defined within will know about its outer context. We can also
// use template specialization for contexts with the types here
// to get different behaviors for root and nested contexts.
//
typedef igloo::ContextWithAttribute<void> IGLOO_CURRENT_CONTEXT;

//
// This is the current root context (void to begin with).
//
typedef void IGLOO_ROOT_CONTEXT;


#include <igloo/core/xregistration.h>


// specs/describe macros
#define describe(contextName) \
XIGLOO_CONTEXT_REGISTRATION(contextName, GENERATE_NAME(Context) )

#define describe_only(contextName) \
XIGLOO_CONTEXT_REGISTRATION_ONLY(contextName, GENERATE_NAME(Context))

#define describe_skip(contextName) \
XIGLOO_CONTEXT_REGISTRATION_SKIP(contextName, GENERATE_NAME(Context))

#define it(specName) \
XIGLOO_SPEC_REGISTRATION(specName,GENERATE_NAME(Spec))

#define it_skip(specName) \
XIGLOO_SPEC_REGISTRATION_SKIP(specName,GENERATE_NAME(Spec))

#define it_only(specName) \
XIGLOO_SPEC_REGISTRATION_ONLY(specName,GENERATE_NAME(Spec))

#define description_attribute(attributeName, attributeValue) \
XIGLOO_CONTEXT_ATTRIBUTE_REGISTRATION(attributeName, attributeValue)

#if 0
//disable it for now
// Behavior aliases
#define When(contextName) \
XIGLOO_CONTEXT_REGISTRATION(contextName,GENERATE_NAME(Context) )

#define When_Only(contextName) \
XIGLOO_CONTEXT_REGISTRATION_ONLY(contextName,GENERATE_NAME(Context) )

#define When_Skip(contextName) \
XIGLOO_CONTEXT_REGISTRATION_SKIP(contextName,GENERATE_NAME(Context) )

#define Then(specName) \
XIGLOO_SPEC_REGISTRATION(specName,GENERATE_NAME(Spec))

#define Then_Skip(specName) \
XIGLOO_SPEC_REGISTRATION_SKIP(specName,GENERATE_NAME(Spec))

#define Then_Only(specName) \
XIGLOO_SPEC_REGISTRATION_ONLY(specName,GENERATE_NAME(Spec))

#define scenario_attribute(attributeName, attributeValue) \
XIGLOO_CONTEXT_ATTRIBUTE_REGISTRATION(attributeName, attributeValue)
#endif


#endif
