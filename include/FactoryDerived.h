#ifndef FactoryDerived_H
#define FactoryDerived_H


#include <list>

#include <ASTNode.h>


#include "PrimaryExpr.h"
#include "Name.h"
#include "StringLiteral.h"
#include "NumberLiteral.h"
#include "Factory.h"
#include "Token.h"
#include "BlockStmnt.h"
using std::list;
#include "iostream"
#include "ordinary.h"
using std::cout;
using std::endl;


template <typename clazz>
class FactoryDerived:public Factory{
    public:
        ASTNode* make(list<ASTNode*> &c){
//            cout<<"A Node IS MAKING"<<endl;
            return new clazz(c);
        }
};



template <>
class FactoryDerived<NumberLiteral>:public Factory{
    public:
        ASTNode* make_atoken(Token* &c){
//            cout<<c->getText()<<"A NUMBER IS MAKING"<<endl;
            return new NumberLiteral(c);
        }
};

template <>
class FactoryDerived<Name>:public Factory{
    public:
        ASTNode* make_atoken(Token* &c){
//            cout<<c->getText()<<"A NAME IS MAKING"<<endl;
            return new Name(c);
        }
};

template <>
class FactoryDerived<StringLiteral>:public Factory{
    public:
        ASTNode* make_atoken(Token* &c){
//            cout<<c->getText()<<"A String IS MAKING"<<endl;
            return new StringLiteral(c);
        }
};

template <>
class FactoryDerived<BlockStmnt>:public Factory{
    public:
        ASTNode* make(list<ASTNode*> &c){
//            cout<<c->getText()<<"A BlockStmnt IS MAKING"<<endl;

//            for (list<ASTNode*>::iterator iter=c.begin();iter!=c.end();iter++)
//            {
//                cout<< *iter <<endl;
//            }

            return new BlockStmnt(c);
        }
};

template <>
class FactoryDerived<PrimaryExpr>:public Factory{
    public:
        ASTNode* make(list<ASTNode*> &c){
//            std::cout<<"A PrimaryExpr IS MAKING"<<std::endl;
            if (c.size() != 1){
                std::cout<<"more than one"<<std::endl;
            }


            return (c.size() == 1) ? c.front() : new PrimaryExpr(c);
//            return new PrimaryExpr(c);
        }
};

template <>
class FactoryDerived<ordinary>:public Factory{
    public:
        ASTNode* make(list<ASTNode*> &c){//c disappear quickly //c.front is value
//            cout<<"A ordinary Node IS MAKING"<<endl;
            if (c.size() == 1){
                return c.front();
            }
            else
                return new ASTList(c);
        }
};

//
#endif // FactoryDerived_H
