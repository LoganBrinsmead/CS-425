# Results for Assignment 01

## Improvement Iterations

Here's a table showing the improvements I did to make the application go faster.  The **Time** column in the table represents the _wall-clock time_ for a program run.

| Version | Time | Speedup | Memory (KB) | Changes |
| :-----: | ---- | :-----: | :------: | ------- |
| [01](01.cpp) | 8.53s | &mdash; | 1041264 | Initial version - no changes |
| 02 | 1.75s | 4.87x | 1041260 | Compiled with -O3 to see about maximizing speed while sacrificing mathematical precision |
| 03 | 1.42s | 6.01x| 1041292 | used -Ofast flag to make the program faster at the expense of using more memory

## Profiling Analysis

# Initial Analyzation
I noticed that my initial program took 8.53s, which is a lot slower than yours (Dave's) which was 3.66s. I'm assuming it's probably because I ran this on an Ubuntu VM with limited resources. Just thought it was interesting to see how much my limited resources slowed it down (if they did).

### Speedup using -O3 flag
The program significantly sped up with the -O3 flag. The calculated value without this flag was 22150987, and with the -O3 flag the calculated value was 22150987. So the same value, so it seems like the flag didn't have much effect for this program in particular.


### Speedup using the -Ofast flag

An even more signifcant speedup. Since this flag uses more memory, my initial run of the program used 1041264 KB and with the -Ofast flag it was 1041292 KB so it used very very slightly more memory than the initial run.