//
//  quoteBank.cpp
//
//
//  Created by M on 3/30/1396 AP.
//
//

#include "quoteBank.h"
#include "trieTree.h"
#include <iostream>
#include <stdio.h>


node root;
trieTree myTrie;


node* strings_by_id[1000];
node* author_by_id[1000];
int votes[1000] = {0};
int count;
node* current_user = NULL;

void quoteBank::CreatUser(){
    node* temp;
    char str[1000];
    cin.getline(str,1000);
    temp = myTrie.findNode(&root, str);
    if(temp != NULL && temp->isUser )
        printf("%s is already exists.\n",str);
    else{
        temp = myTrie.addNode(&root, str);
        temp->isUser = true;
    }
    
}
//*******************************
void quoteBank::LogIn(){
    node* temp;
    char str[1000];
    cin.getline(str,1000);
    if(current_user != NULL )
        cout<<"Current user must logout first."<<endl;
    else{
        temp = myTrie.findNode(&root, str);
        if(temp == NULL || !(temp->isUser))
            printf("user %s doesn't exist.\n",str);
        else{
            current_user = temp;
            printf("Logged in\n");
        }
        
    }
    
    
}
//*******************************
void quoteBank::LogOut(){
    
    if(current_user == NULL)
        printf("you must login first.\n");
    else{
        current_user = NULL;
        printf("Logged out\n");
    }
    
}
//*******************************
void quoteBank::AddQuote(){
        char str[1000];
    
        node* temp1;
        node* temp2;
        node* temp3;
    if(current_user == NULL)
        printf("please login first\n");
    else{
        cin.getline(str, 1000);
        temp1 = myTrie.addNode(&root, str);           //add author to root
        temp1->isAuthor = true;
        if(temp1->strings == NULL)
            temp1->strings = new node;
        temp2 = myTrie.addNode(temp1->strings,nextId);
        temp2->isId = true;
        
        cin.getline(str, 1000);
        temp3 = myTrie.addNode(&root, str);         //add string to root
        temp3->isSentence = true;
        temp3->Autor = temp1;
        
        temp2->strings = temp3;                     //add strings to id of strings in Author root
        
        temp2 = myTrie.addNode(&root,nextId);      //add id to root
        temp2->isId = true;
        temp2->strings = temp3;
        
        
        temp3->strings = temp2;             //add id to string
       
        
        if(current_user->strings == NULL)
            current_user->strings = new node;
        temp1 = myTrie.addNode(current_user->strings, nextId);  //add strings to current_user
        temp1->isId = true;
        temp1->strings = temp3;
        
        temp2->Autor =temp1; //add id of user to main id
        
        getnextId();
    }
    
}
//*********************************
void quoteBank::SearchByUser(){
    char str[1000];
    cin.getline(str,1000);
    
    node* temp = myTrie.findNode(&root, str);
    if(temp == NULL || !(temp->isUser))
        printf("user %s doesn't exists.\n",str);
    else{
        myTrie.Search(temp->strings);
    }
}
//*********************************
void quoteBank::SearchById(){
    char id[7];
    cin.getline(id,8);
    node* temp = myTrie.findNode(&root,id );
    if(temp == NULL || !(temp->isId))
        printf("Quote %s doesn’t exist.\n",id);
    else{
        
       myTrie.Print(temp->strings);
        printf("\nby ");
        myTrie.Print(temp->strings->Autor);
        printf("\n");
    }
}
//*********************************
void quoteBank::SearchByAuthor(){
    char str[1000];
    cin.getline(str, 1000);
    node* temp = myTrie.findNode(&root, str);
    if(temp == NULL || !(temp->isAuthor))
        printf("Author doesn't exixts.\n");
    else{
        myTrie.Search(temp->strings);
    
    }
}
//*********************************
void quoteBank::UpVote(){
    char n[6];
    if(current_user == NULL)
        printf("You must login first.\n");
    else{
        cin.getline(n, 7);
        node* temp = myTrie.findNode(&root, n);
        if(temp == NULL){
            printf("Id doesn't exists.\n");
            return;
        }
        if(current_user->voted_strings == NULL)
            current_user->voted_strings = new node;
            node* temp1 = myTrie.findNode((current_user->voted_strings),n);
        if(temp1 == NULL){
            node* temp2 = myTrie.addNode((current_user->voted_strings),n);
            temp2 ->isId = true;
            temp2->vote = 'P';
            (temp->vote) ++;
        }
        else{
            if(temp1->vote == 'N')
                temp->vote += 2;
            temp1->vote = 'P';
        }
    if((temp->vote)>50)
        temp->isRegistered = true;

    }
}
//******************************
void quoteBank::DownVote(){
    char str[7];
    if(current_user == NULL)
        printf("You must login first.\n");
    else{
        cin.getline(str, 8);
        node* temp = myTrie.findNode(&root, str);
        if(temp == NULL){
            printf("Id doesn't exists in users quote list.\n");
            return;
        }
        if(current_user->voted_strings == NULL)
            current_user->voted_strings = new node;
        node* temp1 = myTrie.findNode((current_user->voted_strings),str);
        if(temp1 == NULL){
            node* temp2 = myTrie.addNode((current_user->voted_strings),str);
            temp2 ->isId = true;
            temp2->vote = 'N';
            (temp->vote) --;
        }
        else{
            if(temp1->vote == 'P')
                temp->vote -= 2;
            temp1->vote = 'N';
        }
        if((temp->vote)<46 && !(temp->isRegistered)){
            myTrie.DeleteSentences(temp->Autor);
        }
    }
}
//******************************
void quoteBank::CountVotes(){
    char ch[7];
    cin.getline(ch,8);
    node* temp = myTrie.findNode(&root,ch);
    if(temp == NULL || !(temp->isId))
        printf("quote %s doesn't exist.\n",ch);
    else
        printf("%d\n",(temp->vote)-48);

}
//******************************
void  quoteBank::DeleteUser(){
    char str[10000];
    cin.getline(str,10000);
    node* myNode = myTrie.findNode(&root, str);
    if(myNode == NULL || !(myNode->isUser))
        printf("user %s doesn't exist.\n",str);
    else{
        if(myNode == current_user)
            current_user = NULL;
        if(myNode->strings != NULL)
            myTrie.DeleteSentences(myNode->strings);
        myNode->isUser = false;
        myTrie.DeleteNode(myNode);
    }
    
}
//******************************
void quoteBank::DeleteQuote(){
    char str[7];
    if(current_user == NULL){
        printf("please login first\n");
        return;
    }
        
    cin.getline(str,8);
    node* myNode;
    if(current_user->strings != NULL)
         myNode = myTrie.findNode(current_user->strings, str);
    if(myNode == NULL || !(myNode->isId))
        printf("quote  %s doesn't exist in current user's quotes list.",str);
    else{
        if(myNode->strings->isRegistered)
            printf("couln't delete %s.\n",str);
        else
            myTrie.DeleteSentences(myNode);
}

}
//******************************
void quoteBank::FindAllOccurrences(){
    char str[100000];
    cin.getline(str,100000);
    myTrie.findOccurences(&root, str);



}
void quoteBank::MostRecentQuote(){
    char str[7];
    char temp[7];
    for(int i = 0 ; i < 7;i++)
        temp[i] = nextId[i];
    cin.getline(str,8);

    mostrecent(temp,str);
}
void quoteBank::mostrecent(char* str,char* key){
    if(str[0] == '0' || key[0] == '0')
        return;
    
    node* mynode = myTrie.findNode(&root,str);
    if(mynode != NULL && mynode->isId){
        getpreviosId(key);
        getpreviosId(str);
        mostrecent(str,key);
        myTrie.Print(mynode->strings);
        printf(" by \n");
        myTrie.Print(mynode->strings->Autor);
        printf("\n");
    }
    else{
        getpreviosId(str);
        mostrecent(str,key);
    }
   

}
void quoteBank::getpreviosId(char str[7]){
    int lenght = 0;
    int temp;
    while(str[lenght] != '\0')
        lenght++;
    temp = lenght;
    while (str[lenght-1] == '0' && lenght!= 1) {
        str[lenght-1] = '9';
        if(str[lenght-2] == '1')
        {
            str[temp-1] = '\0';
            str[lenght-2] = '9';
            return;
        }
        lenght--;
        
    }
    str[lenght-1]--;

    

}
//******************************
void quoteBank::getnextId(){
    int lenght = 0;
    int temp;
    while(nextId[lenght] != '\0')
        lenght++;
    temp = lenght;

    while (nextId[lenght-1] == '9') {
        if (lenght == 1) {
            nextId[lenght-1] = '1';
            nextId[temp] = '0';
            return;
        }
        nextId[lenght-1] = '0';
        lenght--;
    }
    nextId[lenght-1]++;
    
}

