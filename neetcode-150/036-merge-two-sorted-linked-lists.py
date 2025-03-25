from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def mergeTwoLists(
    list1: Optional[ListNode], list2: Optional[ListNode]
) -> Optional[ListNode]:
    dummy = ListNode()
    tail = dummy

    while list1 and list2:
        if list1.val < list2.val:
            tail.next = list1
            list1 = list1.next
        else:
            tail.next = list2
            list2 = list2.next

        tail = tail.next

    tail.next = list1 or list2

    return dummy.next


## Testing code


def print_list(head: Optional[ListNode]) -> None:
    """Helper function to print linked list."""
    values = []
    while head:
        values.append(str(head.val))
        head = head.next
    print(" -> ".join(values) if values else "Empty list")


list1 = ListNode(1, ListNode(2, ListNode(4)))

list2 = ListNode(1, ListNode(3, ListNode(5)))

print("List 1:")
print_list(list1)

print("List 2:")
print_list(list2)

merged_list = mergeTwoLists(list1, list2)

print("Merged List:")
print_list(merged_list)
