# 4-in-a-row
Minimax algorithm applied to the four-in-a-row game.<br>
You can clone the repository and compile the project or you can simply open bin/Debug and try the already compiled binary.<br>
The minimax code with the alpha-beta pruning optimizations reach the depth that you set at the beginning of the execution, the time complexity is potentially exponential so it is suggested to not go over 10.<br>
The implementation is thought to be re-usable for other projects only by changing a few lines of code in the file Minimax_agent.cpp (like the function to find successors) and by readapting the State.cpp.
