

# OS Kernel

What's a kernel?

Component of the operating system that:

 - always runs when the system is booted
 - mediates access to the hardware for programs
 
Kernel code can do stuff that regular programs can't:

 - Use physical memory addresses
 - Execute any CPU instruction
   - Including instructions that set special registers,
     like the page table register
 - Directly send commands to hardware (e.g. disks, netowrk devices,
   I/O devices, etc).

If our program wants to use hardware, that'll happen in two steps:

 - Kernel <=> Hardware
 - User Code <=> Kernel (system calls)


## System calls

AMD64 assembly:

```
    mov $1, %rax
    syscall
```

Intel 32-bit assembly

```
    mov $1, %eax
    int 0x80
```


```C
function int80_handler() {
    // make sure all the syscall argument are in the right spot
    syscall_table[%eax]();
}
```
