/* 
 * File:   BSTrigram.h
 * Author: s0544768
 *
 * Created on 8. Dezember 2014, 19:21
 */

#ifndef BSNGRAMS_H
#define BSNGRAMS_H

#include <map>
#include <vector>
#include <string>

using namespace std;
class BSNGrams {
    map<string, vector<int> > data;
    vector<string> splitIntoNGrams(string str);
    int n;
public:
    BSNGrams(int numberOfCharacters);
    bool addString(string element, int index);
    map<int, int> search(string str);
    map<string, vector<int> > getNGrams();
    void print();
};

#endif