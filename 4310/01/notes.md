

# CS 4310: Operating Systems

Problem: How can we run two programs at the same time on a computer?

 - When you type, which program sees the keys you pressed?
   - Only one? Which one?
   - Both? That sounds bad.
 - The operating system is a program that takes ownership of shared
   resources (like the keyboard) and delegates access to other programs.

Kinds of resource that need to be managed:

 - Physical memory
 - The CPU
 - Networking
 - The display
 - (Any hardware)
 - A shared filesystem, where each file / directory / etc is a shared resource.
