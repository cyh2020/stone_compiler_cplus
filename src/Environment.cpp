#include "Environment.h"
#include <iostream>

using std::pair;
using std::cout;
using std::endl;

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

}

void Environment::putNew(string name,ReturnType* value){
    cout<<"env has no putNew"<<endl;
}
