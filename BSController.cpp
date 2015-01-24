#include "BSController.h"
#include <iostream>
#include <string>
#include "BSMessages.h"


BSController::BSController(){
    this->model = BSModel();
    this->view = BSView();
    this->subject = aSubject();
    this->model.attachObserver(this);
    this->view.attachObserver(this);
    this->subject.attachObserver(this);
    this->model.addDatabase("cities.bs", BSDatatype::city); // Take care to add the right path...
    this->view.menuUI();
    this->subject.test();
}

// This is an abstract method, that needs to be implemented. It's defined in BSObserver.h
void BSController::update(int type) {
    // model operations
    switch (type) {
            break;
        case BSMessages::getSearchStringFinished:
            model.search(view.currentSearchString, BSDatatype::city);
            break;
        case BSMessages::requestDatabaseEntered:
            model.requestDatabase();
            break;
        case BSMessages::requestNGramsEntered:
            model.requestNGrams();
            break;
        default:
            break;
    }
    // view operations
    switch (type) {
        case BSMessages::searchEntered:
            view.searchUI();
        case BSMessages::printDatabaseFinished:
            view.menuUI();
            break;
        case BSMessages::printNGramsFinished:
            view.menuUI();
            break;
        case BSMessages::printResultFinished:
            view.menuUI();
            break;
        case BSMessages::getMenuOperationFinished:
            view.searchUI();
            break;
        case BSMessages::searchFinished:
            view.printResult(model.getSearchResult());
            break;
        case BSMessages::requestDatabaseFinished:
            view.printDatabase(model.getDatabase(BSDatatype::city));
            break;
        case BSMessages::requestNGramsFinished:
            view.printNGrams(model.getNGrams(BSDatatype::city));
            break;
        default:
            break;
    }
}

