#include <gcore/gl/vertex_buffer.hpp>
#include <gcore/gl/gl_error.hpp>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <cassert>

VertexBuffer::~VertexBuffer()
{
    if (m_bufName)
        glDeleteBuffers(1, &m_bufName);
}

void VertexBuffer::create(GlUsage usage, std::size_t size)
{
    m_bufSize = size;

    // Allocate resource
    glGenBuffers(1, &m_bufName);

    assert(m_bufName);

    // Bind VBO
    glBindBuffer(GL_ARRAY_BUFFER, m_bufName);

    // Allocate buffer data
    glBufferData(
        GL_ARRAY_BUFFER,
        static_cast<GLintptrARB>(size),
        nullptr,
        static_cast<GLenum>(usage)
    );
}

void VertexBuffer::setAttribute(ShaderProgram&  program,
                                const char*     name,
                                GlAttributeType type,
                                std::size_t     size,
                                std::size_t     stride,
                                std::size_t     offset,
                                bool            normalized)
{
    // Locate attribute
    int location = program.locateAttribute(name);

    assert(location >= 0);

    m_attributes.push_back({
        name,
        location,
        type,
        size,
        stride,
        offset,
        normalized
    });
}

void VertexBuffer::update(const void* data, std::size_t size)
{
    assert(m_bufName);

    // Check overflow
    assert(size < m_bufSize);

    // Bind VBO
    glBindBuffer(GL_ARRAY_BUFFER, m_bufName);

    glBufferSubData(
        GL_ARRAY_BUFFER,
        0,
        static_cast<GLsizeiptr>(size),
        static_cast<const void*>(data)
    );
}

std::size_t VertexBuffer::getSize() const {
    return m_bufSize;
}

void VertexBuffer::bind() const {
    assert(m_bufName);

    // Bind VBO
    glBindBuffer(GL_ARRAY_BUFFER, m_bufName);

    for (auto& attribute : m_attributes) {
        SAFE_GL(glEnableVertexAttribArray(attribute.location));
        SAFE_GL(glVertexAttribPointer(
            (GLuint   )(attribute.location  ),
            (GLint    )(attribute.size      ),
            (GLenum   )(attribute.type      ),
            (GLboolean)(attribute.normalized),
            (GLsizei  )(attribute.stride    ),
            (GLvoid*  )(attribute.offset    )
        ));
    }
}

void VertexBuffer::unbind() const {
    for (auto& attribute : m_attributes)
        glDisableVertexAttribArray((GLuint)(attribute.location));
}