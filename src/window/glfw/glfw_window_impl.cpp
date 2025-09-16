#include "glfw_window_impl.hpp"
#include "glfw_keyboard.hpp"

#include <gcore/gl/gl_resource.hpp>

#include <iostream>

GlfwWindowImpl::GlfwWindowImpl() :
    _window(nullptr)
{ }

GlfwWindowImpl::~GlfwWindowImpl() {
    if (!_window)
        return;

    glfwDestroyWindow(_window);
    glfwTerminate();
}

void GlfwWindowImpl::create(Vec2u size, const char* name)
{
    /* GLFW initialization */
	if (glfwInit() == GL_FALSE)
        throw;

    /* 
     * GLFW setup.
	 * Define minimum OpenGL version 3.3. 
     */
    /* Major */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	/* Minor */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Установка профайла для которого создается контекст
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Выключение возможности изменения размера окна
	// glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    /* Create window */
    _window = glfwCreateWindow(size.x, size.y, name, nullptr, nullptr);
    if (_window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        throw;
    }
    
    this->setActive();

    // glfwSetKeyCallback(_window, key_callback);  

    /* Connect GLAD */
    gladLoadGL(glfwGetProcAddress);
    // int version = 
    // __log_info("GLAD GL %d.%d\n", GLAD_VERSION_MAJOR(version), GLAD_VERSION_MINOR(version));

    glEnable(GL_DEPTH_TEST);

    /* Set viewport */
    int bufWidth, bufHeight;
    glfwGetFramebufferSize(_window, &bufWidth, &bufHeight);
    
    glViewport(0, 0, bufWidth, bufHeight);
}

bool GlfwWindowImpl::isOpen(void)
{
    /* Check events and call callbacks */
    glfwPollEvents();
    /* Check that window should close */
    return (glfwWindowShouldClose(_window) == 0);
}

void GlfwWindowImpl::setActive()
{
    glfwMakeContextCurrent(_window);
}

Vec2i GlfwWindowImpl::getSize()
{
    Vec2i size;
    glfwGetWindowSize(_window, &size.x, &size.y);
    return size;
}

void GlfwWindowImpl::setSize(Vec2i size)
{
    glfwSetWindowSize(_window, size.x, size.y);
}

void GlfwWindowImpl::display() {
    /* Swap buffers */
    glfwSwapBuffers(_window);
}
