//=============================================================================
// LinkAgainstMyLibs — minimal GLFW window + Compages GPU init.
// Copyright 2018-2026 Quentin Quadrat <lecrapouille@gmail.com>
//=============================================================================

#pragma once

#include "Compages/GPU/GPU.hpp"

#include <string>

struct GLFWwindow;

// ****************************************************************************
//! \brief Owns a GLFW window and a Compages GPU context (init / shutdown).
// ****************************************************************************
class GpuContext
{
public:

    struct Options
    {
        std::string title{ "Compages" };
        int width{ 800 };
        int height{ 600 };
        //! \brief When false, the window is suitable for compute-only work.
        bool visible{ true };
    };

    GpuContext() = default;
    ~GpuContext();

    GpuContext(GpuContext const&) = delete;
    GpuContext& operator=(GpuContext const&) = delete;

    [[nodiscard]] compages::gpu::Status open(Options const& p_options);

    [[nodiscard]] bool ready() const { return m_window != nullptr; }
    [[nodiscard]] GLFWwindow* window() const { return m_window; }

    [[nodiscard]] bool shouldClose() const;
    [[nodiscard]] int framebufferWidth() const;
    [[nodiscard]] int framebufferHeight() const;
    void pollEvents();
    void swapBuffers();

private:

    GLFWwindow* m_window{ nullptr };
    bool m_glfw_ready{ false };
    bool m_device_ready{ false };
};
