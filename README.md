# GET_NEXT_LINE
####
- gnl_for_BUF-1 - Implementation variant without a static variable
- tru_gnl_for_42 - Implementation in 5 functions using a static variable
- test - Files for testing
####
## What is GNL ?
- Function which returns a line read from afile descriptor, without the newline.
- Calling your functionget_next_linein a loop will then allow you to read the textavailable on a file descriptor one line at a time until the EOF.
