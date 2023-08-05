#include "BTS.hpp"

void BTS::SearchAndAdd(BtsNode *&subNode, int const & newItem){
      
			if(subNode == nullptr) subNode = new BtsNode(newItem);
      else if(subNode->value = 0)subNode->value = newItem;
			else if(newItem < subNode->value)
				SearchAndAdd(subNode->left,newItem);
			else if(newItem > subNode->value)
				SearchAndAdd(subNode->right,newItem);
			else return;
		}

 void BTS::insert(int const  & newItem){
  
      BtsNode *temp = this->root;
      cout << "Hey 1 ";
     
     if(root != nullptr) temp = GetNode(root);
    
    SearchAndAdd(temp,newItem);
 }
  void  BTS::insertNext(){
    GetNextNode(root);
  }

void BTS::GetNextNode(BtsNode*subNode){

   BtsNode* temp =  GetNode(subNode);
   temp->Next = new BtsNode();
   
}

BtsNode* BTS::GetNode(BtsNode*subNode){
   
    BtsNode*temp =subNode;
    if(temp->Next == nullptr) return temp;
    while(temp->Next !=nullptr){
        temp = temp->Next;
    }
    return temp;
}


bool DeleteNode(BtsNode *&subNode){
			BtsNode *DelNode = subNode;
			
			if(subNode->right == NULL) subNode = subNode->left;
			else if(subNode->left == NULL) subNode = subNode->right;
			else{
				DelNode = subNode->left;
				BtsNode *parent = subNode;
				while(DelNode->right != NULL){
					parent = DelNode;
					DelNode = DelNode->right;
				}
				subNode->value = DelNode->value;
				if(parent == subNode) subNode->left = DelNode->left;
				else parent->right = DelNode->left;
			}
			delete DelNode;
			return true;
		}


    BTS::BTS(){
      this->root = nullptr;
      this->NextCount = 0;
    }

    BTS::~BTS(){

        while(!isEmpty()) DeleteNode(root);

    }