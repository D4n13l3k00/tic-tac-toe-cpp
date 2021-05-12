#ifdef _WIN32 || _WIN64

    #include <stdlib.h>

    void clearconsole()
    {
        system("cls");
    }

#else

    #include <unistd.h>

    void clearconsole()
    {
        write(1,"\E[H\E[2J",7);
    }

#endif