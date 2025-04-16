
Hints:

 - The assignment has been updated a couple times (doc fixes),
   so reload.
 - To read a response, you'll need to make sure you read
   all hdr.len bytes. In general, that will take two recv calls
   per message (one to get the header, one to get the rest).
