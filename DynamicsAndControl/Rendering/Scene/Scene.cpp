#include "stdafx.h"
#include "Rendering/Scene/Scene.h"
#include "Rendering/Primitives/Physics.h"

namespace Rendering
{
    void LeafCart::Accept(Renderer& r) { r.Render(this); }
    void LeafSpring::Accept(Renderer& r) { r.Render(this); }

    Scene::Scene() {}
    Scene::~Scene() {}

    LeafCart* Scene::InsertCart(float height, float width, float wheelRadius) {
        _leafs.push_back(std::make_unique<LeafCart>(static_cast<int>(_leafs.size()),
            height * kPixelsPerMeter,
            width * kPixelsPerMeter,
            wheelRadius * kPixelsPerMeter));
        return reinterpret_cast<LeafCart*>(_leafs.back().get());
    }

    LeafSpring* Scene::InsertSpring(float length, float wireLength, float turnsCount) {
        _leafs.push_back(std::make_unique<LeafSpring>(static_cast<int>(_leafs.size()),
            length * kPixelsPerMeter,
            wireLength * kPixelsPerMeter,
            turnsCount));
        return reinterpret_cast<LeafSpring*>(_leafs.back().get());
    }

    void Renderer::RenderScene(const Scene& scene) {
        for (const auto& el : scene) {
            el->Accept(*this);
        }
    }

    void Renderer::Render(const LeafCart* cart) {
        glPushMatrix();
        glMultMatrixf(glm::value_ptr(cart->GetRotation()));
        const auto t2 = kMatHomo;
        const auto t = cart->GetTranslation() * kPixelsPerMeter;
        glTranslatef(t.x, t.y, t.z);
        DrawCart(cart->GetHeight(), cart->GetWidth(), cart->GetWheelRadius());
        glPopMatrix();
    }

    void Renderer::Render(const LeafSpring* spring) {
        glPushMatrix();
        glMultMatrixf(glm::value_ptr(spring->GetRotation()));
        const auto t = spring->GetTranslation() * kPixelsPerMeter;
        glTranslatef(t.x, t.y, t.z);
        DrawSpring(spring->GetLength(), spring->GetWireLength(), spring->GetTurnsCount());
        glPopMatrix();
    }
}