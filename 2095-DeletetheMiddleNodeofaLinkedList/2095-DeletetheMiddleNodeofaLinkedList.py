# Last updated: 1/17/2026, 7:37:08 PM
1# Definition for singly-linked list.
2# class ListNode:
3#     def __init__(self, val=0, next=None):
4#         self.val = val
5#         self.next = next
6class Solution:
7    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
8        if not head.next:
9            return None
10
11        if not head.next.next:
12            head.next = None
13            return head
14
15        before = head
16        middle = head.next
17        after = head.next.next
18
19        n = 3
20        ln = after
21
22        while ln.next:
23            n += 1
24
25            if n % 2 == 0:
26                before = middle
27                middle = after
28                after = after.next
29
30            ln = ln.next
31
32        before.next = after
33        return head
34