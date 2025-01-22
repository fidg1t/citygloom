#pragma once

#include <string>
#include <glad/glad.h>

namespace Cloudscape {

  namespace Thunder {
  
    class Shader
    {
    public:
      Shader(std::string vertexShaderSource, std::string fragmentShaderSource);
      ~Shader();

      inline GLuint GetShaderProgramID() const { return m_shaderProgramID; }

    private:
      GLuint m_shaderProgramID;
    };
  
  }

}