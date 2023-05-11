# leftpad-perf
In this experiment, I test the performance of various leftpad implementations as well as my own, due to the recent dependency chain failure on NPM in regards to react.

# results
Results can be viewed here:
[Results](https://docs.google.com/spreadsheets/d/1eAe3zd_cT-A2jwwNUE9de68Heu05FPr27UciZXwyaEA/edit?usp=sharing)

# summary
Both the `npm` implementation, the `while loop` implementation, and the `for loop` implementation all follow a linear time complexity however it is notable that the `for` implementaiton is faster than the while loop implementations. My own implementation is considerably faster than the aforementioned implementations. It resembles a logarithmic time complexity just by visually looking at the graph. I will likely be doing more implementations and comparing more results later on.
