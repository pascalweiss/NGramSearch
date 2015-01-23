/* 
 * File:   BSModel.h
 * Author: s0544768
 *
 * Created on 8. Dezember 2014, 19:34
 */

#ifndef BSMODEL_H
#define	BSMODEL_H

#include "BSData.h"
#include <string>
#include <vector>
#include "BSSubject.h"


using namespace std;

class BSModel: public BSSubject {
    BSData cityData;
    vector<pair<string, int> > searchResult;
    // private method for data processing
    void search(string str, BSData data);
    
public:
    // Initializes the database. Should be called first!
    bool addDatabase(string fileName, int type);
    // Operations, that notify it's observers
    void search(string str, int type);
    void requestDatabase();
    void requestNGrams();
    // Some getter methods for the requested data
    vector<string> getDatabase(int type);
    map<string, vector<int> > getNGrams(int type);
    vector<pair<string, int> > getSearchResult();
};


#endif	/* BSMODEL_H */

