#include "DreamCore.h"
#include "Window/Window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>

namespace Dream
{
    Application *Application::S_Instance = nullptr;

    Application::Application()
    {
        S_Instance = this;
        
        M_Window = std::unique_ptr<Window>(Window::Create());        

        while(Running)
        {
            glClearColor(1, 0, 0, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            M_Window->OnUpdate();
        }
    }

    Application::~Application() = default;
}
