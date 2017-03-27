# CSI 3120 Assignment 4 Solution
# Student Name: Walter Freire
# Student Number: 6399015
# Student Email: wfrei020@uottawa.ca

#please note that the whole assignment was done is this one script

currentYear = 2016
numberOfYears =1
SimulationYears = 3
#-------------------------Question 1-2-3 together in this code----------------------------
rowNames <- c("A/C", "Appliances", "Toys")
colNames <- c("January","February" ,"March","April","May","June","July","August","September","October","November","December")
InventoryYearList = list(NULL,NULL,NULL)
YearSalesList = list(NULL,NULL,NULL)
names(InventoryYearList)=c(paste(currentYear,"sales",sep = " "),
                              paste(currentYear+1,"sales",sep = " "),
                              paste(currentYear+2,"sales",sep = " "))
names(YearSalesList)=c(paste(currentYear,"sales",sep = " "),
                              paste(currentYear+1,"sales",sep = " "),
                              paste(currentYear+2,"sales",sep = " "))

MinInventory = matrix(c(10,10,10,10,10,30,50,50,30,10,10,10,
                        40,40,40,40,40,40,40,40,40,40,40,40,
                        40,40,40,40,40,40,40,40,40,40,400,400),nrow=3,ncol=12,byrow=TRUE,dimnames=list(rowNames,colNames))
while(numberOfYears <= SimulationYears){



YearSales = matrix(nrow = 3,ncol = 12,byrow = FALSE,dimnames=list(rowNames,colNames))
InventoryOrder = matrix(nrow = 3,ncol = 12,byrow = FALSE,dimnames=list(rowNames,colNames))

i = 1

#start iterating through each category
while(i<=3){
  j = 1
  
  average = 0
  #A/C Category
  if(i ==1){
    while(j <= 12){
    average = 5
    if(j == 6 |j==9){
      average = 30
      YearSales[i, j] = rpois(1,average)}
    else if(j == 7){
      average = 45
      YearSales[i, j] = rpois(1,average)}
    else if(j == 8){
      average = 50
      YearSales[i, j] = rpois(1,average)}
    else{YearSales[i, j] = rpois(1,average)}
    j = j+1}
    }
  #Appliances category
  else if(i ==2){
    while(j<=12){
    average = runif(1,min =10 , max = 40)
    YearSales[i,j] = rpois(1,average)
    j = j+1}}
  #Toys category
  else {
    while(j<=12){
      average = rnorm(1,mean = 30,sd = 9)
      if(j==11){
        average =average + runif(1,min = 100, max =200)
        average
      }
      else if(j==12){
        average = average + runif(1,min=300,max=400)
      }
      
      YearSales[i,j] = round(average)
      j= j+1
    }}
  i=i+1
}

i = 1

while(i<=3){
  j = 1
  while(j<=12){
    if(YearSales[i,j] <= MinInventory[i,j]){InventoryOrder[i,j] = YearSales[i,j]}
    else{InventoryOrder[i,j] = MinInventory[i,j]}
    j = j+1
  }
  i=i+1
}

InventoryYearList[[numberOfYears]] = InventoryOrder
YearSalesList[[numberOfYears]] = YearSales


numberOfYears = numberOfYears+1

}
#-----------------------------will print all result for Question 2 -----------------------
print("Orders Automatically filled")
print(InventoryYearList[[1]]);
#------------------------------Simulation Data Completed for 3 years-------------------------------------
#----------------------calculate averages of each category for all years--------------------
i=2
AverageSales = YearSalesList[[1]]
AverageInventory = InventoryYearList[[1]]

while(i<3){
  TempSales = YearSalesList[[i]]
  TempInventory = InventoryYearList[[i]]
  j = 1
  while(j<=3){
    k =1
    while(k<=12){
    AverageSales[j,k] = AverageSales[j,k] + TempSales[j,k]
    AverageInventory[j,k] = AverageInventory[j,k]+TempInventory[j,k]
    k = k+1
    }
  j = j+1
      }
  
  
  i=i+1
}

i = 1
while(i<=3){
  j = 1
  while(j <=12){
    AverageSales[i,j] = round(AverageSales[i,j]/3)
    AverageInventory[i,j] = round(AverageInventory[i,j]/3)
    j = j+1
  }

  i = i+1
}
#------------------------------calculating averages completed-----------------------------------

#------------Histogram showing overall average for sales in categories------------------------------
#data for histogram
ACAverageSales = AverageSales[1,1:12]
APPAverageSales =AverageSales[2,1:12]
TOYSAverageSales = AverageSales[3,1:12]
ACAverageInv = AverageInventory[1,1:12]
APPAverageInv =AverageInventory[2,1:12]
TOYSAverageInv = AverageInventory[3,1:12]

