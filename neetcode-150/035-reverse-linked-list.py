from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def reverseLinkedList(head: Optional[ListNode]) -> Optional[ListNode]:
    prev, curr = None, head

    while curr:
        curr.next, prev, curr = prev, curr, curr.next

    return prev


## Testing code:


def printLinkedList(linked_list: Optional[ListNode]) -> None:
    vals = []
    while linked_list:
        vals.append(str(linked_list.val))
        linked_list = linked_list.next
    print(" -> ".join(vals) if vals else "Empty list")


linked_list = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))


print("Original linked list:")
printLinkedList(linked_list)

reversed_linked_list = reverseLinkedList(linked_list)

print("Reversed linked list:")
printLinkedList(reversed_linked_list)
