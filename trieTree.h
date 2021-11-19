//
//  trieTree.h
//  data_structure
//
//  Created by M on 3/30/1396 AP.
//  Copyright (c) 1396 M. All rights reserved.
//

#ifndef data_structure_trieTree_h
#define data_structure_trieTree_h


#endif

#include <vector>

using namespace std;
struct node{
    node* right_node = NULL;
    node* down_node = NULL;
    node* parent = NULL;
    
    node* strings;
    node* Autor;
    node* voted_strings;
    
    bool isAuthor= false;
    bool isUser = false;
    bool isSentence = false;
    bool isId = false;
    
    bool isRegistered = false;
    
    char vote = '0';
    
    char value;
    
    
    
};

class trieTree{
public:
    node* addNode(node* ,char* );
    node* findNode(node* ,char* );
    void Search(node*);
    void Print(node*);
    void DeleteNode(node*);
    void findId(node*,char[3]);
    void DeleteSentences(node*);
    void findOccurences(node* ptr,char* );
};