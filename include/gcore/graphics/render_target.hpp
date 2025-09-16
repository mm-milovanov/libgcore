#ifndef __render_target_hpp__
#define __render_target_hpp__

// #include <system/noncopyable.hpp>
#include <gcore/graphics/color.hpp>
#include <gcore/graphics/camera.hpp>
#include <gcore/linalg/transform.hpp>
#include <gcore/linalg/vec2.hpp>
#include <gcore/gl/render_state.hpp>
#include <gcore/gl/shader_program.hpp>

class IDrawable;
class VertexArray;

// Render target abstract class
class RenderTarget // : NonCopyable
{
public:
    virtual ~RenderTarget() = default;

    /* Public methods */

    void setCamera(Camera*);

    void draw(const IDrawable   &object,
                    RenderState  states);

    void draw(const RenderState     &state,
                    GlDrawFunc       drawFun,
                    GlPrimitiveType  type,
                    std::size_t      firstVertex,
                    std::size_t      vertexCount );

    void clear(Color color = Color::black);

    virtual Vec2i getSize() const = 0;

protected:

    RenderTarget();

private:
    /* Private methods */

    void drawPrimitives(GlDrawFunc      draw,
                        GlPrimitiveType type,
                        std::size_t     firstVertex,
                        std::size_t     vertexCount );

    /* Private fields */

    Camera* m_camera;
};

#endif // __render_target_hpp__