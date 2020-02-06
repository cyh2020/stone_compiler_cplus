#include "StringLiteral.h"
#include "ReturnTypeString.h"

StringLiteral::StringLiteral(Token* t):ASTLeaf(t)
{
    //ctor
}

StringLiteral::~StringLiteral()
{
    //dtor
}

string StringLiteral::value(){
    return get_token()->getText();
}

ReturnType*  StringLiteral::eval(Environment& e) {
    ReturnTypeString* s = (ReturnTypeString*)new ReturnTypeString(StringLiteral::value());
    return s;
}
