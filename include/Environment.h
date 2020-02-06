#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H


#include <map>
#include <string>
#include"ReturnType.h"
using std::map;
using std::string;


class Environment
{
    public:
        Environment();
        virtual ~Environment();
        void put(string name, ReturnType* value);
        ReturnType* get(string name);


    protected:

    private:
        map<string,ReturnType*> values;
};

#endif // ENVIRONMENT_H
