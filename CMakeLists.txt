cmake_minimum_required(VERSION 3.18)

# Projetct Name and usage Languages
project(pcieperf LANGUAGES CXX CUDA)

# Required c++ 17 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Search toolkit cuda in your SO Linux
find_package(CUDAToolkit REQUIRED)

# Define the final executable 
add_executable(pcieperf
    src/main.cpp
    src/backend/cuda/CudaBackend.cu
)

# Add include for compile
target_include_directories(pcieperf PRIVATE include)

# Linka library
target_link_libraries(pcieperf PRIVATE CUDA::cudart)

# Flags of otimization (max)
target_compile_options(pcieperf PRIVATE -O3)
