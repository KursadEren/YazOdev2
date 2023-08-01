#include "BTS.hpp"

void BTS::SearchAndAdd(BtsNode *&subNode,const int& newItem){
			if(subNode == NULL) subNode = new BtsNode(newItem);
			else if(newItem < subNode->data)
				SearchAndAdd(subNode->left,newItem);
			else if(newItem > subNode->data)
				SearchAndAdd(subNode->right,newItem);
			else return;
		}

 void BTS::insert(const int& newItem){
    SearchAndAdd(root,newItem);
 }
  void  BTS::insertNext(const Object& newItem){
    GetNextNode(root,newItem);
  }

void BTS::GetNextNode(BtsNode*subNode,int value){

   BtsNode* temp =  GetNode(subNode);
   temp->Next = new BtsNode(value);
   
}

BtsNode* BTS::GetNode(BtsNode*subNode){
    BtsNode*temp =subNode;
    while(temp->Next !=nullptr){
        temp = temp->Next;
    }
    return temp;
}