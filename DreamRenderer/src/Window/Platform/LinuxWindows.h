#ifndef LINUXWINDOWS_H
#define LINUXWINDOWS_H
#include "../Window.h"
#include <GLFW/glfw3.h>
#include <string>

namespace Dream
{
    class LinuxWindows : public Window
    {
    private:
        GLFWwindow *M_Window;
        
        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;
        };

        WindowData M_WData;

    public:
        LinuxWindows(const WindowProps &WProps);
        virtual ~LinuxWindows();

        void OnUpdate() override;

        unsigned int GetWidth() const override { return M_WData.Width; }
        unsigned int GetHeight() const override{ return M_WData.Height; }

        void EnableVSync(bool Enabled) override;
        bool VSyncEnabled() const override { return M_WData.VSync; }

        virtual void *GetNativeWindow() const { return M_Window; }
    private:
        virtual void Init(const WindowProps &WProps);
        virtual void Shutdow();
    };
}

#endif
