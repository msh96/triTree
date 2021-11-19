//
//  quoteBank.h
//  data_structure
//
//  Created by M on 3/30/1396 AP.
//  Copyright (c) 1396 M. All rights reserved.
//

#ifndef data_structure_quoteBank_h
#define data_structure_quoteBank_h


#endif
#include <iostream>

using namespace std;
class quoteBank{
public:
    char nextId[8] = {'1','\0','\0','\0','\0','\0','\0','\0'} ;
    public:
    void CreatUser();
    void DeleteUser();
    void LogIn();
    void LogOut();
    void AddQuote();
    void SearchByUser();
    void SearchById();
    void SearchByAuthor();
    void UpVote();
    void CountVotes();
    void DownVote();
    void DeleteQuote();
    void FindAllOccurrences();
    void TopQuotes();
    void MostRecentQuote();
    //extra functions
    void getnextId();
    void getpreviosId(char str[7]);
    void mostrecent(char str[7],char* key);

    
};
