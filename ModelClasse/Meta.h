//
//  Keyword.h
//  
//
//  Created by Oumar TRAORE on 10/06/2014.
//
//

#ifndef _Meta_h
#define _Meta_h

#include <string>

using namespace std;


class Meta
{
private:
    string content;
    int rank;
    
    int linkId;
public:
    Meta();
    
    string getContent();
    void setContent(string element);
    
    
    int getRank();
    void setRank(int type);
};

#endif
