package main

import (
	"bytes"
	"strconv"
)

// Vector vector type that contains elements
type Vector struct {
	elements []int
}

func newVector(size int, number int) Vector {
	elements := make([]int, size)
	for i := range elements {
		elements[i] = number
	}
	return Vector{elements}
}

// func (v *Vector) fill(number int) {
// 	for i := range v.elements {
// 		v.elements[i] = number
// 	}
// }

func (v *Vector) printVec() string {
	var buffer bytes.Buffer
	buffer.WriteString("( ")
	for _, el := range v.elements {
		buffer.WriteString(strconv.Itoa(el))
		buffer.WriteString(" ")
	}
	buffer.WriteString(")")
	// fmt.Println(buffer.String())
	return buffer.String()
}

func (v *Vector) min() int {
	min := v.elements[0]
	for _, el := range v.elements {
		if min > el {
			min = el
		}
	}
	return min
}

func (v *Vector) addVec(v2 *Vector) Vector {
	vec := newVector(N, 0)
	for i, el := range v.elements {
		vec.elements[i] = el + v2.elements[i]
	}
	return vec
}

func (v *Vector) multInt(n int) Vector {
	vec := newVector(N, 0)
	vec.elements = v.elements
	for i := range vec.elements {
		vec.elements[i] *= n
	}
	return vec
}

func (v *Vector) multMatrix(m *Matrix) Vector {
	vec := newVector(N, 0)
	for i := range v.elements {
		for j := range vec.elements {
			vec.elements[i] += m.elements[i][j] * v.elements[i]
		}
	}
	return vec
}

/* ==========================================
SORT(R + S)
==========================================*/
func (v *Vector) sortVec() {
	for itemCount := len(v.elements) - 1; ; itemCount-- {
		hasChanged := false
		for index := 0; index < itemCount; index++ {
			if v.elements[index] > v.elements[index+1] {
				v.elements[index], v.elements[index+1] = v.elements[index+1], v.elements[index]
				hasChanged = true
			}
		}
		if hasChanged == false {
			break
		}
	}
}
