#pragma once

#include <glad/glad.h>
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
      std::vector<glm::vec4> m_vertices;
      std::vector<GLuint> m_indices;
      
      GLuint m_vbo, m_ebo, m_vao, m_shaderProgram;
      GLint m_color; // Test!
    };

  }

}