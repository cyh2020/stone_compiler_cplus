#ifndef POSTFIX_H
#define POSTFIX_H

#include <ASTList.h>
#include <ASTNode.h>
#include <string>

using std::string;


class Postfix : public ASTList
{
    public:
        Postfix(list<ASTNode*> c);
        virtual ~Postfix();

    protected:

    private:
};

#endif // POSTFIX_H
