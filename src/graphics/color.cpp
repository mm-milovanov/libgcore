#include <hexvel-graphics/graphics/color.hpp>

Color::Color() :
    r(0.f), g(0.f), b(0.f), a(1.f)
{ }

Color::Color(float red, float green, float blue, float alpha) :
    r(red), g(green), b(blue), a(alpha)
{ }

Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
    r = static_cast<float>(red  ) / 255;
    g = static_cast<float>(green) / 255;
    b = static_cast<float>(blue ) / 255;
    a = static_cast<float>(alpha) / 255;
}

Color::Color(uint32_t color)
{
    uint8_t red   = (color >> 24) & 0xFF;
    uint8_t green = (color >> 16) & 0xFF;
    uint8_t blue  = (color >> 8 ) & 0xFF;
    uint8_t alpha = (color      ) & 0xFF;

    r = static_cast<float>(red  ) / 255;
    g = static_cast<float>(green) / 255;
    b = static_cast<float>(blue ) / 255;
    a = static_cast<float>(alpha) / 255;
}

Color Color::black(0x000000ff);
Color Color::white(0xffffffff);
Color Color::red  (0xff0000ff);
Color Color::green(0x00ff00ff);
Color Color::blue (0x0000ffff);