#include "LineNumberReader.h"
#include <fstream>
#include <string>

LineNumberReader::LineNumberReader(std::string file_location):file_path(file_location)
{
    line_no = 0;
    is_open = true;
    OpenFile.open(file_path);
}

LineNumberReader::~LineNumberReader()
{
    //dtor
}

std::string LineNumberReader::getstr(){
    //attention this 80 , also in h file;
    OpenFile.getline(chr_out,80);
    str_out = chr_out;
    line_no ++;

    if (OpenFile.eof()){
        OpenFile.close();
        is_open = false;
        return str_out;
    }

    return str_out;
};

int LineNumberReader::getLineNumber(){
    return this->line_no;

};

