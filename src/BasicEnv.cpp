#include "BasicEnv.h"

BasicEnv::BasicEnv():Environment()
{
    //ctor
}

BasicEnv::~BasicEnv()
{
    //dtor
}

void BasicEnv::put(string name, ReturnType* value){
    auto m = values.find(name);
    if (m != values.end()) {//there is a pair which key is name
        values[name] = value;
    }else{//do not have
        values.insert(pair<string,ReturnType*>(name, value));
    }
}

void BasicEnv::putNew(string name, ReturnType* value) {
    auto m = values.find(name);
    if (m != values.end()) {//there is a pair which key is name
        values[name] = value;
    }else{//do not have
        values.insert(pair<string,ReturnType*>(name, value));
    }
}

ReturnType* BasicEnv::get(string name) {
    auto m = values.find(name);
    if (m != values.end()) {
        return m->second;//return second key-value
    }
    return nullptr;
}

