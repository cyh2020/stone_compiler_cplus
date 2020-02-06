#ifndef ASTNode_H
#define ASTNode_H

#include<string>
#include "Environment.h"
#include "ReturnType.h"
using std::string;

class ASTNode {
public:
    ASTNode();
    virtual ~ASTNode();

    virtual ASTNode* child(int i);
    virtual int numChildren();
    virtual string toString();
//        virtual Iterator<ASTNode> children();
    virtual string location();
    virtual ReturnType* eval(Environment& env);//abstract methods

protected:

private:
};

#endif // ASTNode_H
