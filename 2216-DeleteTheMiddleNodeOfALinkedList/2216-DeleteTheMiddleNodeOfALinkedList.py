# Last updated: 2/19/2026, 1:34:37 PM
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head.next:
            return None

        if not head.next.next:
            head.next = None
            return head

        before = head
        middle = head.next
        after = head.next.next

        n = 3
        ln = after

        while ln.next:
            n += 1

            if n % 2 == 0:
                before = middle
                middle = after
                after = after.next

            ln = ln.next

        before.next = after
        return head
