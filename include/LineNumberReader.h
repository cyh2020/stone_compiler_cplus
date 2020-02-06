#ifndef LINENUMBERREADER_H
#define LINENUMBERREADER_H

#include <iostream>
#include <fstream>
#include <string>

//using namespace std;

class LineNumberReader{
    public:
        LineNumberReader();
        virtual ~LineNumberReader();

        std::string getstr();
        int getLineNumber();
        bool is_open;

    private:
        std::ifstream OpenFile;
        char chr_out[20];
        std::string str_out;
        int line_no;
};

#endif // LINENUMBERREADER_H
