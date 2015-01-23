
#include "BSModel.h"
#include <iostream>
#include "BSMessages.h"

using namespace std;

// Initializes the database. Should be called first!

bool BSModel::addDatabase(string fileName, int type) {
    switch (type) {
        case BSDatatype::city:
            return cityData.importFromFile(fileName, type);
        default:
            break;
    }
    return false;
}



// Operations, that notify it's observers

void BSModel::search(string str, int type) {
    // Just in case you want to add further databases. You can distinguish them here
    switch (type) {
        case BSDatatype::city:
            search(str, cityData);
            notify(BSMessages::searchFinished);
            break;
        default:
            break;
    }
}

void BSModel::requestDatabase() {
    notify(BSMessages::requestDatabaseFinished);
}

void BSModel::requestNGrams() {
    notify(BSMessages::requestNGramsFinished);
}



// Some getter methods for the requested data

map<string, vector<int> > BSModel::getNGrams(int type) {
    switch (type) {
        case BSDatatype::city:
            return cityData.getNGrams();
            break;
        default:
            break;
    }
    return map<string, vector<int> >();
}

vector<pair<string, int> > BSModel::getSearchResult() {
    return searchResult;
}

vector<string> BSModel::getDatabase(int type) {
    switch (type) {
        case BSDatatype::city:
            return cityData.getDatabase();
        default:
            break;
    }
    return vector<string>();
}




// private method for data processing

bool sortComparison(pair<string, int> p1, pair<string, int> p2) {
    if (p1.second < p2.second) {
        return true;
    }
    return false;
}

void BSModel::search(string str, BSData data) {
    vector<pair<string, int> > searchResult = data.search(str);
    sort(searchResult.begin(), searchResult.end(), sortComparison);
    this->searchResult = searchResult;
}
