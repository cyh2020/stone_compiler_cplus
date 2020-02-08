#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <Postfix.h>
#include <ASTList.h>
#include <ASTNode.h>
#include <string>
using std::string;

class Arguments : public Postfix
{
    public:
        Arguments(list<ASTNode*> c);
        virtual ~Arguments();

        int size();

    protected:

    private:
};

#endif // ARGUMENTS_H
