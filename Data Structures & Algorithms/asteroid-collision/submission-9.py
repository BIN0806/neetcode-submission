def sign(num):
    return num > 0 # positive

# [-2, -2, 1]
class Solution:
    
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        
        n = len(asteroids)

        res = [] 
        for a in asteroids:
            while res and (sign(res[-1]) and not sign(a)):
                if abs(res[-1]) < abs(a):
                    res.pop()
                    continue
                
                if abs(res[-1]) == abs(a):
                    res.pop()
                
                break
            else:
                res.append(a)   

        return res 
            
