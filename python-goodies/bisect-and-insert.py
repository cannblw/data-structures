from bisect import bisect_left, bisect_right

arr = [1, 3, 3, 5, 7, 9]
print(arr)

# bisect_left finds the first position where 3 can be inserted such that the order is preserved.
# This means it places the new 3 before the first existing 3.
index_left = bisect_left(arr, 3)
print(f"bisect_left: Insert 3 at index {index_left}")  # Expected output: 1

# bisect_right finds the last position where 3 can be inserted.
# It places the new 3 after the last existing 3.
index_right = bisect_right(arr, 3)
print(f"bisect_right: Insert 3 at index {index_right}")  # Expected output: 2

# No duplicate items => bisect_right and bisect_left will returnt he same value
index_right = bisect_right(arr, 6)
print(f"bisect_right: Insert 6 at index {index_right}")  # Expected output: 4

arr.insert(index_right, 6)

print(arr)
