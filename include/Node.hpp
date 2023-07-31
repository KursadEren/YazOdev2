#ifndef NODE_HPP
#define NODE_HPP

class Node{
    public:
          int data;
          Node*Next;
          Node*Down;
          Node(int data) : data(data), Next(nullptr), Down(nullptr) {};
        

};

#endif