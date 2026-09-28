//=============================================================================
// Triangle — Compages drawable filled by attribute name (like 01b_Triangle).
// Copyright 2018-2026 Quentin Quadrat <lecrapouille@gmail.com>
//=============================================================================

#include "GpuContext.hpp"

#include "Compages/GPU/Drawable.hpp"
#include "Compages/GPU/RenderPass.hpp"

#include <cstdlib>
#include <iostream>

namespace
{

constexpr char const* VERTEX_SHADER = R"(#version 450 core

in vec2 position;
in vec3 color;

out vec3 vColor;

void main()
{
    vColor = color;
    gl_Position = vec4(position, 0.0, 1.0);
}
)";

constexpr char const* FRAGMENT_SHADER = R"(#version 450 core

in vec3 vColor;
out vec4 oColor;

void main()
{
    oColor = vec4(vColor, 1.0);
}
)";

} // namespace

//------------------------------------------------------------------------------
int main()
{
    GpuContext context;
    if (compages::gpu::Status ready = context.open(
            { .title = "Compages — Triangle", .width = 800, .height = 600 });
        !ready)
    {
        std::cerr << ready.error() << std::endl;
        return EXIT_FAILURE;
    }

    compages::gpu::Drawable triangle;
    if (compages::gpu::Status setup = triangle.load(VERTEX_SHADER, FRAGMENT_SHADER);
        !setup)
    {
        std::cerr << setup.error() << std::endl;
        return EXIT_FAILURE;
    }

    triangle["position"] = { { -0.8f, -0.6f }, { 0.8f, -0.6f }, { 0.0f, 0.8f } };
    triangle["color"]    = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };

    if (compages::gpu::Status prepared = triangle.prepare(); !prepared)
    {
        std::cerr << prepared.error() << std::endl;
        return EXIT_FAILURE;
    }

    while (!context.shouldClose())
    {
        context.pollEvents();

        int const width = context.framebufferWidth();
        int const height = context.framebufferHeight();
        if ((width > 0) && (height > 0))
        {
            // Pass sur la fenêtre (comme la galerie) : clear + draw dans la même cible.
            compages::gpu::RenderPass screen(compages::gpu::PassDesc{
                .width = static_cast<std::uint32_t>(width),
                .height = static_cast<std::uint32_t>(height),
                .color = { 0.1f, 0.1f, 0.15f, 1.0f },
            });
            triangle.draw();
        }

        if (compages::gpu::hasFrameError())
        {
            std::cerr << compages::gpu::takeFrameError() << std::endl;
            return EXIT_FAILURE;
        }

        context.swapBuffers();
    }

    return EXIT_SUCCESS;
}
