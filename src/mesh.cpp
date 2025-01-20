#include "mesh.h"

namespace Cloudscape {

  namespace Thunder {
  
    Mesh::Mesh()
    {
        // compile shaders
      const char* fragment_shader_text =
          "#version 130\n\
       uniform vec4 color;\
       out vec4 outColor;\
       void main(void) {\
         outColor = color;\
       }";
      GLuint fshader = glCreateShader(GL_FRAGMENT_SHADER);
      glShaderSource(fshader, 1, &fragment_shader_text, 0);
      glCompileShader(fshader);

      const char* vertex_shader_text =
          "#version 130\n\
       attribute vec4 position;\
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

      // Standard Square
      m_vertices[4] = {
        glm::vec4(-1, -1, 0, 0), // 0
        glm::vec4(1, -1, 0, 0),  // 1
        glm::vec4(1, 1, 0, 0),   // 2
        glm::vec4(-1, 1, 0, 0)   // 3
      };

      //// Indices for verts
      //m_indices[0] = glm::vec3(0, 1, 3);
      //m_indices[1] = glm::vec3(1, 2, 3);

      // Bind VAO
      glBindVertexArray(m_vao);

      // Init verts
      glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
      glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices, GL_STATIC_DRAW);

      //// Init edges
      //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
      //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_indices), m_indices, GL_STATIC_DRAW);

      // Init VAO
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
      glEnableVertexAttribArray(0);
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
      glBindVertexArray(0);
    }

  }

}