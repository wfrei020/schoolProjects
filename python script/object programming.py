# Question 3 : Object Programming
# House class
#
class House:
    # instance variables
    listofRooms = ['kitchen' , 'living', 'dinning', 'main']
    rooms = []
    houseType = 'House'
    metricRoom = []
    #constructor
    def __init__(self, newRooms=None ):
        if newRooms is None:
               self.rooms = self.listofRooms
              
        else:
            self.rooms = self.listofRooms + newRooms
            

    # Converting square feet to metric
    def inputSqft(self):
        numRooms = 0
        # First go through each room given in the listofrooms, and find the width and length numbers provided
        while numRooms < len(self.rooms):
            dim = input(self.rooms[numRooms] +' : width x length: ')
            width = dim[0]
            countx = 1
            # the following while loop starts to search for the x, anything previous to it add it and make a string for width
            while dim[countx] != 'x':
                width = width + dim[countx]
                countx = countx+1
            countx = countx+1
            length = dim[countx]
            countx = countx+1
            # now find the length
            while countx < len(dim):
                length = length + dim[countx]
                countx =countx+1
            #convert the width and length strings into floats and convert to metric    
            metric =  "{0:.2f} x {1:.2f}".format(float(width)*0.3048 , float(length)*0.3048)
            self.metricRoom = self.metricRoom + [self.rooms[numRooms] + ' : ' + metric]
            numRooms = numRooms + 1


    # this prints the metric results
    def printMetric(self):
        print(self.houseType , end = '\n')
        x = 0
        while x < len(self.metricRoom):
                 print(self.metricRoom[x] , ' m', end= '\n')
                 x = x+1

# the Semi class which inherets the House class and set the houseType variable to Semi
class Semi(House):

    def __init__(self):
        super(Semi,self).__init__()
        self.houseType = 'Semi'

        
    
