/* 
 * File:   BSData.h
 * Author: s0544768
 *
 * Created on 8. Dezember 2014, 19:25
 */

#ifndef BSData_H
#define BSData_H

#include <string>
#include <vector>
#include "BSDatatype.h"
#include "BSNGrams.h"

using namespace std;

class BSData {
    vector <string> data;
    string type;
    BSNGrams nGrams;
public:
    BSData();
    vector<pair<string, int> > search(string str);
    vector<string> getDatabase();
    map<string, vector<int> > getNGrams();
    void addElement(string element);
    bool importFromFile(string filepath, int type);
    void printData();
    void printNGrams();
};

#endif