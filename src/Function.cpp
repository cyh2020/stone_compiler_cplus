#include "Function.h"
#include <iostream>
Function::Function(ParameterList parameters, BlockStmnt body, Environment &env_define):parameters(parameters),body(body),env(&env_define)
{
    //ctor
//    std::cout<<"in Function creator"<<&env_define<<std::endl;
}

Function::~Function()
{
    //dtor
}

ParameterList* Function::get_parameters() { return &parameters; }
BlockStmnt* Function::get_body() { return &body; }
Environment* Function::get_Env() {
//    std::cout<<"in Function get_Env creator"<<env<<std::endl;
    return new NestedEnv(env);
}
string Function::toString() { return "<fun:>"; }
