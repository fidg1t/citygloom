#include "window.h"

namespace Cloudscape {

  namespace Thunder {

    Window::Window(std::string name, int width, int height) : m_name(name), m_width(width), m_height(height)
    {
      SDL_WindowFlags wFlags = 0; // Nothing for now
      m_window = SDL_CreateWindow(m_name.c_str(), m_width, m_height, wFlags);
    }

    Window::~Window()
    {
      SDL_DestroyWindow(m_window);
    }
  }

}