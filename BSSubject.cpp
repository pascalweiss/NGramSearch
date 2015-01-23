//
//  BSSubject.cpp
//  NGramSearch
//
//  Created by Pascal Weiß on 30.12.14.
//  Copyright (c) 2014 Pascal Weiß. All rights reserved.
//

#include "BSSubject.h"

// add an observer
void BSSubject::attachObserver(BSObserver* observer) {
    observers.push_back(observer);
}

// remove an observer
void BSSubject::detachObserver(BSObserver* observer) {
    for (std::list<BSObserver*>::iterator it = observers.begin(); it != observers.end(); it++) {
        if (observer == *it) {
            observers.erase(it);
            break;
        }
    }
}

// notify an observer
void BSSubject::notify(int type) {
    for (std::list<BSObserver*>::iterator it = observers.begin(); it != observers.end(); it++) {
        (*it)->update(type);
    }
}
