//
//  RetrievalModel.h
//  comp433
//
//  Created by Jimmy Au on 16/12/12.
//  Copyright (c) 2012 ECJMT. All rights reserved.
//

#ifndef comp433_RetrievalModel_h
#define comp433_RetrievalModel_h

#include <string>

class RetrievalModel
{
    virtual void retrieve(std::string query) = 0;
};


#endif
