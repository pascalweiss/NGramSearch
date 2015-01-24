#include "BSNGrams.h"
#include <iostream>
#include <sstream>


BSNGrams::BSNGrams(int numberOfCharacters): n(numberOfCharacters), data() {
}

map<string, vector<int> > BSNGrams::getNGrams() {
    return data;
}

bool BSNGrams::addString(string element, int index) {
    vector<string> nGrams = splitIntoNGrams(element);
    for (vector<string>::iterator nGram = nGrams.begin(); nGram != nGrams.end(); nGram++) {
        if (data.count(*nGram) == 1) {       // Jeder key existiert max. 1 mal.
            data[*nGram].push_back(index);   // Wenn ein key bereits existiert:
        }
        else {
            data.insert(make_pair(*nGram, vector<int>()));
            data[*nGram].push_back(index);   // Wenn ein key noch nicht existiert:
        }
    }
    return false;
}

vector<string> BSNGrams::splitIntoNGrams(string str) {
    vector<string> nGrams;
    for (int i = 0; i < str.length() - n + 1; i++) {
        string nGram = str.substr(i, n);
        nGrams.push_back(nGram);
    }
    return nGrams;
}


// first element is the index, that points to an element in BSData.data.
// second element is the score for the element. The higher the score, the more appropriate is the element.
map<int, int> BSNGrams::search(string str) {
    map<int, int> result;
    vector<int> indxes;
    vector<string> nGrams = splitIntoNGrams(str);
    for (vector<string>::iterator nGram = nGrams.begin(); nGram != nGrams.end(); nGram++) {
        indxes = data[*nGram];
        while (!indxes.empty()) {
            int idx = indxes.back();
            indxes.pop_back();
            if (result.count(idx) == 1) { // Wenn der key bereits existiert..
                result[idx]++;            // score um 1 erhöhen.
            }
            else {                        // Wenn der key nicht existiert..
                result[idx] = 1;          // score anlegen.
            }
        }
    }
    return result;
}

void BSNGrams::print() {
    string key;
    vector<int> vek;
    for(map<string, vector<int> >::iterator it = data.begin(); it != data.end(); ++it) {
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
}