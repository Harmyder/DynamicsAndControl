#pragma once
#include "Physics/Base.h"
#include "glm/vec3.hpp"

namespace Physics
{
    class RigidBody : public Base {
    public:
        RigidBody(float mass) : _mass(mass) {}

        float     GetMass()     const { return _mass; }
        glm::vec4 GetVelocity() const { return _velocity; }
        void SetVelocity(glm::vec4 velocity) { _velocity = velocity; }

    private:
        const float _mass = 0.f;
        glm::vec4 _velocity = kVecZero;
    };
}
