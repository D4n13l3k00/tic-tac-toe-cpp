#include <unistd.h>

void clearconsole()
{
  write(1, "\E[H\E[2J", 7);
}
