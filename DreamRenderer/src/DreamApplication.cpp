#include "DreamApplication.h"

namespace Dream
{
    Application::Application()
    {
        S_Instance = this;
    }

    Application::~Application() = default;
}
