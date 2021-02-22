
#include "Grafix/Layers/Layer.hpp"

namespace Grafix
{
    Layer::Layer(const std::string& name)
        : m_DebugName(name)
    {}

    Layer::~Layer()
    {}
}