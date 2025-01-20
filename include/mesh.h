#pragma once

#include <glad/glad.h>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

namespace Cloudscape {

  namespace Thunder {
  
    class Mesh
    {
    public:
      Mesh();
      ~Mesh();

      void Render() const;

    private:
      glm::vec4 m_vertices[4];
      glm::vec3 m_indices[2];
      
      GLuint m_vbo, m_ebo, m_vao, m_shaderProgram;
      GLint m_color; // Test!
    };

  }

}