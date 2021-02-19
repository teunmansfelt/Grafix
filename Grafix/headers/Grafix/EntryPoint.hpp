#pragma once

#include "Grafix/Application.hpp"

extern Grafix::Application* Grafix::CreateApplication();

int main(int argc, char** argv)
{
    Grafix::Application* application = Grafix::CreateApplication();
    application->Run();
    delete application;

    return 0;
}