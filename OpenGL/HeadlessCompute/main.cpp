//=============================================================================
// Headless compute — GPU calculation without drawing (like 00c_Compute).
// Copyright 2018-2026 Quentin Quadrat <lecrapouille@gmail.com>
//=============================================================================

#include "GpuContext.hpp"

#include "Compages/GPU/Compute.hpp"

#include <cstdlib>
#include <iostream>
#include <string_view>
#include <vector>

namespace
{

constexpr std::size_t COUNT = 12u;
constexpr int MODULO = 60;

constexpr std::string_view STEP_SOURCE = R"(#version 450 core
layout(local_size_x = 16) in;

layout(std430, binding = 0) buffer Values
{
    int values[];
};

void main()
{
    uint i = gl_GlobalInvocationID.x;
    if (i >= uint(values.length())) { return; }
    values[i] = (values[i] + int(i) + 1) % 60;
}
)";

void printValues(char const* p_label, std::vector<int> const& p_values)
{
    std::cout << p_label;
    for (int value : p_values)
    {
        std::cout << ' ' << value;
    }
    std::cout << '\n';
}

} // namespace

//------------------------------------------------------------------------------
static compages::gpu::Status run()
{
    GpuContext context;
    COMPAGES_TRY(context.open({ .title = "Compages — headless compute",
                                .width = 1,
                                .height = 1,
                                .visible = false }));

    compages::gpu::ComputeProgram step;
    COMPAGES_TRY(step.load(STEP_SOURCE));

    std::vector<int> on_gpu(COUNT, 0);
    compages::gpu::Buffer<int> values;
    COMPAGES_TRY_ASSIGN(
        values,
        compages::gpu::Buffer<int>::from(on_gpu,
                                         { .kind = compages::gpu::BufferKind::Storage,
                                           .usage = compages::gpu::BufferUsage::Storage }));
    COMPAGES_TRY(values.upload());

    printValues("CPU before: ", on_gpu);

    COMPAGES_TRY(compages::gpu::dispatch(step, values));

    compages::gpu::Result<std::vector<int>> read = values.read();
    if (!read)
    {
        return compages::gpu::failure(read.error());
    }

    printValues("GPU after:  ", read.value());

    if (read.value().empty() || read.value().front() != 1)
    {
        return compages::gpu::failure("unexpected result on values[0]");
    }

    std::cout << "Headless compute OK.\n";
    return compages::gpu::success();
}

//------------------------------------------------------------------------------
int main()
{
    if (compages::gpu::Status done = run(); !done)
    {
        std::cerr << done.error() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
