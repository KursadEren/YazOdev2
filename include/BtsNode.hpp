#ifndef BTSNODE_HPP
#define BTSNODE_HPP

class BtsNode{

    int value;
    BtsNode* Next;
    BtsNode*right;
    BtsNode*left;
    Node(int value) : value{value},Next{nullptr},right{nullptr},left{nullptr};
};

#endif