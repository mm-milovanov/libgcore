#ifndef __render_state_hpp__
#define __render_state_hpp__

#include <hexvel-graphics/gl/shader_program.hpp>
#include <hexvel-graphics/gl/vertex_buffer.hpp>
#include <hexvel-graphics/gl/element_buffer.hpp>

#include <vector>

class RenderState {
public:
    /* Public methods */

    void setShader(ShaderProgram& program);

    void addVertexBuffer(VertexBuffer& buffer);

    void setElementBuffer(ElementBuffer& buffer);

    void connect();

    void bind() const;

private:
    /* Private fields */

    unsigned int              m_vaoId;
    ShaderProgram             m_program;
    std::vector<VertexBuffer> m_vertexbuffers;
    ElementBuffer             m_elementBuffer;
};

#endif // __render_state_hpp__