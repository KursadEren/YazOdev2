#ifndef BTS_HPP
#define BTS_HPP
#include <iostream>
#include "BtsNode.hpp"

using namespace std;
class BTS{
    
    private:
    
    int NextCount;
    void SearchAndAdd(BtsNode *&subNode,int const & newItem);
     void GetNextNode(BtsNode*subNode);
    public:
        BtsNode*root;
        BTS();
        ~BTS();
        bool DeleteNode(BtsNode *&subNode);
        void insert( int const & newItem);
        void insertNext();
        BtsNode* GetNode(BtsNode*subNode);
};


#endif