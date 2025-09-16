#ifndef __glfw_window_impl_hpp__
#define __glfw_window_impl_hpp__

#include <gcore/gl/gl_resource.hpp>

#include "../window_impl.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class GlfwWindowImpl : public WindowImpl
{
public:

    /* Constructor */

    GlfwWindowImpl();

    /* Destructor */

    ~GlfwWindowImpl() override;

    /* Window impl methods */

    void create(Vec2u size, const char* name) override;

    bool isOpen() override;

    void setActive() override;

    Vec2i getSize() override;
    
    void setSize(Vec2i size) override;

    void display() override;

private:
    /* Members */

    GLFWwindow* _window;
};

#endif /* __glfw_window_impl_hpp__*/