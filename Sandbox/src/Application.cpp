
#include <Grafix.hpp>

class ExampleLayer : public Grafix::Layer
{
public:
    ExampleLayer()
        : Grafix::Layer("Example")
    {}

    void OnUpdate() override
    {
        // GFX_INFO("ExampleLayer::Update");
        if (Grafix::Input::IsKeyPressed(GFX_KEY_G))
            GFX_TRACE("'G' key is pressed (poll)!");
    }

    void OnEvent(Grafix::Event& event) override
    {
        // GFX_TRACE("{0}", event);
        Grafix::EventDispatcher dispatcher(event);

        dispatcher.Dispatch<Grafix::KeyPressedEvent>([](Grafix::KeyPressedEvent& event) 
        {
            if (event.GetKeyCode() == GFX_KEY_G)
                GFX_TRACE("'G' key is pressed (event)!");
            GFX_TRACE("{0}", (char)event.GetKeyCode());
            return false;
        });
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