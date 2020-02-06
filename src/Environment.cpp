#include "Environment.h"
using std::pair;

Environment::Environment()
{
    //ctor
//    this.values = new map<string,ReturnType*>;
}

Environment::~Environment()
{
    //dtor
}


void Environment::put(string name, ReturnType* value) {
    auto m = values.find(name);
    if (m != values.end()) {//there is a pair which key is name
        values[name] = value;
    }else{//do not have
        values.insert(pair<string,ReturnType*>(name, value));
    }


}

ReturnType* Environment::get(string name) {
    auto m = values.find(name);
    if (m != values.end()) {
        return m->second;//return second key-value
    }
    return nullptr;
}
