"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        # [(1, 10), (13, 15), (1,5), (6,10), (1, 5)]
        # ----------| --
        # -----|-----  
        # -----|
        # 1 2 3 4 5

        # [(1, 4), (1,5), (1, 10), (6,10), (6,10), (13, 100000000)]
        # ----- | -----
        # -----      ----------
        # -----------


        # we will have a heapq of intervals
        # have a priority queue for verllaping intervals
        # and when we pop from priorty queue we rest the counter 
        # repeat
        # return the max at a all teams

        # import heapq
        # intervals.sort(key = lambda x: x.start)
        # active_rooms = []

        # for interval in intervals:
        #     start, end = interval.start, interval.end
        #     # ended already
        #     if active_rooms and active_rooms[0] <= start:
        #         heapq.heappop(active_rooms)
        #     heapq.heappush(active_rooms, end)

        # return len(active_rooms)
 


        # min_rooms = 0
        # start_times = sorted([interval.start for interval in intervals])
        # end_times = sorted([interval.end for interval in intervals])

        # n = len(intervals)
        # l = r = 0
        # count = 0
        # while l < n:
        #     if start_times[l] < end_times[r]:
        #         l += 1
        #         count += 1
        #     else:
        #         r += 1
        #         count -= 1
        #     min_rooms = max(min_rooms, count)

        # return min_rooms






    
        # intervals.sort(key= lambda x: x.start)
        # current_end_times = []

        # for interval in intervals:
        #     heapq.heappush(current_end_times, interval.end)
        #     if interval.start >= current_end_times[0]:
        #         heapq.heappop(current_end_times)

        # return len(current_end_times)


        # counter = defaultdict(int)
        # for i in intervals:
        #     counter[i.start] += 1
        #     counter[i.end] -= 1

        # counts, res = 0, 0 
        # for i in sorted(counter.keys()):
        #     counts += counter[i]
        #     res = max(res, counts)

        # return res



        start = sorted([interval.start for interval in intervals])
        end = sorted([interval.end for interval in intervals])
        n = len(start)

        res = count = 0
        l = r = 0 

        print(start)
        print(end)

        # [1, 5, 10, 15]
        # [5, 10, 15, 20]

        while l < n:
            start_time, end_time = start[l], end[r]
            
            print(f"Best: {res}")
            print(f"Count so far:{count}")
            print(l, start_time)
            print(r, end_time)
            if end_time <= start_time:
                count -= 1
                r += 1
            if end_time > start_time:
                count += 1
                l += 1

            
            res = max(res, count)
        return res


