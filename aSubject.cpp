//
//  aSubject.cpp
//  NGramSearch
//
//  Created by Pascal Weiß on 23.01.15.
//  Copyright (c) 2015 Pascal Weiß. All rights reserved.
//

#include "aSubject.h"
#include <iostream>
void aSubject::test() {
    std::cout << "Hi Observer and Subject";
    notify(10000);
}