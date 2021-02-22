#pragma once

#include "GF_PCH.hpp"
#include "Grafix/Events/Event.hpp"

namespace Grafix
{
    class Layer
    {
    protected:
        Layer(const std::string& name = "Layer");
    public:
        virtual ~Layer();
    
    public:
        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event& event) {}

        inline const std::string& GetName() const { return m_DebugName; }

    protected:
        std::string m_DebugName;
    };
}