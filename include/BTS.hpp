#ifndef BTS_HPP
#define BTS_HPP

using namespace std;

class BTS{
    BtsNode*root
    private:
    
    void SearchAndAdd(BtsNode *&subNode,const Object& newItem);
     void GetNextNode(BtsNode*subNode,int value);
    public:
        void insert(const Object& newItem);
        void insertNext(const Object& newItem);
        BtsNode* BTS::GetNode(BtsNode*subNode);
};


#endif