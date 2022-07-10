#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <list>
#include <iomanip>
#include <string> 

void ttable(
    int width, std::list<std::string> columns,
    bool toleft);
void tline(int width,
int columns);

#endif