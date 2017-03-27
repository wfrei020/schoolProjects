# question 2
# assumptions: the files car_imperial.txt and an empty car_metric.txt are already created in the working directory
# first open the files
doc = open('car_imperial.txt' , 'r')
newDoc = open('car_metric.txt' , 'w')
#read the first line and then loop until the last line is empty
lin = doc.readline()
while lin != "":
    commasMil,i = 0,0
	# loop until it finds 3 commas because we know then the milage starts
    while commasMil < 3:
        if lin[i] == ",":
            commasMil = commasMil + 1
        i = i + 1
    S = lin[i+1]
    startoffuelCons = i+1
    i = i+2
	# now begin to collect milage until it finds an empty space
    while lin[i] != " ":
        S = S+lin[i]
        i = i+1
	#convert milage into an integer
    milage =int(S)
    i = i+5
    S = lin[i+1]
    i = i+2
	# again loop and collect volume until it find a space and then convert to an integer the accumulated string
    while lin[i] != " ":
        S = S+lin[i]
        i = i+1
    volume = int(S)

    buildNew = 0
    newString = lin[buildNew]
    buildNew = buildNew +1
	# this final loop is to make a new string from the initial string given until it reaches the begining of the milage point
    while buildNew < startoffuelCons:
        newString = newString + lin[buildNew]
        buildNew= buildNew +1
    milageString = "{0:.1f}".format(235.21/milage)
    volumeString = "{0:.3f}".format(volume*0.0283168)
	# after it adds all the previous string then add the new portion which is the metric conversion
    newString = newString  + str(milageString) +" litre/100 km, " + str(volumeString) +" m^3\n" 
    #now write into new file
    newDoc.write(newString)
	#repeat until the lines are done
    lin = doc.readline()
#close the files
doc.close()
newDoc.close()
