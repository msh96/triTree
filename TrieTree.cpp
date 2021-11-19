//
//  TrieNode.cpp
//
//
//  Created by M on 3/30/1396 AP.
//
//

#include "trieTree.h"
#include "iostream"
using namespace std;
node* trieTree::addNode(node* ptr, char* str){
        for ( ; *str != '\0' ;str++ ){ // insert in o(k) , k ---> lentgh of string
        
        if((ptr->down_node) == NULL ){
            ptr -> down_node = new node;
            (ptr->down_node)->value = *str;
            (ptr->down_node)->parent = ptr;
            ptr =  ptr -> down_node;
            continue;
        }
        node* temp;
        node* par ;
        par = ptr;
        temp = ptr;
        ptr = ptr -> down_node;
        while (ptr != NULL &&((ptr->value) < *str)){ //do atmost 26 times
            temp = ptr;
            ptr = ptr ->right_node;
        }
        if(ptr == NULL){
            ptr  = new node;
            temp->right_node = ptr;
            ptr->parent = par;
            ptr->value = *str;
        }
        else if(ptr->value == *str)
            continue;
        else if (temp -> down_node == ptr ){
            temp->down_node = new node;
            temp->down_node ->value = *str;
            temp->down_node ->parent = temp;
            temp->down_node ->right_node = ptr;
            ptr = temp->down_node;
            
        }
        else{
            temp->right_node = new node;
            temp ->right_node -> value = *str;
            temp ->right_node ->right_node = ptr;
            ptr = temp->right_node;
            ptr ->parent = par;
        }
        
    }

    return ptr;
}

//*****************************************
node* trieTree::findNode(node* ptr ,char* str ){
    for( ;  *str != '\0' ; str++){
        
        ptr = ptr->down_node;
        if(ptr == NULL)
            return NULL;
        while(ptr->value != *str){
            if(ptr->right_node == NULL)
                return NULL;
            ptr = ptr->right_node;
        }
        
    }
    return ptr;
}
//*****************************************


void trieTree::Search(node* ptr ){    
    if(ptr->isId){
        Print(ptr->strings);
        if(ptr ->strings-> Autor != NULL){
            printf("\nby ");
            Print(ptr->strings->Autor); //print author
        }
        printf("\n");
    }
    else if(ptr->isSentence){
        Print(ptr);
        printf("\n by");
        Print(ptr->Autor);
        printf("\n");
    }
    if (ptr-> down_node != NULL)
        Search(ptr -> down_node);
    if(ptr -> right_node != NULL)
        Search(ptr->right_node);
    
}
void trieTree::Print(node * ptr){
    if(ptr ->parent != NULL)
        Print(ptr->parent);
    cout<<ptr->value;
}
//***************************************
void trieTree::DeleteNode(node* ptr){
    node* temp;
    if(ptr->isId || ptr->isSentence || ptr->isAuthor)
        return;
    temp = ptr->parent->down_node;
    while(temp->right_node != NULL && ptr != (temp->right_node))
        temp = temp->right_node;
    if (ptr->right_node != NULL){
        if(ptr->parent->down_node == ptr)
            ptr->parent->down_node = ptr->right_node;
        else
            temp->right_node = ptr->right_node;
    }
    else{
        if(ptr->parent->down_node == ptr)
            ptr->parent->down_node = NULL;
        else
            temp->right_node = NULL;
    }
}
//***************************************
void trieTree::findId(node* ptr,char str[7]){
    node* myNode = ptr;
    int lenght = 0;
    while(myNode->parent != NULL){
        lenght++;
        myNode = myNode->parent;
    }
    str[lenght] = '\0';
    for(;lenght>0;lenght--){
        str[lenght-1] = ptr->value;
        ptr = ptr->parent;
    }
}
//****************************************
void trieTree::DeleteSentences(node* ptr){
    if(ptr->isId){
        if(ptr->strings->strings->isRegistered)
            return;
        else{
            char str[7];
            findId(ptr->strings->strings, str);
            node*  myNode = findNode(ptr->strings->Autor->strings,str);
            myNode->isId = false;
            DeleteNode(myNode);
            ptr->strings->strings->isId = false;
            DeleteNode(ptr->strings->strings);
            ptr->strings->isSentence =  false;
            DeleteNode(ptr->strings);
            ptr->isId =  false;
            DeleteNode(ptr);
        }
    }
    if (ptr-> down_node != NULL)
        DeleteSentences(ptr -> down_node);
    if(ptr -> right_node != NULL)
        DeleteSentences(ptr->right_node);
    

}
//***************************************
void trieTree::findOccurences(node* ptr,char* str){

    node* myNode = findNode(ptr, str);
    if(myNode != NULL){
        Search(myNode);
        return;
    }
    if(ptr->right_node != NULL)
        findOccurences(ptr->right_node, str);
    if(ptr->down_node != NULL)
         findOccurences(ptr->down_node, str);
    
}