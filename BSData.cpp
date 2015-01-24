/* 
 * File:   BSData.cpp
 * Author: s0544768
 *
 * Created on 8. Dezember 2014, 19:25
 */

#include "BSData.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "BSScraper.h"
#include <string>

using namespace std;

BSData::BSData(): data(), nGrams(3) {
}

bool BSData::importFromFile(string filePath, int type) {
    string line;
    ifstream infile;
    infile.open(filePath.c_str(), ifstream::in);
    if (infile.is_open()) {
        cout << "file opened\n";
        while (std::getline(infile, line)) {
            line = BSScraper::substringBeweenSeperators(line, ',', 1);
            line = BSScraper::toLower(line);
            addElement(line);
        }
        infile.close();
        return true;
    }
    else {
        std::cout << "can't open file\n";
        return false;
    }
}

vector<pair<string, int> > BSData::search(string str) {
    map<int, int> idxResult = nGrams.search(str);
    vector<pair<string, int> > result;
    for (map<int,int>::iterator idx = idxResult.begin(); idx != idxResult.end(); idx++) {
        result.push_back(pair<string, int>(data.at(idx->first), idx->second));
    }
    return result;
}

vector<string> BSData::getDatabase() {
    return data;
}

map<string, vector<int> > BSData::getNGrams() {
    return nGrams.getNGrams();
}

void BSData::addElement(string element) {
    int idx = (int)data.size();
    data.push_back(element);
    nGrams.addString(element, idx);
}

void BSData::printData() {
    for (int i = 0; i < data.size(); i++) {
        cout << data.at(i) << "\n";
    }
}

void BSData::printNGrams() {
    nGrams.print();
}