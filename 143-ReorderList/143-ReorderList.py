# Last updated: 1/3/2026, 7:22:39 PM
1# Definition for singly-linked list.
2# class ListNode:
3#     def __init__(self, val=0, next=None):
4#         self.val = val
5#         self.next = next
6class Solution:
7    def reorderList(self, head: Optional[ListNode]) -> None:
8     
9        slow, fast = head, head
10        while fast.next and fast.next.next:
11            slow = slow.next
12            fast = fast.next.next
13    
14        second = slow.next
15        slow.next = None 
16        prev = None
17        while second:
18            next_node = second.next
19            second.next = prev
20            prev = second
21            second = next_node
22   
23        first, second = head, prev
24        while second:
25            tmp1, tmp2 = first.next, second.next
26            first.next = second
27            second.next = tmp1
28            first, second = tmp1, tmp2
29