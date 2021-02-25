
#include "Grafix/Application.hpp"

#include "Grafix/Events/Event.hpp"
#include "Grafix/Events/ApplicationEvent.hpp"

#include <glad/glad.h>

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

    void Application::Run()
    {
        m_Running = true;
        while (m_Running)
        {
            glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            for(Layer* layer : m_LayerStack)
                layer->OnUpdate();

            m_Window->OnUpdate();
        }
    }

    void Application::OnEvent(Event& event)
    {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

        GF_CORE_TRACE("{0}", event);

        for (auto iter = m_LayerStack.end(); iter != m_LayerStack.begin(); )
        {
            (*--iter)->OnEvent(event);
            if (event.IsHandled())
                break;
        }
    }

    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer* overlay)
    {
        m_LayerStack.PushOverlay(overlay);
    }

    bool Application::OnWindowClose(Event &event)
    {
        m_Running = false;
        return true;
    }
}
