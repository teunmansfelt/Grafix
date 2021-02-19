#pragma once

#include "GF_PCH.hpp"

namespace Grafix 
{
    class Application
    {
    public:
        Application(const std::string& name);
        virtual ~Application();

        void Run();
    
    private:
        std::string m_Name;
    };

    // To be implemented by the client.
    Application* CreateApplication();
}