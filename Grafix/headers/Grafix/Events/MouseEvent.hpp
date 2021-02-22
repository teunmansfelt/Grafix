#pragma once

#include "Event.hpp"

namespace Grafix
{
    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(double x, double y)
            : m_MouseX(x), m_MouseY(y)
        {}

        inline double GetX() const { return m_MouseX; }
        inline double GetY() const { return m_MouseY; }

        EVENT_TYPE (MOUSE_MOVED)
        EVENT_CATEGORY (EVENT_CATEGORY_MOUSE | EVENT_CATEGORY_INPUT)

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << GetName() << ": (x: " << m_MouseX << ", y: " << m_MouseY << ")";
            return ss.str();
        }
    
    private:
        double m_MouseX, m_MouseY;
    };

    class MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(double xOffset, double yOffset)
            : m_XOffset(xOffset), m_YOffset(yOffset)
        {}

        inline double GetXOffset() const { return m_XOffset; }
        inline double GetYOffset() const { return m_YOffset; }

        EVENT_TYPE (MOUSE_SCROLLED)
        EVENT_CATEGORY (EVENT_CATEGORY_MOUSE | EVENT_CATEGORY_INPUT)

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << GetName() << ": (xOff: " << m_XOffset << ", yOff: " << m_YOffset << ")";
            return ss.str();
        }

    private:
        double m_XOffset, m_YOffset;
    };

    class MouseButtonEvent : public Event
    {
    protected:
        MouseButtonEvent(int button)
            : m_Button(button)
        {}

    public:
        inline int GetMouseButton() const { return m_Button; }

        EVENT_CATEGORY (EVENT_CATEGORY_MOUSEBUTTON | EVENT_CATEGORY_INPUT)

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << GetName() << ": (" << m_Button << ")";
            return ss.str();
        }

    private:
        int m_Button;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int button)
            : MouseButtonEvent(button)
        {}

        EVENT_TYPE (MOUSE_BUTTON_PRESSED)
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int button)
            : MouseButtonEvent(button)
        {}

        EVENT_TYPE (MOUSE_BUTTON_RELEASED)
    };
}