#ifndef RETURNTYPEINT_H
#define RETURNTYPEINT_H

#include <ReturnType.h>


class ReturnTypeInt : public ReturnType
{
    public:
        ReturnTypeInt();
        ReturnTypeInt(int num);
        virtual ~ReturnTypeInt();

        string returnValType();
        int returnVal();

    protected:

    private:
        int val;
};

#endif // RETURNTYPEINT_H
