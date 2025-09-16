#ifndef __drawable_hpp__
#define __drawable_hpp__

class  RenderTarget;
class  Camera;
struct RenderState;

class IDrawable {
public:
    virtual ~IDrawable() {};

protected:
    /* Protected method */

    virtual void draw(RenderTarget &target,
                      Camera       &camera,
                      RenderState  &states ) const = 0;

    /* Forward friend class declaration */

    friend class RenderTarget;
};

#endif // __drawable_hpp__