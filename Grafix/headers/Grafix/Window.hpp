#pragma once

#include "GF_PCH.hpp"
#include "Grafix/Events/Event.hpp"

namespace Grafix
{
    struct WindowProperties
    {
        std::string Title;
        unsigned int Width, Height;

        WindowProperties(const std::string& title = "Grafix Engine - Default window", 
                         unsigned int width = 1280, 
                         unsigned int height = 720)
            : Title(title), Width(width), Height(height)
        {}
    };

    class Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;
    
        virtual ~Window()
        {}

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;
        virtual unsigned int GetFrameBufferWidth() const = 0;
        virtual unsigned int GetFrameBufferHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;
        virtual bool IsFocused() const = 0;

        static Window* Create(const WindowProperties& properties = WindowProperties());
    };
}