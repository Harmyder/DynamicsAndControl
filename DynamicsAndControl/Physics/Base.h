#pragma once

#include <glm/vec3.hpp>

namespace Physics {
    class Base {
    public:
        glm::mat4 GetRotation() const { return _rotation; }
        glm::vec4 GetTranslation() const { return _translation; }

        void SetRotation(const glm::mat4& rotation) { _rotation = rotation; }
        void SetTranslation(const glm::vec4& translation) { _translation = translation; }

    private:
        glm::mat4 _rotation = kMatEye;
        glm::vec4 _translation = kVecUnitW;
    };
}