#pragma once

#include "Grafix/Layers/Layer.hpp"

#include "Grafix/Events/Event.hpp"
#include "Grafix/Events/KeyEvent.hpp"
#include "Grafix/Events/MouseEvent.hpp"
#include "Grafix/Events/ApplicationEvent.hpp"

namespace Grafix
{
    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Event& event) override;
    
    private:
        bool OnMouseMovedEvent(MouseMovedEvent& event);
        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent &event);
        bool OnMouseScrolledEvent(MouseScrolledEvent& event);
        bool OnKeyPressedEvent(KeyPressedEvent& event);
        bool OnKeyReleasedEvent(KeyReleasedEvent& event);
        bool OnKeyTypedEvent(KeyTypedEvent& event);

    private:
        float m_Time = 0.0f;
        static bool s_MouseJustPressed[];
    };
}