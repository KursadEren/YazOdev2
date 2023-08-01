#ifndef NODE_HPP
#define NODE_HPP

class Node{
    public:
          int data;
          int NextCount;
          Node*Next;
          Node*Down;
          Node(int data) : data(data),NextCount(0), Next(nullptr), Down(nullptr) {};
        

};

#endif