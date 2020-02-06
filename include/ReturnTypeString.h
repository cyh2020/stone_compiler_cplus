#ifndef RETURNTYPESTRING_H
#define RETURNTYPESTRING_H

#include <ReturnType.h>
#include <string>

using std::string;


class ReturnTypeString : public ReturnType
{
    public:
        ReturnTypeString();
        ReturnTypeString(string s);
        virtual ~ReturnTypeString();


        string returnValType();
        string returnVal();

    protected:

    private:
        string val;
};

#endif // RETURNTYPESTRING_H
