//
//  ListLink.cpp
//  
//
//  Created by Oumar TRAORE on 07/06/2014.
//
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#include "ListLink.h"

ListLink::ListLink()
{   
    
}

ListLink::~ListLink()
{
  
}

vector<Link> ListLink::getLinkTC()
{
    return linkTC;
}

void ListLink::setLinkC(Link link)
{
    linkC.push_back(link);
}

void ListLink::setLinkTC(Link link)
{
    linkTC.push_back(link);
}

vector<Link> ListLink::getLinkC()
{
  return linkC;
}

bool ListLink::dejaCrawler(string url)
{
  for(int i = 0; i < (int)linkC.size(); i++)
  {
    if(url.compare(linkC[i].getContent()) == 0)
      return false;
  }
  
  return true;;
}

vector<Link> ListLink::getlinkDone()
{
  return linkDone;
}

void ListLink::updateLinkTC(string ligne)
{
    if(dejaCrawler(ligne))
    {
      Link newLink;
      newLink.setContent(ligne);
      newLink.setDomaine(lienCourant.getDomaine());
      
      // On l'ajoute à la liste des éléments à crawler
      linkTC.push_back(newLink);
      linkC.push_back(newLink);
    }
}

void ListLink::readHtml()
{
    // On ouvre le fichier en lecture
    FILE* fichier = NULL;
    
    
    fichier = fopen("Http/temp.txt", "r");
    
    // Booléean match qui verifie si une expression régulière est correcte.
    bool match = false;
    
    int buffer = 1000;
    char lignes[buffer];
    
    // On charge nos expression régulière
    regex aLink("<a([^>]+)>(.+?)</a>");
    regex aLink2(".*href=\"(../)*(.*)\"");
    regex http("(http://)|(.*#.*)|(https://)");
    
    
    regex aH("<h(.*)>(<.*>)(.*)(<.*>)</h1>");
    
    
    regex description("<meta name=\"description\"([^>]+)>");
    regex description1("(.*)content=\"(.*)\"(.*)");
    
    regex keywords("<meta name=\"keywords\"([^>]+)>");
    regex keywords1("(.*)content=\"(.*)\"(.*)");
    
    regex titleT("<title>(.*)</title>");
    
    // contenu du résultat matcher (En l'occurence je vais avoir 2 groupe la balise entiere et son contenu).
    smatch res;
    
    cout << "I'm here"<< endl;
    
    if(fichier)
    {
        while(fgets(lignes, buffer, fichier) != NULL) // On le parcours ligne par ligne
        {
            string ligne = lignes;
	    
	    // On recherche le <title>Titre de la page</title>
	    match = regex_search(ligne, res, titleT);
	    if(match)
	    {
	      ligne = res[1];
	      lienCourant.setTitle(ligne);
	    }
	    ligne = lignes;
	    
            // On recherche les liens.
            match = regex_search(ligne, res, aLink);
            if(match)
            {
                ligne = res[1];
                match = regex_search(ligne, res, aLink2);
                if(match)
		{
		    // Lien Trouver
		    ligne = res[2]; 
		    
		    match = regex_search(ligne, res, http);
		    
		    if(!match)
		    {
			if(ligne[0] == '/')
			  ligne = ligne;
			else
			  ligne = "/" + ligne;
			  
			  ListLink::updateLinkTC(ligne); // Si le lien trouver dans la page n'existe pas dans la liste des lien n'est pas repertorier.
		    }
		    
                }
            }
            ligne = lignes;
            
            // On recupère la description de la page si jamais ça existe.
            match = regex_search(ligne, res, description);
            if(match)
            {
                ligne = res[1];
                
                match = regex_search(ligne, res, description1);
                if(match)
                {
                    
                    Meta meta;
                    meta.setContent(res[2]);
                    lienCourant.addVectorMeta(meta);
                }

            }
            ligne = lignes;
            
            // On recupère les keywords de la page si jamais ça existe.
            match = regex_search(ligne, res, keywords);
            if(match)
            {
                ligne = res[1];
                match = regex_search(ligne, res, keywords1);
                if(match)
                {
                    
                    Meta meta;
                    meta.setContent(res[2]);
                    lienCourant.addVectorMeta(meta);
                }
                
            }
            ligne = lignes;

            
            // Si il a trouver un Titre h1 - h2 - h2 (Pour le calcul du score).
            match = regex_search(ligne, res, aH);
            if(match)
            {
                H1 h1;
                h1.setContent(res[3]);
                lienCourant.addVectorH1(h1);
            }
        }
        
        // Ensuite on forme le fichier
        fclose(fichier);
    }
    else
    {
        cout << "Not file" << endl;
    }
}

void ListLink::setAllDomaine(string name)
{
    Link startUrl;
    startUrl.setDomaine(name);
    
    linkTC.push_back(startUrl);
}

void ListLink::setAllScore()
{
  for(int i = 0; i < (int)linkDone.size(); i++)
  {
    linkDone[i].setRank();
  }
}

void ListLink::crawl()
{
    //cout << linkTC[0].getDomaine() << endl;
    
    if(!linkTC.empty())
    {
      lienCourant = linkTC[linkTC.size()-1];
      
      // On construit notre appel système avec curl, pour recuperer une page html.
      string getUrl = "curl ";
      
      
      getUrl.append(lienCourant.getDomaine());
      getUrl.append(lienCourant.getContent());
      getUrl.append(" > Http/temp.txt");
      
      
      cout << getUrl << endl;
      
      const char *urlcurrent = getUrl.c_str();
      
      system(urlcurrent);
      
      // Traitement de la page
      ListLink::readHtml();
      
      linkDone.push_back(lienCourant);
      
      // Lorsqu'on n'a finit de crawler ce lien on l'enlève de la liste des liens à recrawler
      linkTC.pop_back();
      
      
      if(!linkTC.empty())
      {
	  ListLink::crawl(); // Manque plus ka créer un opérateur d'affectation pour mettre à jour liencourant
	  // lorsque l'on fait le pop juste un peu plus haut lol :)
      }

    }      
}

// Debug

void ListLink::showDomaine()
{
  for(int i = 0; i< (int)linkTC.size(); i++)
  {
    cout << linkTC[i].getDomaine() << endl;
  }
}

