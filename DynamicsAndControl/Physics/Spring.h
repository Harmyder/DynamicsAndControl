#pragma once
#include "Physics/Base.h"

namespace Physics
{
    class Spring : public Base {
    public:
        Spring(float k, float restLength, float delta) : _k(k), _restLength(restLength), _delta(delta) {}

        float GetK()          const { return _k; }
        float GetRestLength() const { return _restLength; }
        float GetDelta()      const { return _delta; }
        void SetDelta(float delta) { _delta = delta; }

    private:
        const float _k;
        const float _restLength;
        float _delta;
    };
}
