#include "ReturnTypeInt.h"

ReturnTypeInt::ReturnTypeInt()
{
    //ctor
}

ReturnTypeInt::ReturnTypeInt(int num)
{
    //ctor
    this->val = num;
}

ReturnTypeInt::~ReturnTypeInt()
{
    //dtor
}

ReturnTypeInt::returnVal()
{
    return this->val;
}

string ReturnTypeInt::returnValType()
{
    return "int";
}
