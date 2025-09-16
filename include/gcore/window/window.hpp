#ifndef __window_hpp__
#define __window_hpp__

#include <gcore/linalg/vec2.hpp>
#include <gcore/graphics/render_target.hpp>

class WindowImpl;

class Window : public RenderTarget
{
public:
    Window();

    ~Window() override;

    /* Public methods */

    void create(Vec2u size, const char* name);

    bool isOpen();
    
    void close();

    void display();

    void setActive();

    Vec2i getSize() const override;

private:
    /* Private methods */

    WindowImpl* _windowImpl;
};

#endif // __window_hpp__