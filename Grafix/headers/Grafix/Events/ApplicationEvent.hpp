#pragma once

#include "Event.hpp"

namespace Grafix
{
    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() 
        {}

        EVENT_TYPE (WINDOW_CLOSE)
        EVENT_CATEGORY (EVENT_CATEGORY_APPLICATION)
    };

    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height)
        {}

        inline unsigned int GetWidth() const { return m_Width; }
        inline unsigned int GetHeight() const { return m_Height; }

        EVENT_TYPE (WINDOW_RESIZE)
        EVENT_CATEGORY (EVENT_CATEGORY_APPLICATION)

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << GetName() << ": (w: " << m_Width << ", h: " << m_Height << ")";
            return ss.str();
        }
    
    private:
        unsigned int m_Width, m_Height;
    };

    class WindowFocusEvent : public Event
    {
    public:
        WindowFocusEvent()
        {}

        EVENT_TYPE (WINDOW_FOCUS)
        EVENT_CATEGORY (EVENT_CATEGORY_APPLICATION)
    };

    class WindowLostFocusEvent : public Event
    {
    public:
        WindowLostFocusEvent()
        {}

        EVENT_TYPE (WINDOW_LOST_FOCUS)
        EVENT_CATEGORY (EVENT_CATEGORY_APPLICATION)
    };
}