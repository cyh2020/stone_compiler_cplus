#ifndef RETURNTYPE_H
#define RETURNTYPE_H

#include <string>
using std::string;

class ReturnType
{
    public:
        ReturnType();
        virtual ~ReturnType();
        virtual string returnValType();//what type is it

    protected:

    private:
};

#endif // RETURNTYPE_H
