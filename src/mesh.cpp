#include "mesh.h"
#include <iostream>

namespace Cloudscape {

  namespace Lightning {
  
    Mesh::Mesh()
    {
      
      // get shader parameter locations
      m_color = glGetUniformLocation(m_shader, "color");

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
      glUseProgram(m_shader.GetShaderProgramID());
      glBindVertexArray(m_vao);
      glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

  }

}