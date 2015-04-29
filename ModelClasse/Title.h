//
//  Title.h
//  
//
//  Created by Oumar TRAORE on 06/06/2014. // My Brithday Date lol
//
//

#ifndef _Title_h
#define _Title_h

#include <string>

using namespace std;

class Title
{
  private:
    string content;
    int rank;
  public:
    Title();
    ~Title();
    
    string getContent();
    void setContent(string element);
    
    int getRank();
    void setRank();
};

#endif