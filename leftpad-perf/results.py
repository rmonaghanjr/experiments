import sys

results = {}

for line in sys.stdin:
    split_line = line.split(":")

    strlen = int(split_line[0])
    size = int(split_line[1])
    function_name = split_line[2]
    time = float(split_line[3])

    if str(strlen) not in results:
        results[str(strlen)] = {}

    if function_name not in results[str(strlen)]:
        results[str(strlen)][function_name] = []
    results[str(strlen)][function_name].append(str(time * 1000))

for length in results:
    print("strsize = "+length+","+(",".join([str(i) for i in [0, 1, 100, 1000, 1000000]])))
    for fname in results[length]:
        print(fname+","+(",".join(results[length][fname])))

