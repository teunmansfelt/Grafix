#pragma once

#include "Grafix/Core.hpp"
#include "GFX_PCH.hpp"

#include "Grafix/Window.hpp"
#include "Grafix/Layers/LayerStack.hpp"
#include "Grafix/Events/Event.hpp"

namespace Grafix 
{
    class Application
    {
    public:
        Application(const std::string& name);
        virtual ~Application();

        void Run();
        void OnEvent(Event &event);
    
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        
        inline static Application& GetInstance() { return *s_Instance; }
        inline Window& GetWindow() { return *m_Window; }

    private:
        bool OnWindowClose(Event &event);
        void OnWindowRefresh();

    private:
        std::string m_Name;
        bool m_Running;

        std::unique_ptr<Window> m_Window;
        LayerStack m_LayerStack;
    
    private:
        static Application* s_Instance;
    };

    // To be implemented by the client.
    Application* CreateApplication();
}