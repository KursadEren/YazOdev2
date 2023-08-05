#ifndef BTSNODE_HPP
#define BTSNODE_HPP

class BtsNode{
    public:
    int value;
    BtsNode* Next;
    BtsNode*right;
    BtsNode*left;
  
    BtsNode(int value){
        this->value = value;
        this->Next = nullptr;
        this->right = nullptr;
        this->left = nullptr;
    }
    BtsNode(){
        this->value = 0;
        this->Next = nullptr;
        this->right = nullptr;
        this->left = nullptr;
    }
};

#endif