#include <hexvel-graphics/graphics/render_target.hpp>
#include <hexvel-graphics/graphics/drawable.hpp>

#include <hexvel-graphics/gl/gl_error.hpp>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cassert>

RenderTarget::RenderTarget() :
    m_camera(nullptr)
{}

void RenderTarget::setCamera(Camera* camera) {
    m_camera = camera;
}

void RenderTarget::draw(const IDrawable   &object,
                              RenderState  state  )
{
    assert(m_camera);
    object.draw(*this, *m_camera, state);
}

void RenderTarget::draw(const RenderState         &state,
                              GlDrawFunc        drawFun,
                              GlPrimitiveType  type,
                              std::size_t          firstVertex,
                              std::size_t          vertexCount )
{
    state.bind();

    this->drawPrimitives(
        drawFun,
        type,
        firstVertex,
        vertexCount
    );
}

void RenderTarget::clear(Color color) {
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderTarget::drawPrimitives(GlDrawFunc       draw,
                                  GlPrimitiveType type,
                                  std::size_t         firstVertex,
                                  std::size_t         vertexCount )
{  
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    switch (draw)
    {
    case GlDrawFunc::DRAW_ARRAYS:
        glDrawArrays(
            static_cast<GLenum>(type),
            (GLint)firstVertex,
            (GLsizei)vertexCount
        );
        break;
    case GlDrawFunc::DRAW_ELEMENTS:
        glDrawElements(
            static_cast<GLenum>(type),
            (GLsizei)vertexCount,
            GL_UNSIGNED_INT,
            0
        );
        break;
    }
}