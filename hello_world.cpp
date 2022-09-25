#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>

__global__ void hello_cuda(){
    printf("Hello CUDA world \n");
}

int main(){
    // dim3 is x,y,z
    // block size limitation is 1024, 1024, 64
    // x * y * z <= 1024
    // grid size limitation is 2^32 - 1, 65536, 65536
    
    // dim3 block(4);  // 4, 1, 1
    // dim3 grid(8);   // 8, 1, 1

    int nx, ny
    nx = 16;    // num threads in x and y (total of 20)
    ny = 4;

    dim3 block(8, 2);                        
    dim3 grid(nx / block.x, ny / block.y);   // 2, 2

    hello_cuda <<< grid, block >>> ();
    cudaDeviceSynchronize();

    cudaDeviceReset();
    return 0;
}