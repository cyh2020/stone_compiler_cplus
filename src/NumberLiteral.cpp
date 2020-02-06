#include "NumberLiteral.h"
#include "derivedTokens.h"
#include "ReturnTypeInt.h"

NumberLiteral::NumberLiteral(Token* t):ASTLeaf(t)
{
    //ctor
}

NumberLiteral::~NumberLiteral()
{
    //dtor
}

int NumberLiteral::value(){
    return ((NumToken*)get_token())->getNumber();
}

ReturnType* NumberLiteral::eval(Environment& e) {
    ReturnTypeInt* s = (ReturnTypeInt*)new ReturnTypeInt(NumberLiteral::value());
    return s;
};
