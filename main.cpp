#include <list>
#include <limits>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <iostream>
#include "req/table.hpp"
#include "req/clearscreen.hpp"

using namespace std;

inline bool isInteger(const std::string &s)
{
  if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
    return false;
  char *p;
  strtol(s.c_str(), &p, 10);
  return (*p == 0);
}

string check_win(int match[8][3], string data[9])
{
  for (int i = 0; i < 8; i++)
  {
    if (data[match[i][0]] != "" and data[match[i][1]] != "" and data[match[i][2]] != "" and data[match[i][0]] == data[match[i][1]] and data[match[i][1]] == data[match[i][2]])
    {
      return data[match[i][0]];
    }
  }
  return "";
}

void show_table(string data[9])
{
  tline(1, 3);
  ttable(1, list<string>{data[0], data[1], data[2]}, true);
  tline(1, 3);
  ttable(1, list<string>{data[3], data[4], data[5]}, true);
  tline(1, 3);
  ttable(1, list<string>{data[6], data[7], data[8]}, true);
  tline(1, 3);
}

void fill_table(string data[9])
{
  for (int i = 0; i < 9; i++)
  {
    data[i] = "";
  }
}

int main()
{
  // 3x3 table
  string data[9];

  // all winning combinations
  int match[8][3]{
      {0, 1, 2},
      {3, 4, 5},
      {6, 7, 8},
      {0, 3, 6},
      {1, 4, 7},
      {2, 5, 8},
      {0, 4, 8},
      {2, 4, 6}};

  // fill table with empty strings
  fill_table(data);

  // initialize first player
  string player = "X";

  // user input
  string step_coords;

  // game loop
  while (true)
  {
    // answer loop
    while (true)
    {
      clearconsole();
      show_table(data);
      cout << endl
           << player << " > ";
      cin >> step_coords;
      // check input on correct format
      if (isInteger(step_coords) and stoi(step_coords) > 0 and stoi(step_coords) < 10 and data[stoi(step_coords) - 1] == "")
      {
        data[stoi(step_coords) - 1] = player;
        break;
      }
    }

    // check if someone won
    string check = check_win(match, data);

    // if someone won, break the loop and congratulate the winner
    if (check != "")
    {
      clearconsole();
      show_table(data);
      cout << endl
           << check << " won! Press enter to restart...";
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin.get();
      fill_table(data);
      player = "X";
    }

    // if no one won, switch players
    else
    {
      // check on draw
      bool draw = true;
      for (int i = 0; i < 9; i++)
      {
        if (data[i] == "")
        {
          draw = false;
          break;
        }
      }
      if (draw)
      {
        clearconsole();
        show_table(data);
        cout << endl
             << "Draw! Press enter to restart...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        for (int x = 0; x < 9; x++)
        {
          data[x] = "";
        }
        player = "X";
      }
      // else switch players
      else
      {
        player = (player == "X" ? "O" : "X");
      }
    }
  }
  return 0;
}
