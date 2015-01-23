//
//  BSObserver.h
//  NGramSearch
//
//  Created by Pascal Weiß on 30.12.14.
//  Copyright (c) 2014 Pascal Weiß. All rights reserved.
//

#ifndef __NGramSearch__BSObserver__
#define __NGramSearch__BSObserver__

class BSObserver {
public:
    virtual void update(int type) = 0;
};

#endif /* defined(__NGramSearch__BSObserver__) */
