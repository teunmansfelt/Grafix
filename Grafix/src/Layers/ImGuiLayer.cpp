
#include "Grafix/Layers/ImGuiLayer.hpp"
#include "GF_PCH.hpp"
#include "Grafix/Core.hpp"
#include "Grafix/Application.hpp"

#include <imgui/imgui.h>
#include "Platform/OpenGL/imgui_impl_opengl3.h"
#include <glfw/glfw3.h> // TEMPORARY!! -> for key codes

namespace Grafix
{
    bool ImGuiLayer::s_MouseJustPressed[ImGuiMouseButton_COUNT] = {};

    ImGuiLayer::ImGuiLayer()
        : Layer("ImGui Layer")
    {}

    ImGuiLayer::~ImGuiLayer()
    {}

    void ImGuiLayer::OnAttach()
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

        // TEMPORARY: Should use GRAFIX keycodes!!
        io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
        io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
        io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
        io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
        io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
        io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
        io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
        io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
        io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
        io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
        io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
        io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
        io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
        io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
        io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
        io.KeyMap[ImGuiKey_KeyPadEnter] = GLFW_KEY_KP_ENTER;
        io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
        io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
        io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
        io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
        io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
        io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

        ImGui_ImplOpenGL3_Init("#version 330");
    }

    void ImGuiLayer::OnDetach()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayer::OnUpdate()
    {
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::GetInstance();

        unsigned int width = app.GetWindow().GetWidth();
        unsigned int height = app.GetWindow().GetHeight();
        unsigned int display_width = app.GetWindow().GetFrameBufferWidth();
        unsigned int display_height = app.GetWindow().GetFrameBufferHeight();      
        io.DisplaySize = ImVec2((float)width, (float)height);
        if (width > 0 && height > 0)
            io.DisplayFramebufferScale = ImVec2((float)display_width / width, (float)display_height / height);

        float time = (float)glfwGetTime();
        io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
        m_Time = time;
        
        for (unsigned int i = 0; i < ImGuiMouseButton_COUNT; i++)
            s_MouseJustPressed[i] = false;

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        static bool showDemo = true;
        ImGui::ShowDemoWindow(&showDemo);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayer::OnEvent(Event& event)
    {   
        EventDispatcher dispatcher(event);

        dispatcher.Dispatch<MouseMovedEvent>(GF_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
        dispatcher.Dispatch<MouseButtonPressedEvent>(GF_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
        dispatcher.Dispatch<MouseButtonReleasedEvent>(GF_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
        dispatcher.Dispatch<MouseScrolledEvent>(GF_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
        dispatcher.Dispatch<KeyPressedEvent>(GF_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
        dispatcher.Dispatch<KeyReleasedEvent>(GF_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
        dispatcher.Dispatch<KeyTypedEvent>(GF_BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));
    }

    bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent &event)
    {
        ImGuiIO &io = ImGui::GetIO();

        bool focused = Application::GetInstance().GetWindow().IsFocused();
        if (focused)
            io.MousePos = ImVec2((float)event.GetX(), (float)event.GetY());
        else
            io.MousePos = ImVec2(-FLT_MAX, -FLT_MAX);

        return false;
    }

    bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent &event)
    {
        ImGuiIO &io = ImGui::GetIO();

        int button = event.GetMouseButton();
        if (button >= 0 && button < ImGuiMouseButton_COUNT)
            io.MouseDown[button] = s_MouseJustPressed[button] = true;

        return false;
    }

    bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent &event)
    {
        ImGuiIO &io = ImGui::GetIO();

        int button = event.GetMouseButton();
        if (button >= 0 && button < ImGuiMouseButton_COUNT)
            io.MouseDown[button] = s_MouseJustPressed[button];

        return false;
    }

    bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent &event)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.MouseWheelH += (float)event.GetXOffset();
        io.MouseWheel += (float)event.GetYOffset();
        return false;
    }

    bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent &event)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.KeysDown[event.GetKeyCode()] = true;

        io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
        io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
        io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
    #ifdef _WIN32
        io.KeySuper = false
    #else
        io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
    #endif

        return true;
    }

    bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent &event)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.KeysDown[event.GetKeyCode()] = false;

        io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
        io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
        io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];

    #ifdef _WIN32
        io.KeySuper = false
    #else
        io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
    #endif
        
        return true;
    }

    bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent &event)
    {
        ImGuiIO& io = ImGui::GetIO();
        unsigned int c = event.GetKeyCode();
        if (c > 0 && c < 0x10000)
            io.AddInputCharacter((unsigned short)c);
        return false;
    }
}