#chart file names
  png(file = "Histogram.png")
  par(mfrow=c(2,3))
  hist(ACAverageSales,prob=TRUE, main = "A/C Average Sales", col = "red",xlab = "Average Sale")
  lines(density(ACAverageSales))
  hist(APPAverageSales, prob=TRUE,main = "Appliances Average Sales", col = "red",xlab = "Average Sale")
  lines(density(APPAverageSales))
  hist(TOYSAverageSales, prob=TRUE,main = "Toys Average Sales", col = "red",xlab = "Average Sale")
  lines(density(TOYSAverageSales))
  hist(ACAverageInv,prob=TRUE, main = "A/C Average Inventory", col = "red",xlab = "Average inventory")
  lines(density(ACAverageInv))
  hist(APPAverageInv,prob=TRUE, main = "Appliances Average Inventory", col = "red",xlab = "Average inventory")
  lines(density(APPAverageInv))
  hist(TOYSAverageInv,prob=TRUE, main = "Toys Average Inventory", col = "red",xlab = "Average inventory")
  lines(density(TOYSAverageInv))
  garbage = dev.off()
#-------------------------------------Histogram completed-------------------------------------  
  
#-----------------Average Line graphs of sales for each category every year--------------------
  
  ACCAverageSalesYear1=0
  APPAverageSalesYear1 = 0
  TOYSAverageSalesYear1 = 0
  ACCAverageSalesYear2=0
  APPAverageSalesYear2 = 0
  TOYSAverageSalesYear2 = 0
  ACCAverageSalesYear3=0
  APPAverageSalesYear3 = 0
  TOYSAverageSalesYear3 = 0
    j = 1
    while(j <=12){
      ACCAverageSalesYear1 = ACCAverageSalesYear1 + YearSalesList[[1]][1,j]
      APPAverageSalesYear1 =  APPAverageSalesYear1 + YearSalesList[[1]][2,j]
      TOYSAverageSalesYear1 = TOYSAverageSalesYear1 + YearSalesList[[1]][3,j]
      ACCAverageSalesYear2 = ACCAverageSalesYear2 + YearSalesList[[2]][1,j]
      APPAverageSalesYear2 =  APPAverageSalesYear2 + YearSalesList[[2]][2,j]
      TOYSAverageSalesYear2 = TOYSAverageSalesYear2 + YearSalesList[[2]][3,j]
      ACCAverageSalesYear3 = ACCAverageSalesYear3 + YearSalesList[[3]][1,j]
      APPAverageSalesYear3 =  APPAverageSalesYear3 + YearSalesList[[3]][2,j]
      TOYSAverageSalesYear3 = TOYSAverageSalesYear3 + YearSalesList[[3]][3,j]
      j = j+1
    }
  
ACCTotal = c(round(ACCAverageSalesYear1/12),round(ACCAverageSalesYear2/12),round(ACCAverageSalesYear3/12))
APPTotal = c(round(APPAverageSalesYear1/12),round(APPAverageSalesYear2/12),round(APPAverageSalesYear3/12))
TOYSTotal = c(round(TOYSAverageSalesYear1/12),round(TOYSAverageSalesYear2/12),round(TOYSAverageSalesYear3/12))

lineData  <- matrix(c(ACCTotal,APPTotal,TOYSTotal), ncol=3)
png(file = "LineGraphs.jpg")

matplot(lineData, type = c("b"),pch=1,col = 1:3,xlab = "Year", ylab="Average Sales",main = "Average Sales For 3 Years") #plot
legend("center", legend = c("A/C" , "Appliance" , "Toys"), col=1:3, pch=1) # optional legend

garbage=dev.off()


#-------------------------------Line Graphs completed--------------------------------------

#-------------12 Pie Chart for Year 2 for sales of each category each month---------------
year2Data = YearSalesList[[2]]

i = 1
labels = c("A/C","Appliances","Toys")
png(file = "PieChartJan_June.png")
par(mfrow=c(2,3))

while(i<=6){
    PIEDATA2 = c(year2Data[1,i],year2Data[2,i],year2Data[3,i])
    
    switch(i,
           pie(PIEDATA2,labels,main = paste("January,", currentYear+1,"Sales",sep = " ")),
           pie(PIEDATA2,labels,main = paste("February,", currentYear+1,"Sales",sep = " ")),
           pie(PIEDATA2,labels,main = paste("March,", currentYear+1,"Sales",sep = " ")),
           pie(PIEDATA2,labels,main = paste("April,", currentYear+1,"Sales",sep = " ")),
           pie(PIEDATA2,labels,main = paste("May,", currentYear+1,"Sales",sep = " ")),
           pie(PIEDATA2,labels,main = paste("June,", currentYear+1,"Sales",sep = " ")))
i = i+1;
    }
