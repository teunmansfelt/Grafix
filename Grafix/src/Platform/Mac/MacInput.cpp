
#include "Platform/Mac/MacInput.hpp"
#include "Grafix/Application.hpp"

#include <glfw/glfw3.h>

namespace Grafix
{
    Input* Input::s_Instance = new MacInput();
    
    bool MacInput::IsKeyPressedImpl(int keycode)
    {
        GLFWwindow* window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
        int state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool MacInput::IsMouseButtonPressedImpl(int button)
    {
        GLFWwindow *window = static_cast<GLFWwindow *>(Application::GetInstance().GetWindow().GetNativeWindow());
        int state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }

    std::pair<double, double> MacInput::GetMousePosImpl()
    {
        GLFWwindow *window = static_cast<GLFWwindow *>(Application::GetInstance().GetWindow().GetNativeWindow());
        double posX, posY;
        glfwGetCursorPos(window, &posX, &posY);
        return {posX, posY};
    }

    double MacInput::GetMouseXImpl()
    {
        auto pos = GetMousePosImpl();
        return pos.first;
    }

    double MacInput::GetMouseYImpl()
    {
        auto pos = GetMousePosImpl();
        return pos.second;
    }
}