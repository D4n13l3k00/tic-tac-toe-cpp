#include <iostream>
#include <list>
#include <iomanip>
#include <string> 

void ttable(int width,
    std::list<std::string> columns,
    bool toleft) {
    std::cout << "| ";
    for(std::string str : columns) {
        std::cout << std::setw(width);
        if (toleft) { std::cout << std::left; }
        std::cout << str << std::setw(3) << " | ";
    }
    std::cout << std::endl;
}
void tline(int width, int columns) {
    std::cout << "|";
    for(int x = 0; x != columns; x++) {
        std::cout
            << std::string(width+2, '-')
            << "|";
    }
    std::cout << std::endl;
}