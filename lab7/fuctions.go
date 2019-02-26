package main

import (
	"fmt"
)

//F1 A = B*MIN(C) *(MA*MD+MD)
func F1() {
	myWaitGroup.Add(1)
	fmt.Println("T1 started")

	B := newVector(N, 1)
	C := newVector(N, 1)
	MA := newMatrix(N, 1)
	MD := newMatrix(N, 1)

	vec := B.multInt(C.min())
	mat := MA.multMatrix(&MD)
	mat2 := mat.addMatrix(&MD)
	A := vec.multMatrix(&mat2)

	fmt.Println("T1 result: \n" + A.printVec())
	fmt.Println("T1 ended")
	// F1Ch <- "T1 ended"
	myWaitGroup.Done()

}

//F2 MK = MA*(MA*MZ) + TRANS(MB)
func F2() {
	myWaitGroup.Add(1)
	fmt.Println("T2 started")

	MA := newMatrix(N, 2)
	MZ := newMatrix(N, 2)
	MB := newMatrix(N, 2)

	mat := MA.multMatrix(&MZ)
	mat2 := MA.multMatrix(&mat)
	MB.transMatrix()
	MK := mat2.addMatrix(&MB)

	fmt.Println("T2 result:")
	MK.printMatrix()

	fmt.Println("T2 ended")
	// F2Ch <- "T2 ended"
	myWaitGroup.Done()

}

// F3  O = SORT(R + S)*(MT*MP)
func F3(F3Ch chan string) {
	fmt.Println("T3 started")

	R := newVector(N, 3)
	S := newVector(N, 3)
	MT := newMatrix(N, 3)
	MP := newMatrix(N, 3)

	vec := R.addVec(&S)
	vec.sortVec()
	mat := MT.multMatrix(&MP)
	O := vec.multMatrix(&mat)

	fmt.Println("T3 result: \n" + O.printVec())

	// fmt.Println("T3 ended")
	F3Ch <- "T3 ended"
}
