#pragma once

#include "Grafix/Application.hpp"
#include "Grafix/Logger.hpp"

extern Grafix::Application& Grafix::CreateApplication();


int main(int argc, char** argv)
{
    Grafix::Logger::Init();
    GF_CORE_INFO("Logger initialized successfully!");

    Grafix::Application& application = Grafix::CreateApplication();
    application.Run();

    return 0;
}