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
#include "stem.h"

class DataLoader;

class VSMRetrieval : public RetrievalModel
{
public:
    VSMRetrieval(DataLoader *dataLoader);
    virtual void retrieve(std::string query, std::ofstream& ofs);
    
private:
    DataLoader *dataLoader;
	stemmer stm;
};


#endif /* defined(__comp433__VSMRetrieval__) */
