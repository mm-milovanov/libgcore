#include <window/keyboard.hpp>

static bool pressedKeys[256] = {0};

// Translate key from glfw to keyboard_key_e enum
keyboard_key_e glfwKeyCodeToEnum(int key) {
    switch(key) {
    case GLFW_KEY_UNKNOWN:          return keyboard_key_e::UNKNOWN;
    case GLFW_KEY_SPACE:            return keyboard_key_e::SPACE;
    case GLFW_KEY_APOSTROPHE:       return keyboard_key_e::APOSTROPHE;
    case GLFW_KEY_COMMA:            return keyboard_key_e::COMMA;
    case GLFW_KEY_MINUS:            return keyboard_key_e::MINUS;
    case GLFW_KEY_PERIOD:           return keyboard_key_e::PERIOD;
    case GLFW_KEY_SLASH:            return keyboard_key_e::SLASH;
    case GLFW_KEY_0:                return keyboard_key_e::NUM_0;
    case GLFW_KEY_1:                return keyboard_key_e::NUM_1;
    case GLFW_KEY_2:                return keyboard_key_e::NUM_2;
    case GLFW_KEY_3:                return keyboard_key_e::NUM_3;
    case GLFW_KEY_4:                return keyboard_key_e::NUM_4;
    case GLFW_KEY_5:                return keyboard_key_e::NUM_5;
    case GLFW_KEY_6:                return keyboard_key_e::NUM_6;
    case GLFW_KEY_7:                return keyboard_key_e::NUM_7;
    case GLFW_KEY_8:                return keyboard_key_e::NUM_8;
    case GLFW_KEY_9:                return keyboard_key_e::NUM_9;
    case GLFW_KEY_SEMICOLON:        return keyboard_key_e::SEMICOLON;
    case GLFW_KEY_EQUAL:            return keyboard_key_e::EQUAL;
    case GLFW_KEY_A:                return keyboard_key_e::A;
    case GLFW_KEY_B:                return keyboard_key_e::B;
    case GLFW_KEY_C:                return keyboard_key_e::C;
    case GLFW_KEY_D:                return keyboard_key_e::D;
    case GLFW_KEY_E:                return keyboard_key_e::E;
    case GLFW_KEY_F:                return keyboard_key_e::F;
    case GLFW_KEY_G:                return keyboard_key_e::G;
    case GLFW_KEY_H:                return keyboard_key_e::H;
    case GLFW_KEY_I:                return keyboard_key_e::I;
    case GLFW_KEY_J:                return keyboard_key_e::J;
    case GLFW_KEY_K:                return keyboard_key_e::K;
    case GLFW_KEY_L:                return keyboard_key_e::L;
    case GLFW_KEY_M:                return keyboard_key_e::M;
    case GLFW_KEY_N:                return keyboard_key_e::N;
    case GLFW_KEY_O:                return keyboard_key_e::O;
    case GLFW_KEY_P:                return keyboard_key_e::P;
    case GLFW_KEY_Q:                return keyboard_key_e::Q;
    case GLFW_KEY_R:                return keyboard_key_e::R;
    case GLFW_KEY_S:                return keyboard_key_e::S;
    case GLFW_KEY_T:                return keyboard_key_e::T;
    case GLFW_KEY_U:                return keyboard_key_e::U;
    case GLFW_KEY_V:                return keyboard_key_e::V;
    case GLFW_KEY_W:                return keyboard_key_e::W;
    case GLFW_KEY_X:                return keyboard_key_e::X;
    case GLFW_KEY_Y:                return keyboard_key_e::Y;
    case GLFW_KEY_Z:                return keyboard_key_e::Z;
    case GLFW_KEY_LEFT_BRACKET:     return keyboard_key_e::LEFT_BRACKET;
    case GLFW_KEY_BACKSLASH:        return keyboard_key_e::BACKSLASH;
    case GLFW_KEY_RIGHT_BRACKET:    return keyboard_key_e::RIGHT_BRACKET;
    case GLFW_KEY_GRAVE_ACCENT:     return keyboard_key_e::GRAVE_ACCENT;
    case GLFW_KEY_WORLD_1:          return keyboard_key_e::WORLD_1;
    case GLFW_KEY_WORLD_2:          return keyboard_key_e::WORLD_2;
    case GLFW_KEY_ESCAPE:           return keyboard_key_e::ESCAPE;
    case GLFW_KEY_ENTER:            return keyboard_key_e::ENTER;
    case GLFW_KEY_TAB:              return keyboard_key_e::TAB;
    case GLFW_KEY_BACKSPACE:        return keyboard_key_e::BACKSPACE;
    case GLFW_KEY_INSERT:           return keyboard_key_e::INSERT;
    case GLFW_KEY_DELETE:           return keyboard_key_e::DELETE;
    case GLFW_KEY_RIGHT:            return keyboard_key_e::RIGHT;
    case GLFW_KEY_LEFT:             return keyboard_key_e::LEFT;
    case GLFW_KEY_DOWN:             return keyboard_key_e::DOWN;
    case GLFW_KEY_UP:               return keyboard_key_e::UP;
    case GLFW_KEY_PAGE_UP:          return keyboard_key_e::PAGE_UP;
    case GLFW_KEY_PAGE_DOWN:        return keyboard_key_e::PAGE_DOWN;
    case GLFW_KEY_HOME:             return keyboard_key_e::HOME;
    case GLFW_KEY_END:              return keyboard_key_e::END;
    case GLFW_KEY_CAPS_LOCK:        return keyboard_key_e::CAPS_LOCK;
    case GLFW_KEY_SCROLL_LOCK:      return keyboard_key_e::SCROLL_LOCK;
    case GLFW_KEY_NUM_LOCK:         return keyboard_key_e::NUM_LOCK;
    case GLFW_KEY_PRINT_SCREEN:     return keyboard_key_e::PRINT_SCREEN;
    case GLFW_KEY_PAUSE:            return keyboard_key_e::PAUSE;
    case GLFW_KEY_F1:               return keyboard_key_e::F1;
    case GLFW_KEY_F2:               return keyboard_key_e::F2;
    case GLFW_KEY_F3:               return keyboard_key_e::F3;
    case GLFW_KEY_F4:               return keyboard_key_e::F4;
    case GLFW_KEY_F5:               return keyboard_key_e::F5;
    case GLFW_KEY_F6:               return keyboard_key_e::F6;
    case GLFW_KEY_F7:               return keyboard_key_e::F7;
    case GLFW_KEY_F8:               return keyboard_key_e::F8;
    case GLFW_KEY_F9:               return keyboard_key_e::F9;
    case GLFW_KEY_F10:              return keyboard_key_e::F10;
    case GLFW_KEY_F11:              return keyboard_key_e::F11;
    case GLFW_KEY_F12:              return keyboard_key_e::F12;
    case GLFW_KEY_F13:              return keyboard_key_e::F13;
    case GLFW_KEY_F14:              return keyboard_key_e::F14;
    case GLFW_KEY_F15:              return keyboard_key_e::F15;
    case GLFW_KEY_F16:              return keyboard_key_e::F16;
    case GLFW_KEY_F17:              return keyboard_key_e::F17;
    case GLFW_KEY_F18:              return keyboard_key_e::F18;
    case GLFW_KEY_F19:              return keyboard_key_e::F19;
    case GLFW_KEY_F20:              return keyboard_key_e::F20;
    case GLFW_KEY_F21:              return keyboard_key_e::F21;
    case GLFW_KEY_F22:              return keyboard_key_e::F22;
    case GLFW_KEY_F23:              return keyboard_key_e::F23;
    case GLFW_KEY_F24:              return keyboard_key_e::F24;
    case GLFW_KEY_F25:              return keyboard_key_e::F25;
    case GLFW_KEY_KP_0:             return keyboard_key_e::KP_0;
    case GLFW_KEY_KP_1:             return keyboard_key_e::KP_1;
    case GLFW_KEY_KP_2:             return keyboard_key_e::KP_2;
    case GLFW_KEY_KP_3:             return keyboard_key_e::KP_3;
    case GLFW_KEY_KP_4:             return keyboard_key_e::KP_4;
    case GLFW_KEY_KP_5:             return keyboard_key_e::KP_5;
    case GLFW_KEY_KP_6:             return keyboard_key_e::KP_6;
    case GLFW_KEY_KP_7:             return keyboard_key_e::KP_7;
    case GLFW_KEY_KP_8:             return keyboard_key_e::KP_8;
    case GLFW_KEY_KP_9:             return keyboard_key_e::KP_9;
    case GLFW_KEY_KP_DECIMAL:       return keyboard_key_e::KP_DECIMAL;
    case GLFW_KEY_KP_DIVIDE:        return keyboard_key_e::KP_DIVIDE;
    case GLFW_KEY_KP_MULTIPLY:      return keyboard_key_e::KP_MULTIPLY;
    case GLFW_KEY_KP_SUBTRACT:      return keyboard_key_e::KP_SUBTRACT;
    case GLFW_KEY_KP_ADD:           return keyboard_key_e::KP_ADD;
    case GLFW_KEY_KP_ENTER:         return keyboard_key_e::KP_ENTER;
    case GLFW_KEY_KP_EQUAL:         return keyboard_key_e::KP_EQUAL;
    case GLFW_KEY_LEFT_SHIFT:       return keyboard_key_e::LEFT_SHIFT;
    case GLFW_KEY_LEFT_CONTROL:     return keyboard_key_e::LEFT_CONTROL;
    case GLFW_KEY_LEFT_ALT:         return keyboard_key_e::LEFT_ALT;
    case GLFW_KEY_LEFT_SUPER:       return keyboard_key_e::LEFT_SUPER;
    case GLFW_KEY_RIGHT_SHIFT:      return keyboard_key_e::RIGHT_SHIFT;
    case GLFW_KEY_RIGHT_CONTROL:    return keyboard_key_e::RIGHT_CONTROL;
    case GLFW_KEY_RIGHT_ALT:        return keyboard_key_e::RIGHT_ALT;
    case GLFW_KEY_RIGHT_SUPER:      return keyboard_key_e::RIGHT_SUPER;
    case GLFW_KEY_MENU:             return keyboard_key_e::MENU;
    default:                        return keyboard_key_e::UNKNOWN;              
    }
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    int k = static_cast<int>(glfwKeyCodeToEnum(key));
    /* Remember pressed key */
    pressedKeys[k] = (action == GLFW_PRESS);
}

bool isKeyPressed(keyboard_key_e key) {
    int k = static_cast<int>(key);
    return pressedKeys[k];
}