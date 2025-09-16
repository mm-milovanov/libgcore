#include <gcore/gl/render_state.hpp>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cassert>

void RenderState::setShader(ShaderProgram& program) {
    m_program = program;
}

void RenderState::addVertexBuffer(VertexBuffer& buffer) {
    m_vertexbuffers.push_back(buffer);
}

void RenderState::setElementBuffer(ElementBuffer& buffer) {
    m_elementBuffer = buffer;
}

void RenderState::connect() {
    // Generate VAO
    glGenVertexArrays(1, &m_vaoName);

    assert(m_vaoName);

    // Bind VAO
    glBindVertexArray(m_vaoName);

    // m_program.enable();

    // // Bind VBO and it's attributes to VAO
    // for (auto& buffer : m_vertexbuffers)
    //     buffer.bind();

    // // Bind EBO
    // m_elementBuffer.bind();
}

void RenderState::bind() const {
    // assert(m_vaoName);

    m_program.enable();

    // glBindVertexArray(m_vaoName);

    // Bind VBO and it's attributes to VAO
    for (auto& buffer : m_vertexbuffers)
        buffer.bind();

    // Bind EBO
    m_elementBuffer.bind();
}