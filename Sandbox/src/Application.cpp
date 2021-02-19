
#include <Grafix.hpp>

class SandboxApp : public Grafix::Application
{
public:
    SandboxApp()
        : Grafix::Application("Grafix Sandbox Application")
    {}

    ~SandboxApp()
    {}
};

Grafix::Application* Grafix::CreateApplication()
{
    return new SandboxApp();
}