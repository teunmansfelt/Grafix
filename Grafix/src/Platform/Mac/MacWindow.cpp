
#include "Grafix/Platform/Mac/MacWindow.hpp"

#include "Grafix/Core.hpp"

namespace Grafix
{
    Window* Window::Create(const WindowProperties &properties)
    {
        return new MacWindow(properties);
    }

    MacWindow::MacWindow(const WindowProperties& properties)
    {
        Init(properties);
    }

    MacWindow::~MacWindow()
    {
        Shutdown();
    }

    void MacWindow::Init(const WindowProperties& properties)
    {
        m_Data.Title = properties.Title;
        m_Data.Width = properties.Width;
        m_Data.Height = properties.Height;

        GF_CORE_INFO("Creating window {0} (w:{1}, h:{2})", m_Data.Title, m_Data.Width, m_Data.Height);

        static bool s_GlfwInitialized = false;
        if (!s_GlfwInitialized)
        {
            int success = glfwInit();
            GF_CORE_ASSERT(success, "Could not initialize GLFW!");
            s_GlfwInitialized = true;
        }
        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
    }

    void MacWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    void MacWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void MacWindow::SetVSync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else   
            glfwSwapInterval(0);
        
        m_Data.VSync = enabled;
    }
}