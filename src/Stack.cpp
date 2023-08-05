#include "Stack.hpp"

 Stack::Stack(){
    this->NextNumber=1;
    this->TopNode=nullptr;
    this->root = nullptr;
    
 }
 Stack:: ~Stack(){

    }
 void Stack::push(int data) {
    Node* new_node = new Node(data);
    new_node->Down = TopNode;
    TopNode = new_node;
}

int Stack::pop() {
    if (!TopNode) {
        std::cerr << "Stack is empty!" << std::endl;
        return -1;
    }

    int popped_data = TopNode->data;
    Node* temp = TopNode;
    if(TopNode->Down != nullptr)
    {
    TopNode->Down->Next = TopNode->Next;
    TopNode = TopNode->Down;
    }
    else{
      TopNode = TopNode->Next;
    }
   
    delete temp;

    return popped_data;
}   




void Stack::CreateStack(int value,int value2){
   Node* new_Node = new Node(value);
   
   if(TopNode ==nullptr)
   {
      TopNode = new_Node;
      new_Node->NextCount = NextNumber;
   }
      Node* temp = GetNode(TopNode);
      Node* prev = GetPrevNode(temp);
    if(value % 2 ==0 && temp->data < value ) {
         
         temp->Next  = new_Node ;
         NextNumber++;
         new_Node->NextCount = NextNumber;
     }
     else  if( prev == nullptr && value2 != 0 ) // mantıksız bu sefer hiçbir zaman next ine bir şey oluşturmayacak 
     {
       new_Node->Down =TopNode;
       TopNode = new_Node;
       new_Node->NextCount = NextNumber;
     }
     else if (prev !=nullptr){
         prev->Next =new_Node;
         new_Node->Down = temp;
         new_Node->NextCount = NextNumber;
     }
 
   

   
 
      //cout<< TopNode<< " " << new_Node->data << " " << new_Node << " " << new_Node->Next << " " << new_Node->Down << endl;
     
     
  
}
void Stack:: WriteStack()
{
   Node* temp = TopNode;
   Node*temp2 = TopNode;
   
    for(int i=0; i< NextNumber;i++)
   {
     
      while(temp)
      {
          cout << temp->data<< " "  ;
          temp = temp->Down;
      }
      cout << " -> "<<endl;
      temp = temp2->Next;
      temp2=temp;
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
void Stack::PopAndBTS()
{
   Node *temp = TopNode;
   Node *delNode;
   for(int i =0 ; i<NextNumber;i++){

         while(temp != nullptr){

           
            if(TopNode->Down !=nullptr){
              
              root->insert(TopNode->data);
                 
               temp = TopNode->Down;
               delete TopNode;
               TopNode = temp;
            }
            else if (TopNode->Down == nullptr){
                cout << "Hey 2 "<<endl;
               root->insert(TopNode->data);
                temp = TopNode->Next;
                delete TopNode;
                TopNode = temp;
            }
            
         }    
         if(TopNode != nullptr){
             cout << "Hey 3 "<<endl;
           root->insertNext();
         }
   }
}