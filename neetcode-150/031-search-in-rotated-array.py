from typing import List


def searchInRotatedArray(nums: List[int], target: int) -> int:
    l = 0
    r = len(nums) - 1

    while l <= r:
        m = l + (r - l) // 2
        if nums[m] == target:
            return m

        # Left half is sorted
        if nums[l] <= nums[m]:
            if nums[l] <= target < nums[m]:
                r = m - 1
            else:
                l = m + 1

        # Right half is sorted
        else:
            if nums[m] < target <= nums[r]:
                l = m + 1
            else:
                r = m - 1

    return -1


print(searchInRotatedArray([3, 4, 5, 6, 1, 2], 4))
