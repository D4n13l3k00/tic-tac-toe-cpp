#include <list>
#include <limits>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <iostream>
#include "req/table.h"
#include "req/clearscreen.h"

using namespace std;

inline bool isInteger(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
   char * p;
   strtol(s.c_str(), &p, 10);
   return (*p == 0);
}

string check_win(int match[8][3], string data[9]) {
    for(int i = 0; i < 8; i++) {
        if(data[match[i][0]] != "" and data[match[i][1]] != "" and data[match[i][2]] != "" and data[match[i][0]] == data[match[i][1]] and data[match[i][1]] == data[match[i][2]]) {
            return data[match[i][0]];
        }
    }
    return "";
}

void show_table(string data[9]) {
    tline(1, 3);
    ttable(1, list<string>{data[0], data[1], data[2]}, true);
    tline(1, 3);
    ttable(1, list<string>{data[3], data[4], data[5]}, true);
    tline(1, 3);
    ttable(1, list<string>{data[6], data[7], data[8]}, true);
    tline(1, 3);
}

int main() {
    string data[9];
    int match[8][3] {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7 ,8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };
    for(int x = 0; x < 9;x++) {
        data[x] = "";
    }
    string player = "X";
    while(true) {
        while(true) {
            clearconsole();
            show_table(data);
            string var;
            cout << player << " > ";
            cin >> var;
            if(isInteger(var) and 10 > stoi(var) > 0 and data[stoi(var)-1] == "") {
                data[stoi(var)-1] = player;
                break;
            }
            
        }
        string check = check_win(match, data);
        if(check != "") {
            clearconsole();
            show_table(data);
            cout << check << " won! Press enter to restart...";
            cin.ignore( numeric_limits <streamsize> ::max(), '\n' );
            cin.get();
            for(int x = 0; x < 9;x++) {
                data[x] = "";
            }
            player == "X";
        }
        else {
            if(player == "X") {
                player = "O";
            } else {
                player = "X";
            }
        }
    }
    return 0;
}