//
//  VSMRetrieval
//  comp433
//
//  Created by Jimmy Au on 15/12/12.
//  Copyright (c) 2012 ECJMT. All rights reserved.
//

#ifndef __comp433__VSMRetrieval__
#define __comp433__VSMRetrieval__

#include "RetrievalModel.h"
#include <string>

class DataLoader;

class VSMRetrieval : public RetrievalModel
{
public:
    VSMRetrieval(DataLoader *dataLoader);
    virtual void retrieve(std::string query);
    
private:
    DataLoader *dataLoader;
};


#endif /* defined(__comp433__VSMRetrieval__) */
