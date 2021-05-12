#ifdef _WIN32 || _WIN64

    #include <windows.h>
    #include <stdlib.h>

    void clearconsole()
    {
        sysytem("cls");
    }

#else

    #include <unistd.h>

    void clearconsole()
    {
        write(1,"\E[H\E[2J",7);
    }

#endif