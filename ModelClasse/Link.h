//
//  Link.h
//  
//
//  Created by Oumar TRAORE on 06/06/2014.
//
//

#ifndef _Link_h
#define _Link_h

#include <iostream>
#include <vector>
#include <string>

#include "H1.h"
#include "Meta.h"
#include "Title.h"

using namespace std;

class Link
{
private:
    string content;
    
    Title title;
    
    int rank;
    
    vector<Meta> meta; // 2 types de meta (name="description" - name="keywords") on les charges dans une liste
    // pour l'ajouter à la base de donnée plus tard (int identifiant - ki identifiera le lien) 
    
    vector<H1> h1;
    //list<Paragraphe> p;
    
    string domaine;
    
public:
    Link();
    ~Link();
    
    Link &operator=(const Link &j);
    
    string getContent();
    void setContent(string url);
    
    void addVectorH1(H1 element);
    void addVectorMeta(Meta element);
    
    void setTitle(string titre);
    string getTitle();
    
    int getRank();
    void setRank();
    
    void setDomaine(string name);
    string getDomaine();
    
    vector<Meta> getMeta();
};


#endif