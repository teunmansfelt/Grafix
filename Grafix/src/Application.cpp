
#include "Grafix/Application.hpp"

namespace Grafix
{
    Application::Application(const std::string& name)
        : m_Name(name)
    {}

    Application::~Application()
    {}

    void Application::Run()
    {
        while (true);
    }
}
