// Assignment1Q1
package main

import (
	"fmt"
)
var sizeFt []roomSz

type House struct{
rooms []string
name string
roomsize  []roomSz
}
type roomSz struct{
 width float32
 length float32
}

type Home interface{
inputSqft()
printMetric()
}

func NewHouse() House{
house := House{}
house.name = "House"
house.rooms = []string{"kitchen" , "living" , "dining" , "main"}
sizeFt = make([]roomSz, len(house.rooms))
return house
}

func NewHouseRooms(newRooms []string) House{
newhouse := NewHouse()
newhouse.rooms = append(newhouse.rooms,newRooms...)
sizeFt = make([]roomSz, len(newhouse.rooms))
return newhouse
}

func (house House) inputSqft(){
 var width float32
 var length float32
 fmt.Printf("%s\n",house.name)
	for i := 0; i < len(house.rooms); i++ {
fmt.Printf("%s : width x length:", house.rooms[i])
fmt.Scanf("%fx%f\n", &width,&length)

sizeFt[i] =  roomSz{width, length}
}
}

func (house House) printMetric(){
fmt.Printf("\n%s\n", house.name)
var width float32
var length float32
for i := 0; i < len(house.rooms); i++ {
width = sizeFt[i].width/3.2808
length = sizeFt[i].length/3.2808

fmt.Printf("%s : %.2f x %.2f m\n",house.rooms[i],width,length)
}
}

type Semi struct{
semiHouse House
}

func NewSemi() House{
house := Semi{}
house.semiHouse.name = "Semi"
house.semiHouse.rooms = []string{"kitchen" , "living" , "dining" , "main"}
sizeFt = make([]roomSz, len(house.semiHouse.rooms))
return house.semiHouse
}

func NewSemiRooms(newRooms []string) House{
newhouse := NewSemi()
newhouse.rooms = append(newhouse.rooms,newRooms...)
sizeFt = make([]roomSz, len(newhouse.rooms))
return newhouse
}

func main(){
homes := []Home{NewHouse(), NewSemi(), NewHouseRooms([]string{"bedroom1","bedroom2"})}

for i:= 0 ; i <len(homes) ; i++ {
homes[i].inputSqft()
}
for i:= 0 ; i <len(homes) ; i++ {
homes[i].printMetric()
}

}