#include <iostream>
#include <fstream>
#include "Price.hpp" 
using namespace std;


void add(Price a, Price b, Price &result) {
    result.hryvnias = a.hryvnias + b.hryvnias;
    result.kopecks = a.kopecks+ b.kopecks;
    if (result.kopecks >= 100) { 
        result.hryvnias++;
        result.kopecks -= 100;
    }
}


void mult(Price p, int quantity, Price &result) {
    int total = (p.hryvnias * 100 + p.kopecks) * quantity;
    result.hryvnias = total / 100;
    result.kopecks = total % 100;
}


void roundTo10Kop(Price &p) {
    int total = (p.hryvnias * 100 + p.kopecks + 5) / 10 * 10;
    p.hryvnias = total / 100;
    p.kopecks = total % 100;
}


void processFile() {
    std::ifstream file("C:\\Projects\\la1\\prices.txt");
    if (!file) { 
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }

    Price total = {0, 0};  
    int h, k, q;

    cout << "Чек:\n";

    while (file >> h >> k >> q) { 
        Price temp = {h, k}; 
        Price itemTotal;
        mult(temp, q, itemTotal); 
        add(total, itemTotal, total); 
       
        
        cout << q << " шт. × " << h << " грн " << k << " коп = " 
             << itemTotal.hryvnias << " грн " << itemTotal.kopecks << " коп\n";
    }

    roundTo10Kop(total);
    
   
    cout << "Загальна сума (після округлення): " << total.hryvnias << " грн " << total.kopecks << " коп\n";
}