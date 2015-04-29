//
//  Keyword.cpp
//  
//
//  Created by Oumar TRAORE on 10/06/2014.
//
//

#include "Meta.h"

#include <iostream>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

Meta::Meta()
{
    rank = 0;
}

string Meta::getContent()
{
    return content;
}

void Meta::setContent(string element)
{
    content = element;
}

int Meta::getRank()
{
  return rank;
}

void Meta::setRank(int type)
{
  switch(type)
  {
    case 1: // Dans le cas d'une meta description Correcte
      if(content.size() > 70 && content.size() < 160)
	rank += 2;
      else // Sinon on l'encourage voilà on le met 1 point
	rank++;
      break;
    case 2: // Dans le cas meta keyword
      vector<string> keyFound;
      
      split(keyFound, content, is_any_of(".*,"));
      
      // Si il a decrit un multiple de 5 de Keyword on lui rajoute +(x) points (5 = 1 points - 10 (-14) = 2 - 25 = 5)
      rank += keyFound.size() / 5;
      
      break;
  }
}