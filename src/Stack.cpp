#include "Stack.hpp"

 Stack::Stack(){
    this->NextNumber=1;
    this->TopNode=nullptr;
    this->root = nullptr;
    
 }
 Stack:: ~Stack(){
   
    Node* temp;
    for(int i = 0; i<NextNumber; i++ )
    {
      while (TopNode != nullptr) {
        temp = TopNode;
        TopNode->Down->Next = TopNode->Next;
        TopNode = TopNode->Down;
        delete temp;
    }
    temp = TopNode;
    TopNode = TopNode->Next;
    delete temp;
    
    

    }
    

    }
 void Stack::push(int data) {
    Node* new_node = new Node(data);
    new_node->Down = TopNode;
    TopNode = new_node;
}





void Stack::CreateStack(int value, int value2) {
    Node* new_Node = new Node(value);

    if (TopNode == nullptr) {
        TopNode = new_Node;
        new_Node->NextCount = NextNumber;
    } else {
        Node* temp = GetNode(TopNode);
        Node* prev = GetPrevNode(temp);
        
        if (value % 2 == 0 && temp->data < value) {
            temp->Next = new_Node;
            NextNumber++;
            new_Node->NextCount = NextNumber;
        } else if (prev == nullptr && value2 != 0) {
            new_Node->Down = TopNode;
            TopNode = new_Node;
            new_Node->NextCount = NextNumber;
        } else if (prev != nullptr) {
            prev->Next = new_Node;
            new_Node->Down = temp;
            new_Node->NextCount = NextNumber;
        }
    }
}

void Stack::WriteStack() {
    Node* temp = TopNode;
    Node* temp2 = TopNode;
   
    for (int i = 0; i < NextNumber; i++) {
        while (temp) {
            cout << temp->data << " ";
            temp = temp->Down;
        }
        cout << " -> " << endl;
        temp = temp2->Next;
        temp2 = temp;
    }
}
 

Node* Stack::GetNode(Node*node)
{
   Node* temp = node;
   while(temp->Next != nullptr)
   {
      temp = temp->Next;
   }
   return temp;
}

Node* Stack::GetPrevNode(Node*node)
{
   Node* temp = node;
   Node *prev = TopNode;
   while(prev->Next != temp && prev != temp )
   {
      prev = prev->Next;
   }
   if(prev == temp)
   {
      return nullptr;
   }
   return prev;
}
   
void Stack::SetNextNumber(){

     this->NextNumber = 1;
}
BTS* Stack::PopAndBTS()
{
   Node *temp = TopNode;
   
   BTS* root = new BTS();
   for(int i =0 ; i<NextNumber;i++){
         
         while(TopNode != nullptr){
            
            if(TopNode->Down !=nullptr){
               
               root->insert(TopNode->data,TopNode->NextCount);
               temp =  TopNode;
               TopNode->Down->Next = TopNode->Next;
               TopNode = TopNode->Down;
               
               delete temp;
               
            }
            else if (TopNode->Down == nullptr){
               
                root->insert(TopNode->data,TopNode->NextCount);
                temp = TopNode;
                TopNode = TopNode->Next;         
                delete temp;
                
            }
            
         }    
         
   }
   
   return root;
}