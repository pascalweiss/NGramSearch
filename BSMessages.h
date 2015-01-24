//
//  BSMessages.h
//  NGramSearch
//
//  Created by Pascal Weiß on 22.01.15.
//  Copyright (c) 2015 Pascal Weiß. All rights reserved.
//

#ifndef __NGramSearch__BSMessages__
#define __NGramSearch__BSMessages__

#include <stdio.h>

class BSMessages {
public:
    static const int searchFinished = 0;
    static const int requestDatabaseFinished = 1;
    static const int requestNGramsFinished = 2;
    static const int searchEntered = 3;
    static const int requestDatabaseEntered = 4;
    static const int requestNGramsEntered = 5;
    static const int getMenuOperationFinished = 6;
    static const int getSearchStringFinished = 7;
    static const int printDatabaseFinished = 8;
    static const int printResultFinished = 9;
    static const int printNGramsFinished = 10;
};
#endif /* defined(__NGramSearch__BSMessages__) */
