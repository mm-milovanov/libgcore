#ifndef __window_impl_hpp__
#define __window_impl_hpp__

// #include <system/noncopyable.hpp>
#include <hexvel-graphics/linalg/vec2.hpp>

class WindowImpl // : NonCopyable
{
public:

    virtual ~WindowImpl() = default;

    /* Virtual methods */

    virtual void create(Vec2u size, const char* name) = 0;

    virtual bool isOpen() = 0;

    virtual void setActive() = 0;

    virtual Vec2i getSize() = 0;
    
    virtual void setSize(Vec2i size) = 0;

    virtual void display() = 0;

protected:


};

#endif /* __windwo_impl_hpp__*/