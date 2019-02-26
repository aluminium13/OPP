/* ==========================================
Основи Паралельного програмування
Лабораторна робота №7
Процеси в мові Golang
Варіант 10
F1: A = B*MIN(C) *(MA*MD+MD)
F2: MK = MA*(MA*MZ) + TRANS(MB)
F3: O = SORT(R + S)*(MT*MP)
Кузьменко Олександра Вікторівна ІО-62
дата: 21.11.2018
==========================================*/

package main

import (
	"fmt"
	"sync"
)

// N size of vectors & matrixs
const N = 4

var myWaitGroup sync.WaitGroup

func main() {

	fmt.Println("Main routine started")

	// F1Ch := make(chan string)
	// F2Ch := make(chan string)
	F3Ch := make(chan string)

	go F1()
	go F2()
	go F3(F3Ch)

	fmt.Println("Waiting for all goroutines to exit")
	myWaitGroup.Wait()
	// fmt.Println(<-F1Ch)
	// fmt.Println(<-F2Ch)
	fmt.Println(<-F3Ch)
	fmt.Println("Main routine ended")
}
