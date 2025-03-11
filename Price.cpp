#include <iostream>
#include <fstream>

struct Price
{
    int hryvnias;
    short int kopecks;
};

Price add(Price result, Price other) {
    int totalKopecks = (result.hryvnias * 100 + result.kopecks) + 
                       (other.hryvnias * 100 + other.kopecks);
    result.hryvnias = totalKopecks / 100;
    result.kopecks = totalKopecks % 100;
    return result;
}



Price mult(Price result, int quantity) {
    int totalKopecks = (result.hryvnias * 100 + result.kopecks) * quantity;
    result.hryvnias = totalKopecks / 100;
    result.kopecks = totalKopecks % 100;
    return result;
}

void roundToNearest10(Price& result) {
    int roundedKopecks = ((result.kopecks + 5) / 10) * 10;
    if (roundedKopecks == 100) {
        result.hryvnias += 1;
        result.kopecks = 0;
    } else {
        result.kopecks = roundedKopecks;
    }
}


void printPrice(Price result) {
    std::cout << result.hryvnias << " грн " << result.kopecks << " коп" << std::endl;
}

void processFile() {
    std::ifstream file("C:\\Projects\\la1\\prices.txt");
    if (!file) {
        std::cerr << "Не вдалося відкрити файл!" << std::endl;
    }

    Price total = {0, 0};

    int hryvnias, kopecks, quantity;
    while (file >> hryvnias >> kopecks >> quantity) {
        Price item = {hryvnias, kopecks};
        total = add(total, mult(item, quantity));
    }
    
    file.close();

    std::cout << "Загальна сума: ";
    printPrice(total);

    roundToNearest10(total);
    std::cout << "Сума до оплати (після заокруглення): ";
    printPrice(total);

}