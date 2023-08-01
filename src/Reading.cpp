#include "Reading.hpp"

 Reading::Reading(string filename)
 {
    this->filename = filename;
    this->line = nullptr;
   
 }

Reading:: ~Reading(){
        delete line; 
        line = nullptr;
 }

 int Reading :: linecount() {
    int counter = 0;
    ifstream file(this->filename);
    string unused;
    while (getline(file, unused))
        ++counter;

    file.close();
    return counter;
}

 void Reading::readline(){
    string token;
    int i = 0;
    Stack* stk = new Stack();
    ifstream file(this->filename);
    string str;
    int s = 0;
   
    while (getline(file, token)) {
        istringstream ss(token);
        while (getline(ss, str, ' ')) {
           
            
        stk->CreateStack(stoi(str),s);
         s++;
        }
        i++;
        stk->WriteStack();
        
        
       
    }
    
    file.close();
 }