/* 
 * File:   BSController.h
 * Author: s0544768
 *
 * Created on 8. Dezember 2014, 19:40
 */

#ifndef BSCONTROLLER_H
#define	BSCONTROLLER_H

#include "BSModel.h"
#include "BSView.h"
#include "BSObserver.h"
#include "aSubject.h"

class BSController: BSObserver {
    // These are the subjects, that shall be observed.
    BSModel model;
    BSView view;
    aSubject subject;
public:
    // Constructor
    BSController();
    // This is an abstract method, that needs to be implemented. It's defined in BSObserver.h
    void update(int type);
};

#endif	/* BSCONTROLLER_H */

