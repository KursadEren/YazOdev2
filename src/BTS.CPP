#include "BTS.hpp"



void BTS::inorder(BtsNode *subNode){
			if(subNode != NULL){
				inorder(subNode->left);
				cout<<subNode->value<<" ";
				inorder(subNode->right);
                if(subNode->Next != nullptr){
					cout << endl;
                    inorder(subNode->Next);
                }
			}
		}
void BTS::inorder(){
    inorder(root);
}

void BTS::SearchAndAdd(BtsNode *&subNode, int const &newItem, int value) {
    if (subNode == nullptr) {
        subNode = new BtsNode(newItem, value);
    } else if (subNode->Next != nullptr && subNode->NextCount != value) {
        
        SearchAndAdd(subNode->Next, newItem, value);
    } else if (subNode->Next == nullptr && subNode->NextCount < value) {
       
        subNode->Next = new BtsNode(newItem, value);
    }  else if (newItem < subNode->value) {
       
        SearchAndAdd(subNode->left, newItem, value);
    } else if (newItem > subNode->value) {
        
        SearchAndAdd(subNode->right, newItem, value);
    } else {
        
        return;
        
    }
    
}


int BTS::Height(BtsNode *&subNode){
			if(subNode == NULL) return -1;
			  
            return (1+max(Height(subNode->left),Height(subNode->right)));
}



 void BTS::insert(int const &newItem, int value) {
    SearchAndAdd(root, newItem, value);
}

 void BTS::SearchAndMaxHeight(){
	this->NewRoot = SearchAndMaxHeight(root);
    
 }
 int BTS::NodeSum(BtsNode*subNode){
    
    if(subNode == nullptr)return 0;
    return subNode->value +(NodeSum(subNode->left)+NodeSum(subNode->right));
 }

 BtsNode* BTS::SearchAndMaxHeight(BtsNode*&subNode) {
    BtsNode* temp = subNode;
    int maxHeight = -1;  // Başlangıçta en küçük bir değer seçiyoruz
    while (temp != nullptr) {
        temp->height = Height(temp);
        temp->Sum = NodeSum(temp);
        temp = temp->Next;
        
    }
   
    temp = subNode;
     BtsNode* MaxTemp = subNode;
     MaxTemp = subNode;
      
    while (temp != nullptr) {
         
        if (temp->height > maxHeight) {
            maxHeight = temp->height;
             
        }
        else
        if(MaxTemp->height <= temp->height){
            
            if(MaxTemp->height < temp->height)
            MaxTemp = temp;
        
            if(MaxTemp->height == temp->height){
               
              MaxTemp = (MaxTemp->Sum == 55) ? MaxTemp : ((temp->Sum == 55) ? temp : MaxTemp);
              
            }
           
        }
       
        
        temp = temp->Next;
       
    } 
    
    return MaxTemp;  
}

 
 


bool BTS::DeleteNode(BtsNode *& subNode){
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



 BTS::BTS() {
    this->NewRoot =nullptr;
    this->root = nullptr;
    this->NextCount = -1;
}
 BTS::~BTS(){
    if (root != nullptr) {
        NodeDelete();
        root = nullptr;
    }
	
 }
 void BTS::postorderASCII(BtsNode *subNode){
			if (subNode == nullptr)
        return;
   
    postorderASCII(subNode->left);
    postorderASCII(subNode->right);
    cout << static_cast<char>(subNode->value) << " ";
 }

void BTS::postorder(){
			postorderASCII(NewRoot);
            cout << endl;
}

void BTS::NodeDelete(){
    BtsNode*temp = this->root;
    BtsNode*temp2 =temp;
     
       
    while(temp != nullptr){
         
        temp2 = temp;
        temp = temp->Next;
        while(temp2 == nullptr)
        {
           
            DeleteNode(temp2);
             
        }
    }
     while(NewRoot == nullptr){
        DeleteNode(NewRoot);
     }   
   
   
    }
   
