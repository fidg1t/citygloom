#include "shader.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <assert.h>

namespace Cloudscape {

  namespace Lightning {
    static std::string ReadShaderFile(const std::string filepath)
    {
      std::ifstream file(filepath, std::ios::in);

      if (!file)
      {
        std::cerr << "Failed to open shader file\n";
        return NULL;
      }

      std::ostringstream data;
      data << file.rdbuf(); // Read the entire file into our stream
      return data.str();
    }

    Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath)
    {
      std::string vertexShaderSource = ReadShaderFile(vertexShaderPath);
      const GLchar* vertexShaderSourceC = vertexShaderSource.c_str();

      GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
      glShaderSource(vShader, 1, &vertexShaderSourceC, 0);
      glCompileShader(vShader);

      // Compile Fragment Shader
      std::string fragmentShaderSource = ReadShaderFile(fragmentShaderPath);
      const GLchar* fragmentShaderSourceC = fragmentShaderSource.c_str();

      GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
      glShaderSource(fShader, 1, &fragmentShaderSourceC, 0);
      glCompileShader(fShader);

      // Create Shader Program
      m_shaderProgramID = glCreateProgram();
      glAttachShader(m_shaderProgramID, vShader);
      glAttachShader(m_shaderProgramID, fShader);
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