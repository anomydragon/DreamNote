#ifndef DREAMAPPLICATION_H
#define DREAMAPPLICATION_H
#include "DreamBase.h"
#include "Window/Window.h"
#include <GLFW/glfw3.h>
#include <memory>

int main(int argc, char **argv);

namespace Dream
{
    class Application
    {
    public:
        Application();
        virtual ~Application();
    private:
        std::unique_ptr<Window> M_Window;
        bool Running = true;
    private:
        static Application *S_Instance;
        
        friend int ::main(int argc, char **argv);
    };

    //Defined in client
    Application *CreateApp();
}

#endif
