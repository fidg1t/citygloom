#include "mesh.h"
#include <iostream>

namespace Cloudscape {

  namespace Thunder {
  
    Mesh::Mesh() : m_vao(0)
    {
      // compile shaders
      const char* fragment_shader_text =
        "#version 460\n\
       uniform vec4 color;\
       out vec4 outColor;\
       void main(void) {\
         outColor = vec4(0.8f, 0.0f, 0.6f, 1.0f);\
       }";
      GLuint fshader = glCreateShader(GL_FRAGMENT_SHADER);
      glShaderSource(fshader, 1, &fragment_shader_text, 0);
      glCompileShader(fshader);

      const char* vertex_shader_text =
        "#version 460\n\
       layout (location = 0) in vec4 position;\
       void main() {\
         gl_Position = position;\
       }";

      GLuint vshader = glCreateShader(GL_VERTEX_SHADER);
      glShaderSource(vshader, 1, &vertex_shader_text, 0);
      glCompileShader(vshader);

      m_shaderProgram = glCreateProgram();
      glAttachShader(m_shaderProgram, fshader);
      glAttachShader(m_shaderProgram, vshader);
      glLinkProgram(m_shaderProgram);
      glUseProgram(m_shaderProgram);

      glDeleteShader(vshader);
      glDeleteShader(fshader);

      // get shader parameter locations
      m_color = glGetUniformLocation(m_shaderProgram, "color");

      m_vertices = {
        glm::vec4(0.5f, 0.5f, 0.0f, 1.0f),
        glm::vec4(0.5f, -0.5f, 0.0f, 1.0f),
        glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f),
        glm::vec4(-0.5f, 0.5f, 0.0f, 1.0f)
      };

      m_indices = {
          0, 1, 3,
          1, 2, 3
      };

      glGenVertexArrays(1, &m_vao);
      glGenBuffers(1, &m_vbo);
      glGenBuffers(1, &m_ebo);
     
      glBindVertexArray(m_vao);

      glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
      glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec4) * m_vertices.size(), m_vertices.data(), GL_STATIC_DRAW);

      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * m_indices.size(), m_indices.data(), GL_STATIC_DRAW);

      glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(glm::vec4), 0);
      glEnableVertexAttribArray(0);

      glBindBuffer(GL_ARRAY_BUFFER, 0);
      glBindVertexArray(0);

    }

    Mesh::~Mesh()
    {
      glDeleteVertexArrays(1, &m_vao);

      glDeleteBuffers(1, &m_vbo);
      glDeleteBuffers(1, &m_ebo);
    }

    void Mesh::Render() const
    {
      glUseProgram(m_shaderProgram);
      glBindVertexArray(m_vao);
      glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

  }

}