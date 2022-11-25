#include <iostream>

int main {

/*
Program memory map:
-Earlier we've seen that the program instructions are loaded onto RAM when it is executed.
-In reality programs don't use 'acutal memory' as because of the sheer number of programs running on our OS, we can quickly run out of memory.
-So we use the concept of virtual memory.
-Virtual memory is a trick that fools the program into thinking it is the only program running on the OS, and all memory resources belong to it.
- The view of that virtual memory, from the point of view of the program is called a memory map.
-Each memory map is abstracted into a process (eg, the .exe or .o's that we've been building can be seen as processes on the system)
-Each process has acces from 0-(2^n)-1 bits where n is the number of bits the OS supports (eg, 32,64) (because 2^n descibes the largest number that can be used to define a memory block or the places a limit on the size of the memory that can be managed by the OS. There isn't a way to store the address of memory blocks that exceed 2^n bits)
- The process believes that it entirely owns the memory allocated to it.


So, lets now reconsider the program execution model:
We start with the c++ source code 
> The source code is compiled into executable/binary code (representation of how things are laid out in the memory)
> We execute the binary/executable
> The binary code is passed throught the Memory Management Unit (MMU) of the CPU
> The MMU transforms between the memory map of the process and the physical memory (RAM) layout
- The entire program is not loaded in real memory by the CPU and MMU. Only parts that are about to be executed are loaded, making effective use of real memory, a valuable and lacking resource. Parts that are not used are discared from memory and stored on the hard drive instead.

TL;DR: The MMU helps out in mapping between the memory map we have in the program (ie the idea that the program has of memory) and the real thing that we have in memory.)

eg. consider that we are running 2 15 GB programs on 16gb of memory. The reason that it can run simultaneously is that the MMU only loads the instrunction relevant to the next execution step into the physical memory. Each program, however (through its own memory map), believes that it has access to the entire 16GB of ram.
(See slides at 10:33:33)

The memory map is a standard format defined by the OS. All programs written for that OS must conform to it. It is usually divided into some sections: 
(See slides at 10:34:23)
- System
- Stack
- Heap
- Data
- Text

For our purposes we will focus on the stack and heap (see slides at 10:35:33)
Stack - stores our local variables
Heap - We get additional memory that we can use during run time.
       Heap is super important for dynamic memory allocation.
Text - Loads the actual binary of the program so that the CPU can execute it



*/


    return 0;
}