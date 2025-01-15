#pragma once

#include <SDL3/SDL_video.h>
#include <memory>
#include <string>

namespace Cloudscape {

  namespace Thunder {

    class Window
    {
    public:
      Window(std::string name, int m_width, int m_height);
      ~Window();

      inline SDL_Window* GetSDLWindow() const { return m_window; }

    private:
      SDL_Window* m_window;
      
      std::string m_name;
      int m_width, m_height;
    };

  }

}