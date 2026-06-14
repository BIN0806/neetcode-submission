class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l, r, area = 0,len(heights)-1 ,0
        while l < r:
            width = r - l
            height = min(heights[l], heights[r])
            if heights[l] > heights[r]:
                r -= 1
            else:
                l += 1
            area = max(area, width*height)
        return area