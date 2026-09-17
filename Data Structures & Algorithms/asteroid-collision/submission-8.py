def sign(num):
    return num > 0 # positive

# [-2, -2, 1]
class Solution:
    
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        
        n = len(asteroids)

        res = [asteroids[0]] 
        for r in range(1, n):

            if res and (sign(res[-1]) and not sign(asteroids[r])):
                if abs(res[-1]) < abs(asteroids[r]):
                    res.pop()

                elif res[-1] == abs(asteroids[r]):
                    res.pop()
            else:
                res.append(asteroids[r])   

        return res 
            
