#include "ReturnTypeString.h"

ReturnTypeString::ReturnTypeString()
{
    //ctor
}

ReturnTypeString::ReturnTypeString(string s)
{
    //ctor
    this->val = s;
}

ReturnTypeString::~ReturnTypeString()
{
    //dtor
}

string ReturnTypeString::returnValType()
{
    //ctor
    return "string";
}

string ReturnTypeString::returnVal()
{
    return this->val;
}
