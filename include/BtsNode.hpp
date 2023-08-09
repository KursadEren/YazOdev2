#ifndef BTSNODE_HPP
#define BTSNODE_HPP

class BtsNode{
    public:
    int value;
     int Sum;
    int NextCount;
    BtsNode* Next;
    BtsNode*right;
    BtsNode*left;
    int height;
  
    BtsNode(int value ,int NextCount){
        this->Sum = 0;
        this->value = value;
        this->NextCount = NextCount;
        this->Next = nullptr;
        this->right = nullptr;
        this->left = nullptr;
        this->height = 0;
    }
    
};

#endif