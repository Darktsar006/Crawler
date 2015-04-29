//
//  ListLink.h
//  
//
//  Created by Oumar TRAORE on 07/06/2014.
//
//

#ifndef _ListLink_h
#define _ListLink_h

#include <vector>
#include <string>
#include <boost/regex.hpp>
#include "Link.h"

using namespace std;
using namespace boost;

class ListLink
{
private:
    
    vector<Link> linkDone;
    
    
    Link lienCourant; // On met les information du lien courant
    
public:
    ListLink();
    ~ListLink();
    
    vector<Link> linkTC; // Tous les liens à crawler.
    vector<Link> linkC; // Les liens dejà crawler.
    
    
    vector<Link> getLinkTC();
    void setLinkTC(Link link);
    
    void setAllDomaine(string name);
    
    
    vector<Link> getLinkC();
    void setLinkC(Link link);
    
    
    vector<Link> getlinkDone();
    
    void updateLinkTC(string url); // On va mettre à jour la liste de tous les liens à crawler reccurssivement (Add/remove).
    bool dejaCrawler(string url);
    
    void readHtml();
    
    void crawl();
    
    void setAllScore();
    
    //
    void showDomaine();
};


#endif
