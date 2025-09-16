#include <hexvel-graphics/window/window.hpp>
#include <hexvel-graphics/gl/shader_program.hpp>

#include <iostream>
#include <cassert>

#include "window_impl.hpp"

#define UNIX

#if defined(UNIX) || defined(WIN32)

#include "glfw/glfw_window_impl.hpp"
using WindowImplType = GlfwWindowImpl;

#elif defined(ANDROID)

// TODO: Realize android window creation
#include "android/android_window_impl.hpp"
using WindowImplType = AndroidWindowImpl;

#endif

Window::Window(void) :
    _windowImpl{new WindowImplType()}
{ }

Window::~Window()
{
    delete _windowImpl;
}

void Window::create(Vec2u size, const char* name)
{
    // Create window
    _windowImpl->create(size, name);

    // Init RenderTarget super class
    // this->init();
}

void Window::close(void)
{
    /* TODO */
}

bool Window::isOpen(void)
{
    assert(_windowImpl);
    return _windowImpl->isOpen();
}

Vec2i Window::getSize() const
{
    assert(_windowImpl);
    return _windowImpl->getSize();
}

void Window::setActive(void)
{
    assert(_windowImpl);
    _windowImpl->setActive();
}

void Window::display(void)
{
    assert(_windowImpl);
    _windowImpl->display();
}