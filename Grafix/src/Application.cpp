
#include "Grafix/Application.hpp"

#include <glfw/glfw3.h>

namespace Grafix
{
    Application::Application(const std::string& name)
        : m_Name(name)
    {
        WindowProperties windowProperties(name.c_str());
        m_Window = std::unique_ptr<Window>(Window::Create(windowProperties));
        m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
    }

    Application::~Application()
    {}

    void Application::OnEvent(Event& event)
    {
        GF_CORE_INFO("{0}", event);
    }

    void Application::Run()
    {
        m_Running = true;
        while (m_Running)
        {
            glClearColor(0.0f, 0.15f, 0.3f, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }
}
