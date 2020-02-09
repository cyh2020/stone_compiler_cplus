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
        virtual void put(string name,ReturnType* value);
        virtual void putNew(string name,ReturnType* value);
        virtual ReturnType* get(string name){
            throw "Environment interface dont have get method";
        };


    protected:

    private:
};

#endif // ENVIRONMENT_H
