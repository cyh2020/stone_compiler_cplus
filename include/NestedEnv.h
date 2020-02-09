#ifndef NESTEDENV_H
#define NESTEDENV_H

#include <Environment.h>
#include <map>
#include <string>
#include"ReturnType.h"
using std::pair;
using std::map;
using std::string;



class NestedEnv : public Environment
{
    public:
        NestedEnv(Environment* e);
        virtual ~NestedEnv();


    void setOuter(Environment &e);

    ReturnType* get(string name);

    void putNew(string name, ReturnType* value);
    void put(string name, ReturnType* value);

    Environment* where(string name);

    protected:
        Environment* outer = nullptr;
        map<string,ReturnType*> values;
    private:
};

#endif // NESTEDENV_H
