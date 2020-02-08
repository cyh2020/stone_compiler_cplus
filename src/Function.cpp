#include "Function.h"

Function::Function(ParameterList parameters, BlockStmnt body, Environment env):parameters(parameters),body(body),env(env)
{
    //ctor
}

Function::~Function()
{
    //dtor
}

ParameterList* Function::get_parameters() { return &parameters; }
BlockStmnt* Function::get_body() { return &body; }
Environment* Function::get_Env() { return new NestedEnv(env); }
string Function::toString() { return "<fun:>"; }
