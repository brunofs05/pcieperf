#pragma once

#include <cstddef> // Para usar size_t (tamanho em bytes)

namespace pcieperf {
namespace backend {

// Classe puramente virtual (Interface em C++)
class IGpuBackend {
public:
    // Destrutor virtual é obrigatório em interfaces C++ para evitar vazamento de memória
    virtual ~IGpuBackend() = default;

    // Inicializa a API (ex: seleciona a placa de vídeo)
    virtual bool Initialize() = 0;

    // Aloca memória travada (Pinned) na RAM do Host (CPU)
    virtual void* AllocateHostMemory(size_t size) = 0;
    virtual void FreeHostMemory(void* ptr) = 0;

    // Aloca memória na VRAM
    virtual void* AllocateDeviceMemory(size_t size) = 0;
    virtual void FreeDeviceMemory(void* ptr) = 0;

    // Executa as transferências via DMA (bloqueantes para medir o tempo)
    virtual void CopyHostToDevice(void* dstDevice, const void* srcHost, size_t size) = 0;
    virtual void CopyDeviceToHost(void* dstHost, const void* srcDevice, size_t size) = 0;
    
    // Sincroniza a GPU (espera todas as operações terminarem)
    virtual void Synchronize() = 0;
};

} // namespace backend
} // namespace pcieperf
