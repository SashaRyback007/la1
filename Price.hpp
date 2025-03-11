#ifndef PRICE_HPP
#define PRICE_HPP

#include <iostream>
#include <fstream>

struct Price {
    int hryvnias;
    short int kopecks;
    
};
Price add(Price a,Price b);
Price mult(Price a,int gnt);
Price roundTo10(Price m);
void printPrice(Price m);
void processFile();
#endif

