#ifndef FUNCTIONPARSER_H
#define FUNCTIONPARSER_H

#include <BasicParser.h>
#include <ParserDerived.h>
#include "Parser.h"
#include "Arguments.h"
#include "DefStmnt.h"


class FunctionParser : public BasicParser
{
    public:
        FunctionParser();
        virtual ~FunctionParser();

        Parser param;

        ParserDerived<ParameterList> params;

        Parser params_repeat;

        Parser paramList;

        //definition of function def block
        ParserDerived<DefStmnt> def;

        ParserDerived<Arguments> args;
        Parser args_repeat;

        Parser postfix;// run in main program

        void print_BP_ele(){
            BasicParser::print_BP_ele();
            cout<<"param   "<<&param<<endl;
            cout<<"params   "<<&params<<endl;
            cout<<"params_repeat   "<<&params_repeat<<endl;
            cout<<"paramList   "<<&paramList<<endl;
            cout<<"def   "<<&def<<endl;
            cout<<"args   "<<&args<<endl;
            cout<<"args_repeat   "<<&args_repeat<<endl;
            cout<<"postfix   "<<&postfix<<endl;
            cout<<"--------------------------------------------------------------------"<<endl;
        }


    protected:

    private:



};

#endif // FUNCTIONPARSER_H
