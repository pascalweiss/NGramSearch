//
//  BSView.cpp
//  NGramSearch
//
//  Created by Pascal Weiß on 22.01.15.
//  Copyright (c) 2015 Pascal Weiß. All rights reserved.
//

#include "BSView.h"
#include "BSMessages.h"
#include <iostream>
#include <sstream>

// Methods for user input

void BSView::menuUI() {
    cout << "\nPress any key....\n";
    string VOID;
    getline(cin, VOID);
    
    string input;
    cout << "\nMenu \n=====\n1: Search for city\n2: View Database\n3: View Trigrams\n\nType in the number: ";
    getline(cin, input);
    try {
        switch (stoi(input)) {
            case 1:
                currentMenu = BSMessages::searchEntered;
                notify(BSMessages::searchEntered);
                break;
            case 2:
                currentMenu = BSMessages::requestDatabaseEntered;
                notify(BSMessages::requestDatabaseEntered);
                break;
            case 3:
                currentMenu = BSMessages::requestNGramsEntered;
                notify(BSMessages::requestNGramsEntered);
                ;
            default:
                break;
        }
    }
    catch (const invalid_argument& ia) {
        cerr << "Invalid argument: " << ia.what() << '\n';
    }
}

void BSView::searchUI() {
    cout << "Type in a city: ";
    getline(cin, currentSearchString);
    notify(BSMessages::getSearchStringFinished);
}

// Methods for data output

void BSView::printDatabase(vector<string> data) {
    cout << "\nDatabase\n==============\n";
    for (int i = 0; i < data.size(); i++) {
        cout << data.at(i) << "\n";
    }
    notify(BSMessages::printDatabaseFinished);
}

void BSView::printResult(vector<pair<string, int> > results) {
    cout << "\nSearch results\n==============\n";
    int i = (int)results.size()+1;
    for (vector<pair<string, int> >::iterator result = results.begin(); result != results.end(); result++) {
        i--;
        cout << i << ": " << result->first << ", " << result->second << "\n";
    }
    notify(BSMessages::printResultFinished);
}

void BSView::printNGrams(map <string, vector<int> > data) {
    cout << "\nNGrams\n==============\n";
    string key;
    vector<int> vek;
    for(auto it = data.cbegin(); it != data.cend(); ++it) {
        vek = it->second;
        stringstream sstream;
        for (int i = 0; i < vek.size(); i++) {
            sstream << (vek.at(i));
            if (i != vek.size() -1) {
                sstream << ", ";
            }
        }
        key = it->first;
        cout << key << ": " << sstream.str() << "\n";
    }
    notify(BSMessages::printNGramsFinished);
}



