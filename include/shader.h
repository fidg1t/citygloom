#pragma once

#include <string>
#include <glad/glad.h>

namespace Cloudscape {

  namespace Lightning {
  
    class Shader
    {
    public:
      Shader(std::string vertexShaderSource = "shader/default.vert", std::string fragmentShaderSource = "shader/default.frag");
      ~Shader();

      inline GLuint GetShaderProgramID() const { return m_shaderProgramID; }

    private:
      GLuint m_shaderProgramID;
    };
  
  }

}