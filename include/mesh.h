#pragma once

#include <glad/glad.h>
#include <glm/vec4.hpp>

namespace Cloudscape {
  namespace Lightning {
    class Shader;
  }
}

namespace Cloudscape {

  namespace Lightning {

    class Mesh
    {
    public:
      Mesh();
      ~Mesh();

      void Render() const;

    private:
      std::vector<glm::vec4> m_vertices;
      std::vector<GLuint> m_indices;
      
      Shader* m_shader;

      GLuint m_vbo, m_ebo, m_vao;
      GLint m_color; // Test!
    };

  }

}