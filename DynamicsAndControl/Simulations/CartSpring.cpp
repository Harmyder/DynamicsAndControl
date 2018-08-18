#include "stdafx.h"
#include "Simulations/CartSpring.h"
#include "Physics/RigidBody.h"
#include "Physics/Spring.h"
#include "Rendering/Scene/Scene.h"

namespace Simulations {
    CartSpring::CartSpring(Rendering::Scene *scene) : Simulation(scene) {}
    CartSpring::~CartSpring() {}

    void CartSpring::Init() {
        _cart = std::make_unique<Physics::RigidBody>(1.f);
        _cart->SetTranslation(glm::vec4{ 2.5,0,0,1 });
        _cart->SetVelocity(kVecZero);
        _cartAppearence = _scene->InsertCart(1.f, 2.f, .2f);
        _spring = std::make_unique<Physics::Spring>(.5f, 1.f, .5f);
        _spring->SetTranslation(glm::vec4{ 1.f,.5f,.0f,1.f });
        _springAppearence = _scene->InsertSpring(1.f, 2.f, 10);
    }

    void CartSpring::Step(const float dt) {
        const float forceScalar = -_spring->GetDelta() * _spring->GetK();
        const glm::vec4 force = kVecUnitX * forceScalar * _spring->GetRotation();
        const float mass = _cart->GetMass();
        const glm::vec4 acc = force / mass;
        const auto velocity = _cart->GetVelocity() + acc;
        _cart->SetVelocity(velocity);
        const glm::vec4 ds = velocity * dt * 10.f;
        _cart->SetTranslation(_cart->GetTranslation() + ds);
        const auto springDir = _spring->GetRotation() * kVecUnitX;
        const float dsAbs = glm::dot(springDir, ds);
        _spring->SetDelta(_spring->GetDelta() + dsAbs);

        _cartAppearence->SetTranslation(_cart->GetTranslation());
        _cartAppearence->SetRotation(_cart->GetRotation());
        _springAppearence->SetTranslation(_spring->GetTranslation());
        _springAppearence->SetRotation(_spring->GetRotation());
        _springAppearence->SetLength(_spring->GetRestLength() + _spring->GetDelta());
    }
}
