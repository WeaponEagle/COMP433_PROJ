//
//  RetrievedDocument.h
//  comp433
//
//  Created by Jimmy Au on 16/12/12.
//  Copyright (c) 2012 ECJMT. All rights reserved.
//

#ifndef comp433_RetrievedDocument_h
#define comp433_RetrievedDocument_h

class DocRec;
struct RetrievedDocument
{
    int documentId;
    double similarity;
	DocRec* docRec;
};

#endif
