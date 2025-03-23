class TimeMap:
    def __init__(self):
        self.db = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.db:
            self.db[key] = []
        self.db[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.db:
            return ""

        body = self.db[key]

        l, r = 0, len(body) - 1
        result = ""

        while l <= r:
            m = l + (r - l) // 2

            if body[m][0] <= timestamp:
                result = body[m][1]
                l = m + 1
            else:
                r = m - 1

        return result


time_map = TimeMap()

time_map.set("foo", "bar", 1)
time_map.set("foo", "bar2", 4)
time_map.set("foo", "bar3", 6)

print(time_map.get("foo", 1))  # Expected: "bar"
print(time_map.get("foo", 3))  # Expected: "bar"
print(time_map.get("foo", 4))  # Expected: "bar2"
print(time_map.get("foo", 5))  # Expected: "bar2"
print(time_map.get("foo", 6))  # Expected: "bar3"
print(time_map.get("foo", 10))  # Expected: "bar3"
print(time_map.get("foo", 0))  # Expected: "" (no previous value)
print(time_map.get("bar", 1))  # Expected: "" (key does not exist)
