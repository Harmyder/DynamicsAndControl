#include "stdafx.h"
#include "Game/Game.h"

#include "Common/Timer.h"
#include <algorithm>

namespace Game {
    Game::Game(float dt) : _desiredDt(dt), _dt(dt), _timer(std::make_unique<Common::Timer>()) {}

    Game::~Game() {}

    void Game::ResetSimulation(std::unique_ptr<Simulation>& s) {
        _sim = std::move(s);
    }

    void Game::Run() {
        _sim->Init();
        while (true) {
            _startTicks = _timer->GetCounts();
            _sim->Step(_dt);
            const float waitingTime = WaitForDeltaTime();
            if (waitingTime < 0) { // we are lagging behind, increase dt
//                _dt -= waitingTime;
            }
            else if (_dt > _desiredDt) {
//                _dt = std::max(_desiredDt, _dt - waitingTime);                
            }
        }
    }

    float Game::WaitForDeltaTime() {
        const uint64 dtInTicks = static_cast<uint64>(_dt * _timer->GetFrequency());
        uint64 currDtInTicks = _timer->GetCounts() - _startTicks;
        const float waitingTime = _dt - static_cast<float>(currDtInTicks * _timer->GetInvFrequency());
        while (currDtInTicks < dtInTicks) {
            currDtInTicks = _timer->GetCounts() - _startTicks;
        };
        return waitingTime;
    }
}
