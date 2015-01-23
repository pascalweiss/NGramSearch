//
//  BSView.h
//  NGramSearch
//
//  Created by Pascal Weiß on 22.01.15.
//  Copyright (c) 2015 Pascal Weiß. All rights reserved.
//

#ifndef __NGramSearch__BSView__
#define __NGramSearch__BSView__

#include <stdio.h>
#include "BSSubject.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

class BSView: public BSSubject {
// Everything should be public!
public:
    // Attributes for storing the user input. Maybe not the most beautiful solution...
    int currentMenu;
    string currentSearchString;
    // Methods for user input
    void menuUI();
    void searchUI();
    // Methods for data output
    void printDatabase(vector<string> data);
    void printResult(vector<pair<string, int> > results);
    void printNGrams(map <string, vector<int> > data);
};



#endif /* defined(__NGramSearch__BSView__) */
