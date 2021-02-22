
#include "Grafix/Platform/Mac/MacWindow.hpp"

#include "Grafix/Core.hpp"

#include "Grafix/Events/KeyEvent.hpp"
#include "Grafix/Events/MouseEvent.hpp"
#include "Grafix/Events/ApplicationEvent.hpp"

namespace Grafix
{
    static void GLFWErrorCallback(int error, const char* message)
    {
        GF_CORE_ERROR("GLFW Error ({0}): {1}", error, message);
    }

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

            glfwSetErrorCallback(GLFWErrorCallback);
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

        // Set GLFW event callbacks.
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;

            WindowResizeEvent event(width, height);        
            data.EventCallback(event); 
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window) 
        {
            WindowData& data = *(WindowData *)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.EventCallback(event);
        });

        glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused)
        {
            WindowData& data = *(WindowData *)glfwGetWindowUserPointer(window);
            data.Focus = focused;

            WindowFocusEvent event(focused);
            data.EventCallback(event);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            WindowData& data = *(WindowData *)glfwGetWindowUserPointer(window);

            switch(action)
            {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, 0);
                    data.EventCallback(event);
                    break;
                }               
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, 1);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
        {
            WindowData& data = *(WindowData *)glfwGetWindowUserPointer(window);
            MouseMovedEvent event(xPos, yPos);
            data.EventCallback(event);
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) 
        {
            WindowData& data = *(WindowData *)glfwGetWindowUserPointer(window);

            switch(action)
            {
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
        {
            WindowData& data = *(WindowData *)glfwGetWindowUserPointer(window);
            MouseScrolledEvent event(xOffset, yOffset);
            data.EventCallback(event);
        });
    }

    void MacWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
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