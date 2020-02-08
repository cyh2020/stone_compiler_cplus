#ifndef LINENUMBERREADER_H
#define LINENUMBERREADER_H

#include <iostream>
#include <fstream>
#include <string>

//using namespace std;

class LineNumberReader{
    public:
        LineNumberReader( std::string s );
        virtual ~LineNumberReader();

        std::string getstr();
        int getLineNumber();
        bool is_open;

    private:
        std::string file_path;
        std::ifstream OpenFile;
        char chr_out[80];
        std::string str_out;
        int line_no;
};

#endif // LINENUMBERREADER_H
