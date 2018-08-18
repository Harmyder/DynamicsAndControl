#pragma once

#include <vector>
#include <memory>
#include "Physics/Base.h"

namespace Rendering
{
    enum class PrimitiveType;

    class Renderer;

    static const float kPixelsPerMeter = 100.f;

    class Leaf : public Physics::Base
    {
    public:
        Leaf(int indexInContainer) : _indexInContainer(indexInContainer) {}

        virtual void Accept(Renderer&) = 0;
        int GetIndexInContainer() { return _indexInContainer; }

    private:
        int _indexInContainer; // To be able to find leaf in container to delete it
    };
    
    class LeafCart : public Leaf {
    public:
        LeafCart(int indexInContainer, float height, float width, float wheelRadius) : Leaf(indexInContainer), _height(height), _width(width), _wheelRadius(wheelRadius) {}
        void Accept(Renderer& r) override;
        float GetWidth() const { return _width; }
        float GetWheelRadius() const { return _wheelRadius; }
        float GetHeight() const { return _height; }
    private:
        float _height;
        float _width;
        float _wheelRadius;
    };

    class LeafSpring : public Leaf {
    public:
        LeafSpring(int indexInContainer, float length, float wireLength, float turnsCount) : Leaf(indexInContainer), _length(length), _wireLength(wireLength), _turnsCount(turnsCount) {}
        void Accept(Renderer& r) override;
        float GetLength() const { return _length; }
        float GetWireLength() const { return _wireLength; }
        float GetTurnsCount() const { return _turnsCount; }
        void SetLength(float length) { _length = length * kPixelsPerMeter; }
    private:
        float _length;
        float _wireLength;
        float _turnsCount;
    };

    class Scene
    {
    public:
        Scene();
        ~Scene();

        LeafCart*   InsertCart(float height, float width, float wheelRadius);
        LeafSpring* InsertSpring(float length, float wireLength, float turnsCount);

        auto cbegin() const { return _leafs.cbegin(); }
        auto cend()   const { return _leafs.cend(); }
        auto begin() const { return _leafs.cbegin(); }
        auto end()   const { return _leafs.cend(); }
        auto begin() { return _leafs.begin(); }
        auto end()   { return _leafs.end(); }

    private:
        std::vector<std::unique_ptr<Leaf>> _leafs;
    };

    class Renderer
    {
    public:
        void RenderScene(const Scene& scene);
        void Render(const LeafCart* cart);
        void Render(const LeafSpring* spring);
    };
}

