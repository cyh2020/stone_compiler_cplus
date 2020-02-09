#include "NestedEnv.h"
#include <iostream>
#include "BasicEnv.h"
using std::cout;
using std::endl;

NestedEnv::NestedEnv(Environment* e)
{
    //ctor
//    cout<<"in NestedEnv creator"<<e<<endl;
    this->outer = e;
}

NestedEnv::~NestedEnv()
{
    //dtor
}

void NestedEnv::setOuter(Environment &e) { outer = &e; }

ReturnType* NestedEnv::get(string name) {
    auto m = values.find(name);
    if (m != values.end()) {
        return m->second;//return second key-value
    }else{
        if (outer != nullptr){//outer env
//            cout<<this<<"---->"<<outer<<endl;
            return ((BasicEnv*)outer)->get(name);
        }else{
            return nullptr;
        }
    }
    return nullptr;
}

void NestedEnv::putNew(string name, ReturnType* value) {
    auto m = values.find(name);
    if (m != values.end()) {//there is a pair which key is name
        values[name] = value;
    }else{//do not have
        values.insert(pair<string,ReturnType*>(name, value));
    }
}

void NestedEnv::put(string name, ReturnType* value) {//find where to put the value
        Environment* e = where(name);
        if (e == nullptr)
            e = this;
        e->putNew(name, value);
    }

Environment* NestedEnv::where(string name) {
    auto m = values.find(name);
    if (m != values.end()) {
        return this;
    }else if (outer == nullptr)
        return nullptr;
    else//outer exist
        return outer;
}
