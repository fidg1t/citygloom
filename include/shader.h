#pragma once

#include <string>
#include <glad/glad.h>

namespace Cloudscape {

  namespace Lightning {
  
    class Shader
    {
    public:
      Shader(std::string vertexShaderPath = "shaders/default.vert", std::string fragmentShaderPath = "shaders/default.frag");
      ~Shader();

      inline GLuint GetShaderProgramID() const { return m_shaderProgramID; }

    private:
      GLuint m_shaderProgramID;
    };
  
  }

}