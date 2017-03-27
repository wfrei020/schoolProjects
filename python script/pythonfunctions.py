# cubeless(2,10) = 2
def cubeless(x,b): return b - x*x*x

# smallerCube(130) = [(1, 129), (2, 122), (3, 103), (4, 66), (5, 5)] 

def smallerCube(b):
		LL = [(x,cubeless(x,b)) for x in range(1,b) if cubeless(x,b) > 0]
		return LL
# restSum(smallerCube(130))

def restSum(S):
        x,restsum = 0,0
        while len(S) > x:
            restsum,x =restsum+S[x][1],x+1
        return restsum
# showAllRestSum(1,20) 
def showAllRestSum(a,b):
    LL = [(x,restSum(smallerCube(x))) for x in range(a,b) if restSum(smallerCube(x))%3 == 0]
    print(LL)
    


