#pragma once

#include "Game/Simulation.h"
#include <memory>

namespace Physics {
    class Spring;
    class RigidBody;
}

namespace Rendering {
    class LeafCart;
    class LeafSpring;
}

namespace Simulations {

    class CartSpring : public Game::Simulation {
    public:
        CartSpring(Rendering::Scene *scene);
        ~CartSpring();

        void Init() override;
        void Step(const float dt) override;

    private:
        std::unique_ptr<Physics::Spring> _spring;
        std::unique_ptr<Physics::RigidBody> _cart;
        Rendering::LeafCart *_cartAppearence;
        Rendering::LeafSpring *_springAppearence;
    };
}