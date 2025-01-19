#include "window.h"

namespace Cloudscape {

  namespace Thunder {

    Window::Window(std::string name, int width, int height) : m_name(name), m_width(width), m_height(height)
    {
      m_window = SDL_CreateWindow(m_name.c_str(), m_width, m_height, SDL_WINDOW_OPENGL);
    }

    Window::~Window()
    {
      SDL_DestroyWindow(m_window);
    }
  }

}