from typing import List


def dailyTemperatures(temperatures: List[int]) -> List[int]:
    stack = []
    result = [0] * len(temperatures)

    for i, temp in enumerate(temperatures):
        while stack and temperatures[stack[-1]] < temp:
            top = stack.pop()
            result[top] = i - top

        stack.append(i)

    return result


print(dailyTemperatures([30, 38, 30, 36, 35, 40, 28]))
