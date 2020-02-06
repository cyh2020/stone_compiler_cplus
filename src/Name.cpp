#include "Name.h"
#include <iostream>
#include "derivedTokens.h"
#include<ASTLeaf.h>
#include<string>
using std::string;

Name::Name(Token* t):ASTLeaf(t)
{
    //ctor
}

Name::~Name()
{
    //dtor
}

string Name::name(){
    return ((IdToken*)get_token())->getText();
    }

ReturnType* Name::eval(Environment& env) {
    ReturnType* value = env.get(name());
    if (value == nullptr)
        throw "undefined name: " + name();
    else
        return value;
}
