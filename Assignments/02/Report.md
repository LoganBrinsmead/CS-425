# Report
I am running this program on Blue.

### I ran the program initially without changing anything and got the runtime: 2m3.464s

First attempt at threading: I'm pushing a commit with my first attempt at threading with commit message "first attempt at threading". I attempted to thread the program by dividing the vector of records into tenths and processing the values that way. When it doesn't segfault, I am getting a worse runtime, but thought it would be worthwile to still push my attempt.

### Runtime with initial attempt at threading: 15m

After reviewing the code on blue, I rearranged mine and reran it and got much better time with the testcases and got 1 minute. The output isn't quite there, though, and I'm trying to discover what the issue is.

### Runtime after rearranging with the example code on blue: 1m3.232s

The above was all with the test values. I reran the code with the final values

### runtime on blue with unthreaded program, final values: 52m3.222s

I reran my code with the final test values and my threaded code

### runtime on blue with threaded program, final values: 27m3.212s