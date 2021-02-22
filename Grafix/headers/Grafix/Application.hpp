#pragma once

#include "GF_PCH.hpp"
#include "Grafix/Window.hpp"

namespace Grafix 
{
    class Application
    {
    public:
        Application(const std::string& name);
        virtual ~Application();

        void OnEvent(Event& event);

        void Run();
    
    private:
        std::string m_Name;
        std::unique_ptr<Window> m_Window;
        bool m_Running;
    };

    // To be implemented by the client.
    Application* CreateApplication();
}