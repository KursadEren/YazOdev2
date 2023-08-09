#ifndef BTS_HPP
#define BTS_HPP
#include <iostream>

#include "BtsNode.hpp"

using namespace std;
class BTS{
    BtsNode*root;
    BtsNode*NewRoot;
    private:
   
    int NextCount;
    void SearchAndAdd(BtsNode *&subNode,int const & newItem, int value);
    void inorder(BtsNode *subNode);
     BtsNode*  SearchAndMaxHeight(BtsNode*&subNode);
      void postorderASCII(BtsNode *subNode);
      bool DeleteNode(BtsNode *& subNode);
    public:
        
        BTS();
        ~BTS();
        void postorder();
        void inorder();
        
        void insert( int const & newItem, int value);
        int Height(BtsNode *&subNode);
        void SearchAndMaxHeight();
        int NodeSum(BtsNode*subNode);
        void NodeDelete();
};


#endif