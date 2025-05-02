
# Today: Final "Exam" Prep

During the final exam period, we'll do a final homework assignment,
worth two normal homeworks.

This will be completed in the classroom, with a hard due date
at the end of the lab period.

Today: A new topic, relevant to this final assignment.

Final period: Wed May 7th @ 8:00-10:30am, here


## New Topic: Non-blocking I/O

Problem: Concurrent program

Blocking I/O is an issue.

ex: read(0, ...), will stop our whole program until we get something on stdin.

We can solve this with processes / threads, but that's overkill if we're IO
bound.

Solution Non-blocking I/O

- When we open a file we can specify O_NONBLOCK to make calls to that
fd not block.
- Calls that would block now return an error and set errno to EWOULDBLOCK.

New problem: Just repeatedly calling read in a loop without blocking will
peg an entire CPU core, wasting power if nothing else.

Solution: We need a mechanism to block until something happens. Linux provides
a bunch of system calls to wait for events on file descriptors.

Today we'll look at select(2).



## Modifying a socket server to use non-blocking I/O

- Make read, accept calls non-blocking.
- Pull out our state from being one set of local variables into
  some structure that has state per connection.
- Use the select system call to block until something happens and
  figure out what we're doing next.








