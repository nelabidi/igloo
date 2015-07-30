
//          Copyright Naoufel El Abidi 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifdef _MSC_VER
#pragma once
#endif

#ifndef XIGLOO_REGISTRATION_H
#define XIGLOO_REGISTRATION_H



#define XCONCAT_I(a,b) a ## b
#define XCONCAT(a,b) XCONCAT_I(a,b)
#ifdef __COUNTER__
//use counter macro for ids generation
#define GENERATE_NAME(x)  XCONCAT(x, XCONCAT(_,__COUNTER__))

#else
//if the compiler doesn't have counter macro use line instead
//NOTE: this may cause an error if 2 or more describe/it used in the same line
#define GENERATE_NAME(x)  XCONCAT(x, XCONCAT(_,__LINE__))

#endif


#define XIGLOO_PRIVATE_GENERATE_CONTEXTREGISTRAR(contextId,contextName,baseContextName) \
struct contextId; \
static struct ContextRegistrar_##contextId \
  { \
    const char * name = contextName;\
    ContextRegistrar_##contextId()\
    { \
        igloo::TestRunner::RegisterContext<igloo::ContextRunner<baseContextName, contextId> >(name, __FILE__, __LINE__);\
    } \
} contextId##_Registrar;


#define XIGLOO_CONTEXT_REGISTRATION(contextName,contextId) \
    XIGLOO_PRIVATE_GENERATE_CONTEXTREGISTRAR(contextId,contextName, void) \
struct contextId : public igloo::ContextProvider<contextId, IGLOO_CURRENT_CONTEXT, IGLOO_ROOT_CONTEXT, false, false>

#define XIGLOO_CONTEXT_REGISTRATION_ONLY(contextName,contextId) \
    XIGLOO_PRIVATE_GENERATE_CONTEXTREGISTRAR(contextId,contextName, void) \
struct contextId : public igloo::ContextProvider<contextId, IGLOO_CURRENT_CONTEXT, IGLOO_ROOT_CONTEXT, true, false>

#define XIGLOO_CONTEXT_REGISTRATION_SKIP(contextName,contextId) \
    XIGLOO_PRIVATE_GENERATE_CONTEXTREGISTRAR(contextId,contextName, void) \
struct contextId : public igloo::ContextProvider<contextId, IGLOO_CURRENT_CONTEXT, IGLOO_ROOT_CONTEXT, false, true>

#define XIGLOO_PARENT_CONTEXT_REGISTRATION(contextName,contextId) \
struct contextId : public igloo::ContextProvider<contextId, IGLOO_CURRENT_CONTEXT, IGLOO_ROOT_CONTEXT, false, false>

#define XIGLOO_SUBCONTEXT_REGISTRATION(contextId,contextName, baseContextName) \
    XIGLOO_PRIVATE_GENERATE_CONTEXTREGISTRAR(contextId,contextName, baseContextName) \
struct contextId : public baseContextName

#define XIGLOO_PRIVATE_SPEC_REGISTRATION(specId,specName, skip, only) \
struct SpecRegistrar_##specId \
  { \
  SpecRegistrar_##specId() \
    { \
    igloo::ContextRegistry<IGLOO_CURRENT_CONTEXT>::RegisterSpec(specName, &IGLOO_CURRENT_CONTEXT::specId, skip, only); \
    } \
    } SpecRegistrar_##specId; \
    virtual void specId()

#define XIGLOO_SPEC_REGISTRATION(specName,specId) \
    XIGLOO_PRIVATE_SPEC_REGISTRATION(specId,specName, false, false)

#define XIGLOO_SPEC_REGISTRATION_SKIP(specName,specId) \
    XIGLOO_PRIVATE_SPEC_REGISTRATION(specId,specName, true, false)

#define XIGLOO_SPEC_REGISTRATION_ONLY(specName,specId) \
    XIGLOO_PRIVATE_SPEC_REGISTRATION(specId,specName, false, true)

#define XIGLOO_CONTEXT_ATTRIBUTE_REGISTRATION(name, value) \
struct AttributeRegistrar_##IGLOO_CURRENT_CONTEXT \
    {\
    AttributeRegistrar_##IGLOO_CURRENT_CONTEXT()\
      {\
      igloo::ContextAttributeStorage<IGLOO_CURRENT_CONTEXT>::Set(name, value);\
      }\
    } AttributeRegistrar_##IGLOO_CURRENT_CONTEXT;

#endif


