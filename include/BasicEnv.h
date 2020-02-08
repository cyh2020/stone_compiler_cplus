#ifndef BASICENV_H
#define BASICENV_H

#include <Environment.h>


#include <map>
#include <string>
#include"ReturnType.h"
using std::pair;
using std::map;
using std::string;


class BasicEnv : public Environment
{
    public:
        BasicEnv();
        virtual ~BasicEnv();
        void put(string name, ReturnType* value);
        ReturnType* get(string name);


    protected:

    private:
        map<string,ReturnType*> values;
};

#endif // BASICENV_H
