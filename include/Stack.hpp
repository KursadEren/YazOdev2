#ifndef STACK_HPP
#define STACK_HPP
#include "Node.hpp"
#include "BTS.hpp"
#include <iostream>
using namespace std;

class Stack{

    private:
        int ChechTopNode;
        int NextNumber;
        Node*TopNode;
        BTS*root;
        

    public:
        Stack();
       ~Stack();
        void push(int data);
         int pop();
         
        void CreateStack(int value,int value2);
        void WriteStack();
         Node* GetNode(Node*node);
         Node* GetPrevNode(Node*node);
         void SetNextNumber();
         void PopAndBTS();
 
};



#endif