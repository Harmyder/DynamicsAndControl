#pragma once
#include "stdafx.h"

#include "Rendering/Primitives/Graphics.h"

namespace Rendering {
    void Circle(const glm::vec2& center, float radius) {
        const int stepsCount = static_cast<int>(2 * static_cast<float>(M_PI) * radius + .5f);
        const float step = 2 * M_PI / stepsCount;
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < stepsCount; ++i) {
            const float x = radius * sin(step * i);
            const float y = radius * cos(step * i);
            glVertex3f(center.x + x, center.y + y, 0);
        }
        glEnd();
    }

    void Rectangle(const glm::vec2& lb, const glm::vec2& rt) {
        glBegin(GL_LINE_LOOP);
        glVertex3f(lb.x, lb.y, 0);
        glVertex3f(lb.x, rt.y, 0);
        glVertex3f(rt.x, rt.y, 0);
        glVertex3f(rt.x, lb.y, 0);
        glEnd();
    }
}
