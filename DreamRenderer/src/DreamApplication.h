#ifndef DREAMAPPLICATION_H
#define DREAMAPPLICATION_H
#include "DreamBase.h"

int main(int argc, char **argv);

namespace Dream
{
    class Application
    {
    public:
        Application();
        virtual ~Application();
    private:
        static Application *S_Instance;
        friend int ::main(int argc, char **argv);
    };

    //Defined in client
    Application *CreateApp();
}

#endif
