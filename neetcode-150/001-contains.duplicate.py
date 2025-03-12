from typing import List


def hasDuplicate(nums: List[int]) -> bool:
    return len(set(nums)) < len(nums)


print(hasDuplicate([1, 2, 3, 3]))
