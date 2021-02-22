#pragma once

#include "GF_PCH.hpp"

namespace Grafix 
{
    enum class EventType
    {
        NONE = 0,
        WINDOW_CLOSE, WINDOW_RESIZE, WINDOW_FOCUS,
        KEY_PRESSED, KEY_RELEASED,
        MOUSE_BUTTON_PRESSED, MOUSE_BUTTON_RELEASED, MOUSE_MOVED, MOUSE_SCROLLED
    };

    enum EventCategory
    {
        None = 0,
        EVENT_CATEGORY_APPLICATION  = 0x01,
        EVENT_CATEGORY_INPUT        = 0x02,
        EVENT_CATEGORY_KEYBOARD     = 0x04,
        EVENT_CATEGORY_MOUSE        = 0x08,
        EVENT_CATEGORY_MOUSEBUTTON  = 0x10
    };

    #define EVENT_TYPE(type)   static EventType GetStaticType() { return EventType::type; }           \
                               virtual EventType GetType() const override { return GetStaticType(); } \
                               virtual const char *GetName() const override { return #type; }

    #define EVENT_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

    class Event
    {
        template <typename T>
        using EventFunction = std::function<bool(T&)>;

    public:
        virtual EventType GetType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); } 

        inline bool IsInCategory(EventCategory category) const {
            return GetCategoryFlags() & category;
        }

        template <typename T>
        bool Dispatch(EventFunction<T> function)
        {
            if (GetType() == T::GetStaticType())
            {
                m_Handled = function(*this);
                return true;
            }
            return false;
        }

    private:
        bool m_Handled = false;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& event)
    {
        return os << event.ToString();
    }
}