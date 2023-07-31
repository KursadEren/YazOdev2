#ifndef READING_HPP
#define READING_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Stack.hpp"
using namespace std;

class Reading{
    private:
     string filename;
     Stack*line;
    public:
       Reading(string filename);
       ~Reading();
       int linecount();
       void readline();


};

#endif