garbage = dev.off()

i=1
png(file = "PieChartJuly_DEC.png")
par(mfrow=c(2,3))

while(i<=6){
  PIEDATA2 = c(year2Data[1,i+6],year2Data[2,i+6],year2Data[3,i+6])
  
  switch(i,
         pie(PIEDATA2,labels,main = paste("July,", currentYear+1,"Sales",sep = " ")),
         pie(PIEDATA2,labels,main = paste("August,", currentYear+1,"Sales",sep = " ")),
         pie(PIEDATA2,labels,main = paste("September,", currentYear+1,"Sales",sep = " ")),
         pie(PIEDATA2,labels,main = paste("October,", currentYear+1,"Sales",sep = " ")),
         pie(PIEDATA2,labels,main = paste("November,", currentYear+1,"Sales",sep = " ")),
         pie(PIEDATA2,labels,main = paste("December,", currentYear+1,"Sales",sep = " ")))
  i = i+1;
}
garbage=dev.off()

#-------------------------------------monthly pies complete-----------------------------------

#---------Bar Plots of each categories showing the sales for each month and year---------------

SalesACTable = as.table(matrix(c(YearSalesList[[1]][1,1:12],YearSalesList[[2]][1,1:12],YearSalesList[[3]][1,1:12]),ncol=12, byrow = TRUE,dimnames=list(c("2016","2017","2018"),colNames)))
SalesAPPTable = as.table(matrix(c(YearSalesList[[1]][2,1:12],YearSalesList[[2]][2,1:12],YearSalesList[[3]][2,1:12]),ncol=12, byrow = TRUE,dimnames=list(c("2016","2017","2018"),colNames)))
SalesTOYTable = as.table(matrix(c(YearSalesList[[1]][3,1:12],YearSalesList[[2]][3,1:12],YearSalesList[[3]][3,1:12]),ncol=12, byrow = TRUE,dimnames=list(c("2016","2017","2018"),colNames)))

png(file = "BarPlotACSales.png")
barplot(SalesACTable, main="A/C Sales from 2016-2018",xlab="Months", col=c("darkblue","red","yellow"),legend = c("2016","2017","2018"), beside=TRUE)
garbage = dev.off()
png(file = "BarPlotAPPSales.png")
barplot(SalesAPPTable, main="Appliance Sales from 2016-2018",xlab="Months", col=c("darkblue","red","yellow"),legend = c("2016","2017","2018"), beside=TRUE)
garbage =dev.off()
png(file = "BarPlotTOYSales.png")
barplot(SalesTOYTable, main="Toy Sales from 2016-2018",xlab="Months", col=c("darkblue","red","yellow"),legend = c("2016","2017","2018"), beside=TRUE)
garbage = dev.off()
#-------------------------------------Bar plots complete----------------------------------


#------------------------------------Questions 3 scripts----------------------------------

#------------------------------------------Part 1------------------------------------------

#print max Apliances
i =1
TempSales = YearSalesList[[1]]
max = 0
month = 0;
while(i <=12 ){
  if(max < TempSales[2,i]){max = TempSales[2,i]
  month = i}
  i = i+1
  
}

print(paste("In 2016 the max home Appliances was Sold in ",colNames[month],"with" ,max ,"units sold.",sep = " "))


#------------------------------------------Part 2----------------------------------------
TempSales = YearSalesList[[2]]
i = 1
accu = 0
print("In 2017 the Months that sold more than 50 toys are:")
while(i <= 12){
 if(TempSales[3,i]>=50){
   print(colNames[i])
   accu = accu+TempSales[3,i]}
  i=i+1
}

print(paste("With an Accumulated sales of:", accu,sep=" "))


#------------------------------------------Part 3-------------------------------------------------

TempSales = YearSalesList[[3]]
#note: ACCAverageSales variable is the sum and not the average...naming wrong but can be calculate
ACCYear3 = round(ACCAverageSalesYear3/12)
dat = c(TempSales[1,1:12]-ACCYear3)


png(file = "BarPlotAC.png")
#barplot(vector,names.arg = Months,ylab="yaxis",xlab = "xaxis",col="blue",main ="title")
barplot(dat,main="Difference in 2018 sales from the 2018 Average Sales",names.arg=colNames , xlab="months")
garbage = dev.off()

#------------------------------------------EOF-------------------------------------------------
