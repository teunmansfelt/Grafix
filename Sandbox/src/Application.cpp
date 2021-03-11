
#include <Grafix.hpp>

class ExampleLayer : public Grafix::Layer
{
public:
    ExampleLayer()
        : Grafix::Layer("Example")
    {}

    void OnUpdate() override
    {
        GFX_INFO("ExampleLayer::Update");
    }

    void OnEvent(Grafix::Event& event) override
    {
        GFX_TRACE("{0}", event);
    }
};

class SandboxApp : public Grafix::Application
{
public:
    SandboxApp()
        : Grafix::Application("Grafix Sandbox Application")
    {
        PushLayer(new ExampleLayer());
        PushOverlay(new Grafix::ImGuiLayer());
    }

    ~SandboxApp()
    {}
};

Grafix::Application* Grafix::CreateApplication()
{
    return new SandboxApp();
}