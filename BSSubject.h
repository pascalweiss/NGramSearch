//
//  BSSubject.h
//  NGramSearch
//
//  Created by Pascal Weiß on 30.12.14.
//  Copyright (c) 2014 Pascal Weiß. All rights reserved.
//

#ifndef __NGramSearch__BSSubject__
#define __NGramSearch__BSSubject__

#include "BSObserver.h"
#include <list>

class BSSubject {
private:
    // All the observers, that shall be notified, are stored here
    std::list <BSObserver*> observers;
public:
    // add an observer
    void attachObserver(BSObserver* observer);
    // remove an observer
    void detachObserver(BSObserver* observer);
    // notify an observer
    void notify(int type);
};

#endif /* defined(__NGramSearch__BSSubject__) */
