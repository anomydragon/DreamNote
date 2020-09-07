#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <functional>

namespace Dream
{
    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(const std::string &LTitle = "DreamRenderer", unsigned int LWidth = 680, unsigned int LHeight = 480) : Title(LTitle), Width(LWidth), Height(LHeight) {}
    };

    class Window
    {
    public:
        static Window* Create(const WindowProps &WProps = WindowProps());
        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        //virtual void SetEventCallback(const EventCallbackFunc &Callback);
        virtual void EnableVSync(bool Enabled) = 0;
        virtual bool VSyncEnabled() const = 0;
    };
}

#endif
