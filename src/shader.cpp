#include "shader.h"

namespace Cloudscape {

  namespace Lightning {
  
    Shader::Shader(std::string vertexShaderSource, std::string fragmentShaderSource)
    {
      // Compile Vertex Shader
      const GLchar* vertexShaderSourceC = vertexShaderSource.c_str();

      GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
      glShaderSource(vShader, 1, &vertexShaderSourceC, 0);
      glCompileShader(vShader);

      // Compile Fragment Shader
      const GLchar* fragmentShaderSourceC = fragmentShaderSource.c_str();

      GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
      glShaderSource(fShader, 1, &fragmentShaderSourceC, 0);
      glCompileShader(fShader);

      // Create Shader Program
      m_shaderProgramID = glCreateProgram();
      glAttachShader(m_shaderProgramID, fShader);
      glAttachShader(m_shaderProgramID, vShader);
      glLinkProgram(m_shaderProgramID);

      // Delete shaders after program is created
      glDeleteShader(vShader);
      glDeleteShader(fShader);
    }

    Shader::~Shader()
    {
      glDeleteProgram(m_shaderProgramID); // maybe bad?
    }
  
  }

}