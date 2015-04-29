//
//  H1.h
//  
//
//  Created by Oumar TRAORE on 06/06/2014. // My Brithday Date lol
//
//

#ifndef _H1_h
#define _H1_h

#include <string>

using namespace std;

class H1
{
private:
    int rank;
    string content;
    
    //int linkId;
public:
    H1();
    ~H1();
    
    int getRank();
    void setRank(string element);
    
    string getContent(); // Pour la base de donnée lors de la recherche
    void setContent(string element);
};


#endif
