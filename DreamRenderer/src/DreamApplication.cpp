#include "DreamApplication.h"
#include <GLFW/glfw3.h>

namespace Dream
{
    Application *Application::S_Instance = nullptr;

    Application::Application()
    {
        S_Instance = this;
        
        glfwInit();

        M_Window = glfwCreateWindow(640, 480, "Title", NULL, NULL);

        glfwMakeContextCurrent(M_Window);
        glfwSwapInterval(1);

        while(!glfwWindowShouldClose(M_Window))
        {
            glfwPollEvents();
        }
    }

    Application::~Application() = default;
}
