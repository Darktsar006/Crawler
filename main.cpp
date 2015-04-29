#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "ModelClasse/Link.h"
#include "ModelClasse/ListLink.h"
#include "Dba/DbaLink.h"

#include <regex>

using namespace std;

int main(int argc, char *argv[])
{
    ListLink crawler;
    
    DbaLink dba;
    
    // Phase de recuperation des liens à crawler (Domaine).
    dba.setStartLink(&crawler);
    
    // Phase de recuperation des liens deja crawler
    dba.doUpdateCrawl();
    
    // Phase de crawl
    crawler.crawl();
    
    // Phase de calcul de score
    crawler.setAllScore();
    
    // On passe à la phase d'enregistrement en Database
    dba.setCrawl(crawler);
    
    
    // Phase de fermeture de connection
    dba.closeConnection();
    
    return 0;
}
