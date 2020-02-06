#include "BinaryExpr.h"
#include<ASTNode.h>

#include "derivedTokens.h"
#include<Token.h>
#include<string>
#include "ReturnType.h"
#include "ReturnTypeInt.h"
#include "ReturnTypeString.h"
#include "Name.h"
#include <typeinfo>
using std::string;

BinaryExpr::BinaryExpr(list<ASTNode*> c):ASTList(c)
{
    //ctor
}

BinaryExpr::~BinaryExpr()
{
    //dtor
}

ASTNode* BinaryExpr::left(){ return child(0); }
string BinaryExpr::operator_func(){
    return ((IdToken*)((ASTLeaf*)child(1))->get_token())->getText();
}
ASTNode* BinaryExpr::right() { return child(2); }


ReturnType* BinaryExpr::eval(Environment& env) {
            string op = operator_func();
            if ("="==op) {//assign operation
                ReturnType* right = (BinaryExpr::right())->eval(env);
                return computeAssign(env, right);
            }
            else {//other operation like add divide
                ReturnType* left = (BinaryExpr::left())->eval(env);
                ReturnType* right = (BinaryExpr::right())->eval(env);
                return computeOp(left, op, right);
            }
        }

ReturnType* BinaryExpr::computeAssign(Environment& env, ReturnType* rvalue) {
            ASTNode* l = left();
            if (typeid(*l)== typeid(Name)) {//left is a valid variable
                env.put(((Name*)l)->name(), rvalue);
                return rvalue;
            }
            else
                throw "bad assignment";
        }

ReturnType* BinaryExpr::computeOp(ReturnType* left, string op, ReturnType* right) {
    if (left->returnValType() == "int" && right->returnValType() == "int") {//int op int
        int answer = computeNumber(((ReturnTypeInt*)left)->returnVal(), op, ((ReturnTypeInt*)right)->returnVal());
        return new ReturnTypeInt(answer);
    }
    else//string op string
        if (op =="+"){
            string cat = ((ReturnTypeString*)left)->returnVal() + ((ReturnTypeString*)right)->returnVal();
            return new ReturnTypeString(cat);
        }
//                else if (op=="==") {
//                    if (left == null)
//                        return right == null ? TRUE : FALSE;
//                    else
//                        return left.equals(right) ? TRUE : FALSE;
//                }
        else
            throw "bad type";
}

int BinaryExpr::computeNumber(int left, string op, int right) {
    int a = left;
    int b = right;
    if (op == "+")
        return a + b;
    else if (op=="-")
        return a - b;
    else if (op=="*")
        return a * b;
    else if (op=="/")
        return a / b;
    else if (op=="%")
        return a % b;
    else if (op=="==")
        return a == b ? 1 : 0;
    else if (op==">")
        return a > b ? 1 : 0;
    else if (op=="<")
        return a < b ? 1 : 0;
    else
        throw "bad operator";
}


