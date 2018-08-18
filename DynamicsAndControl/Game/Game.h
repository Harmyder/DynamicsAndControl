#pragma once
#include <memory>
#include "Game/Simulation.h"

namespace Common {
    class Timer;
}

namespace Game {
    class Game {
    public:
        Game(float dt);
        ~Game();

        void ResetSimulation(std::unique_ptr<Simulation>& s);

        void Run();
        
    private:
        float WaitForDeltaTime();
        
        const float _desiredDt;
        float _dt;
        uint64 _startTicks;
        std::unique_ptr<Common::Timer> _timer;
        
        std::unique_ptr<Simulation> _sim;
    };
}