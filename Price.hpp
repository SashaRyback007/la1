#ifndef PRICE_HPP
#define PRICE_HPP

#include <iostream>
#include <fstream>

struct Price {
    int hryvnias;
    short int kopecks;
    
};
void add(Price a, Price b, Price &result);
void mult(Price p, int quantity, Price &result);
void roundTo10Kop(Price &p);
void processFile(); 
#endif

