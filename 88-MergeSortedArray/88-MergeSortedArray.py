# Last updated: 7/2/2026, 11:17:35 PM
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
       
        curr1 = 0
        curr2 = 0
        while curr2 < n:
            # if the val in nums2 is smaller or all of nums1 has been compared. 
            if curr1 >= m + curr2 or nums2[curr2] <= nums1[curr1]:
                nums1.insert(curr1, nums2[curr2])
                curr2 += 1
                nums1.pop()
            curr1 += 1
