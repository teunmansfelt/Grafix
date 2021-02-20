#pragma once

#include "Event.hpp"

namespace Grafix
{
    class KeyEvent : public Event
    {
    public:
        inline int GetKeyCode() const { return m_KeyCode; }

        EVENT_CATEGORY (EVENT_CATEGORY_KEYBOARD | EVENT_CATEGORY_INPUT)

    protected:
        KeyEvent(int keyCode)
            : m_KeyCode(keyCode)
        {}
        
        int m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keyCode, int repeatCount)
            : KeyEvent(keyCode), m_RepeatCount(repeatCount)
        {}

        inline int GetRepeatCount() const { return m_RepeatCount; }

        EVENT_TYPE (KEY_PRESSED)

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << GetName() << ": (key: " << m_KeyCode << ", rep: " << m_RepeatCount << ")";
            return ss.str();
        }

    private:
        int m_RepeatCount;
    };

    class KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int keyCode)
            : KeyEvent(keyCode)
        {}

        EVENT_TYPE (KEY_RELEASED)

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << GetName() << ": (key: " << m_KeyCode << ")";
            return ss.str();
        }
    };
}