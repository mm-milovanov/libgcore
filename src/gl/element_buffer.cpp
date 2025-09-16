#include <gcore/gl/element_buffer.hpp>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <cassert>

ElementBuffer::ElementBuffer()
{ }

void ElementBuffer::create(GlUsage usage, std::size_t count)
{
    m_usage = usage;
    m_indicesCount = count;

    // Generate buffer
    glGenBuffers(1, &m_bufName);

    assert(m_bufName);

    // Create buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufName);
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        sizeof(GLuint) * count,
        nullptr,
        static_cast<GLenum>(usage)
    );
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ElementBuffer::update(const unsigned int* indices, std::size_t count)
{
    assert(m_bufName);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufName);

    glBufferSubData(
        GL_ELEMENT_ARRAY_BUFFER,
        0,
        sizeof(GLuint) * count,
        indices
    );
}

std::size_t ElementBuffer::getCount() const
{
    return m_indicesCount;
}

void ElementBuffer::bind() const {
    assert(m_bufName);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufName);
}

void ElementBuffer::unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}