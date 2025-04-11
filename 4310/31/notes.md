

## FUSE Filesystems

Filesystem in UserSpacE

A library and kernel module that lets us build filesystem drivers as userspace programs.

 - fusermount lets us mount a FUSE filesystem.
 - Any FS operations under the mountpoint result in callbacks to your program.
