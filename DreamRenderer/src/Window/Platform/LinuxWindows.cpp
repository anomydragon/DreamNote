#include "LinuxWindows.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <cstdint>
#include <stdexcept>

namespace Dream
{
    static uint8_t L_GLFWWindowCount = 0;

    Window* Window::Create(const WindowProps &WProps)
    {
        return new LinuxWindows(WProps);
    }
        
    LinuxWindows::LinuxWindows(const WindowProps &WProps)
    {
        Init(WProps);
    }

    LinuxWindows::~LinuxWindows()
    {
        Shutdow();
    }

    void LinuxWindows::Init(const WindowProps &WProps)
    {
        M_WData.Title = WProps.Title;
        M_WData.Width = WProps.Width;
        M_WData.Height = WProps.Height;

        if(L_GLFWWindowCount == 0)
        {
            if(!glfwInit())
                throw std::runtime_error("Failed to Initialize glfw");
        }

        M_Window = glfwCreateWindow((int)WProps.Width, (int)WProps.Height, WProps.Title.c_str(), nullptr, nullptr);
        ++L_GLFWWindowCount;

        glfwMakeContextCurrent(M_Window);
        glfwSetWindowUserPointer(M_Window, &M_WData);

        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            throw std::runtime_error("Failed to load Glad");

        EnableVSync(true);
    }

    void LinuxWindows::Shutdow()
    {
        glfwDestroyWindow(M_Window);
        --L_GLFWWindowCount;

        if(L_GLFWWindowCount == 0)
            glfwTerminate();
    }

    void LinuxWindows::OnUpdate()
    {
        glfwSwapBuffers(M_Window);
        glfwPollEvents();
    }

    void LinuxWindows::EnableVSync(bool Enabled)
    {
        if(Enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        M_WData.VSync = Enabled;
    }

}
