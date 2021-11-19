//
//  main.cpp
//  data_structure
//
//  Created by M on 3/30/1396 AP.
//  Copyright (c) 1396 M. All rights reserved.
//

#include <iostream>
#include "trieTree.h"
#include "quoteBank.h"
#include <string.h>
using namespace std;
int main() {
    char temp[32] = "msh";
    char* ptr = temp;
    temp[0] = 'h';
    cout<<temp[0];
    char ch[100];
    char comand1[20] = "Creat User";
    char comand2[20] = "Delete User";
    char comand3[20] = "Login";
    char comand4[20] = "Logout";
    char comand5[20] = "Add Quote";
    char comand6[20] = "Upvote";
    char comand7[20] = "Downvote";
    char comand8[20] = "Count Votes";
    char comand9[20] = "Delete Quote";
    char comand10[25] = "Find All Occurrences";
    char comand11[20] = "Search by User";
    char comand12[20] = "Search by ID";
    char comand13[20] = "Search by Author";
    char comand14[20] = "Top Quotes";
    char comand15[25] = "Most Recent Quotes";
    
    quoteBank q;
    while (true){
        cin.getline(ch, 1000);
        if(!strcmp(ch,comand1))
            q.CreatUser();
        else if(!strcmp(ch,comand2))
            q.DeleteUser();
        else if(!strcmp(ch,comand3))
            q.LogIn();
        else if(!strcmp(ch,comand4))
            q.LogOut();
        else if(!strcmp(ch,comand5))
            q.AddQuote();
        else if(!strcmp(ch,comand6))
            q.UpVote();
        else if(!strcmp(ch,comand7))
            q.DownVote();
        else if(!strcmp(ch,comand8))
            q.CountVotes();
        else if(!strcmp(ch,comand9))
            q.DeleteQuote();
        else if(!strcmp(ch,comand10))
            q.FindAllOccurrences();
        else if(!strcmp(ch,comand11))
            q.SearchByUser();
        else if(!strcmp(ch,comand12))
            q.SearchById();
        else if(!strcmp(ch,comand13))
            q.SearchByAuthor();
        else if(!strcmp(ch,comand15))
            q.MostRecentQuote();
        else
            printf("comand not found\n");
      //  else if(strcmp(ch,comand14))
            //q.
    
    }
}
