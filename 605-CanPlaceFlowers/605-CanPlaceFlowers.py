class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        available = 0

        past = 0 

        for i in range(len(flowerbed)):
            if flowerbed[i] == 0:
                # check if previous is empty(or it is the first element) and next is empty(or it is the las element)
                if (i == 0 or flowerbed[i - 1] == 0) and (i == len(flowerbed) - 1 or flowerbed[i + 1]== 0):
                    available += 1
                    # we must actually place the flower so that it doesn't get read as an empty spot
                    flowerbed[i] = 1

            

        return available >= n