#pragma once

namespace Rendering {
    class Scene;
}

namespace Game {
    class Simulation {
    public:
        Simulation(Rendering::Scene *scene) : _scene(scene) {}

        virtual void Init() = 0;
        virtual void Step(float dt) = 0;

    protected:
        Rendering::Scene *_scene;
    };
}