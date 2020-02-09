#ifndef FUNCTION_H
#define FUNCTION_H
#include "Environment.h"
#include "BlockStmnt.h"
#include "ParameterList.h"
#include <string>
#include "NestedEnv.h"
#include "ReturnType.h"
using std::string;


class Function:public ReturnType
{
    public:
        Function(ParameterList parameters, BlockStmnt body, Environment &env);
        virtual ~Function();

        ParameterList* get_parameters();
        BlockStmnt* get_body();
        Environment* get_Env();
        string toString();

    protected:
        ParameterList parameters;
        BlockStmnt body;
        Environment* env;

    private:
};

#endif // FUNCTION_H
