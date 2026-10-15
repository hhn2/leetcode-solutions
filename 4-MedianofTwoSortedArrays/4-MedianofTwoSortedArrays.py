# Last updated: 10/14/2026, 11:58:24 PM
1class Solution:
2    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
3        #if this were one sorted list, we would just do binary search and find the median
4        #since this is two sorted list, we still do binary search
5        #we slice both arays so that 
6        #1. all left side nums are smaller than all right side nums
7        #2. left side has the same num of nums as the right side
8    
9        if len(nums1) > len(nums2):
10            temp = nums2
11            nums2 = nums1
12            nums1 = temp
13        l1, r1 = 0, len(nums1) 
14        m1 = (l1 + r1 + 1 ) //2
15
16        l2, r2 = 0, len(nums2) - 1
17        m2 = (len(nums1)+len(nums2)+1)//2 - m1
18
19        if len(nums1)==0:
20            if len(nums2) % 2 == 1:
21                return nums2[m2-1]
22            else:
23                return (nums2[m2-1] + nums2[m2]) /2
24        if len(nums2)==0:
25            if len(nums1) % 2 == 1:
26                return nums1[m1-1]
27            else:
28                return (nums1[m1-1] + nums1[m1] )/2
29        
30        while (l1 <=r1):
31            left1 = float('-inf') if m1 == 0 else nums1[m1 - 1]
32            left2 = float('-inf') if m2 == 0 else nums2[m2 - 1]
33            right1 = float('inf') if m1 == len(nums1) else nums1[m1]
34            right2 = float('inf') if m2 == len(nums2) else nums2[m2]
35                
36            if left1 > right2:
37                r1 = m1 - 1       # search left
38            elif left2 > right1:
39                l1 = m1 + 1       # search right
40            else:
41                break  
42            m1 = (l1 + r1 + 1) //2
43            m2 = (len(nums1)+len(nums2)+1)//2 - m1
44            print("m1 " + str(m1))
45            print("m2 " + str(m2))
46
47        if (len(nums1) + len(nums2)) % 2 == 0:
48            biggerleft = max(left1, left2)
49            smallerright = min(right1, right2)
50            return (biggerleft + smallerright) / 2
51        else: 
52            return max(left1, left2)
53
54    