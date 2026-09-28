//=============================================================================
// LinkAgainstMyLibs — minimal GLFW window + Compages GPU init.
// Copyright 2018-2026 Quentin Quadrat <lecrapouille@gmail.com>
//=============================================================================

#include "GpuContext.hpp"

#include <GLFW/glfw3.h>

namespace
{

std::string glfwReason()
{
    char const* why = nullptr;
    glfwGetError(&why);
    return (why == nullptr) ? "no reason given" : why;
}

} // namespace

//------------------------------------------------------------------------------
compages::gpu::Status GpuContext::open(Options const& p_options)
{
    if (glfwInit() == GLFW_FALSE)
    {
        return compages::gpu::failure("GLFW could not start: " + glfwReason());
    }
    m_glfw_ready = true;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
    glfwWindowHint(GLFW_DEPTH_BITS, 24);
    glfwWindowHint(GLFW_VISIBLE, p_options.visible ? GLFW_TRUE : GLFW_FALSE);

    m_window = glfwCreateWindow(p_options.width,
                                p_options.height,
                                p_options.title.c_str(),
                                nullptr,
                                nullptr);
    if (m_window == nullptr)
    {
        return compages::gpu::failure(
            "No OpenGL 4.5 core context: " + glfwReason());
    }

    glfwMakeContextCurrent(m_window);
    if (p_options.visible)
    {
        glfwSwapInterval(1);
    }

    COMPAGES_TRY(compages::gpu::init(
        reinterpret_cast<compages::gpu::LoadProc>(glfwGetProcAddress)));
    m_device_ready = true;

    return compages::gpu::success();
}

//------------------------------------------------------------------------------
GpuContext::~GpuContext()
{
    if (m_device_ready)
    {
        compages::gpu::shutdown();
    }
    if (m_window != nullptr)
    {
        glfwDestroyWindow(m_window);
    }
    if (m_glfw_ready)
    {
        glfwTerminate();
    }
}

//------------------------------------------------------------------------------
bool GpuContext::shouldClose() const
{
    return (m_window == nullptr) || (glfwWindowShouldClose(m_window) != GLFW_FALSE);
}

//------------------------------------------------------------------------------
int GpuContext::framebufferWidth() const
{
    int width = 0;
    if (m_window != nullptr)
    {
        glfwGetFramebufferSize(m_window, &width, nullptr);
    }
    return width;
}

//------------------------------------------------------------------------------
int GpuContext::framebufferHeight() const
{
    int height = 0;
    if (m_window != nullptr)
    {
        glfwGetFramebufferSize(m_window, nullptr, &height);
    }
    return height;
}

//------------------------------------------------------------------------------
void GpuContext::pollEvents()
{
    glfwPollEvents();
}

//------------------------------------------------------------------------------
void GpuContext::swapBuffers()
{
    if (m_window != nullptr)
    {
        glfwSwapBuffers(m_window);
    }
}
