//
//  H1.cpp
//  
//
//  Created by Oumar TRAORE on 06/06/2014.
//
//

#include "H1.h"

H1::H1()
{
    rank = 0;
}

H1::~H1()
{
  
}

int H1::getRank()
{
    return rank;
}

void H1::setRank(string element)
{
    // A chaque fois qu'un titre apparait on le rajoute 1 point (h1 - h1- h3)
    if(element.size() < 55)
        rank =+2;
    else
      rank++;
}

string H1::getContent()
{
    return content;
}

void H1::setContent(string element)
{
    content = element;
}