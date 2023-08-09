#include "Reading.hpp"

 Reading::Reading(string filename)
 {
    this->filename = filename;
    this->line = nullptr;
   
 }

Reading:: ~Reading(){
         if(line !=nullptr)
       delete line;
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
    
 
    ifstream file(this->filename);
    string str;
    int s = 0;
  
    while (getline(file, token)) {
        istringstream ss(token);
         Stack* stk = new Stack();
         BTS* root = new BTS();    
         
        while (getline(ss, str, ' ')) {
          
           
          stk->CreateStack(stoi(str),s);
         s++;
        }
        i++;
        s=0;
       
        root = stk->PopAndBTS();
        
        
        root->SearchAndMaxHeight();   
        root->postorder();
        
        
        
        root->NodeDelete();
        Sleep(10);
      
    }
    
    file.close();
 }