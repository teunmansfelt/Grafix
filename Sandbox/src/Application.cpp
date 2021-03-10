
#include <Grafix.hpp>

class ExampleLayer : public Grafix::Layer
{
public:
    ExampleLayer()
        : Grafix::Layer("Example")
    {}

    void OnUpdate() override
    {
        GF_INFO("ExampleLayer::Update");
    }

    void OnEvent(Grafix::Event& event) override
    {
        GF_TRACE("{0}", event);
    }
};

class SandboxApp : public Grafix::Application
{
public:
    SandboxApp()
        : Grafix::Application("Grafix Sandbox Application")
    {
        PushLayer(new ExampleLayer());
    }

    ~SandboxApp()
    {}
};

Grafix::Application& Grafix::CreateApplication()
{
    return *(new SandboxApp());
}