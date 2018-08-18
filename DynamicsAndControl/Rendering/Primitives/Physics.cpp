#include "stdafx.h"

#include "Rendering/Primitives/Physics.h"
#include "Rendering/Primitives/Graphics.h"

namespace Rendering {
    //    /\   ...   /\  /\
    //  \/  \/     \/  \/
    void DrawSpring(const float length, const float wireLength, const int turnsCount) {
        glBegin(GL_LINE_STRIP);
        const float step = length / static_cast<float>(turnsCount);
        const float turnWireLength = wireLength / turnsCount;
        const float side = std::sqrt(turnWireLength * turnWireLength - step * step);

        //  
        //  \ 
        glm::vec2 start{ 0, 0 };
        glVertex3f(start.x, start.y, 0);
        glm::fvec2 curr(start.x + step * .25f, start.y + side);
        glVertex3f(curr.x, curr.y, 0);

        //   /\   ...   /\
        //  /  \/     \/  \ 
        for (int i = 0; i < turnsCount - 1; ++i) {
            curr.x = start.x + step * (i + .5f + .25f);
            curr.y = start.y - side;
            glVertex3f(curr.x, curr.y, 0);
            curr.x = start.x + step * (i + 1.f + .25f);
            curr.y = start.y + side;
            glVertex3f(curr.x, curr.y, 0);
        }

        //   /\
        //  /
        curr.x = start.x + step * (turnsCount - 1 + .5f + .25f);
        curr.y = start.y - side;
        glVertex3f(curr.x, curr.y, 0);
        curr.x = start.x + step * turnsCount;
        curr.y = start.y;
        glVertex3f(curr.x, curr.y, 0);

        glEnd();
    }

    void DrawCart(const float height, const float width, const float wheelRadius) {
        glm::ivec2 lb{ 0, 0 };
        Rectangle(glm::vec2(lb.x, lb.y + 2 * wheelRadius), glm::vec2(lb.x + width, lb.y + height));
        Circle(glm::vec2(lb.x + wheelRadius, lb.y + wheelRadius), wheelRadius);
        Circle(glm::vec2(lb.x + width - wheelRadius, lb.y + wheelRadius), wheelRadius);
    }
}
