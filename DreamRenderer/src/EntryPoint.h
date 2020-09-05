#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include "DreamBase.h"
#include <iostream>

extern Dream::Application* Dream::CreateApp();

int main(int argc, char **argv)
{
    std::cout << "Hello world from entrypoint" << std::endl;

    auto App = Dream::CreateApp();

    delete App;

    return 0;
}

#endif
