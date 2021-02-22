
#include "Grafix/Application.hpp"

#include "Grafix/Events/Event.hpp"
#include "Grafix/Events/ApplicationEvent.hpp"

#include <glfw/glfw3.h>

namespace Grafix
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application(const std::string& name)
        : m_Name(name)
    {
        WindowProperties windowProperties(name.c_str());
        m_Window = std::unique_ptr<Window>(Window::Create(windowProperties));
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }

    Application::~Application()
    {}

    void Application::OnEvent(Event& event)
    {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

        GF_CORE_TRACE("{0}", event);
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

    bool Application::OnWindowClose(Event &event)
    {
        m_Running = false;
        return true;
    }
}
