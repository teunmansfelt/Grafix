#pragma once

#include "Grafix/Window.hpp"

#include <glfw/glfw3.h>

namespace Grafix
{
    class MacWindow : public Window
    {
    public:
        MacWindow(const WindowProperties& properties);
        virtual ~MacWindow();

        void OnUpdate() override;

        inline unsigned int GetWidth() const override { return m_Data.Width; }
        inline unsigned int GetHeight() const override { return m_Data.Height; }
        inline unsigned int GetFrameBufferWidth() const override { return m_Data.FrameBufferWidth; }
        inline unsigned int GetFrameBufferHeight() const override { return m_Data.FrameBufferHeight; }

        inline void SetEventCallback(const EventCallbackFn& callback) override { 
            m_Data.EventCallback = callback; 
        }
        void SetVSync(bool enabled) override;
        inline bool IsVSync() const override { return m_Data.VSync; }
        inline bool IsFocused() const override { return m_Data.Focus; }

    private:
        virtual void Init(const WindowProperties& properties);
        virtual void Shutdown();

    private:
        GLFWwindow* m_Window;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            unsigned int FrameBufferWidth, FrameBufferHeight;
            bool VSync;
            bool Focus;
            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    };
}