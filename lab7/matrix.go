package main

import "fmt"

// Matrix matrix type that contains elements
type Matrix struct {
	elements [][]int
}

func newMatrix(size int, number int) Matrix {
	elements := make([][]int, size)
	for i := range elements {
		elements[i] = make([]int, size)
		for j := range elements[i] {
			elements[i][j] = number
		}
	}
	return Matrix{elements}
}

func (m *Matrix) printMatrix() {

	for _, row := range m.elements {
		fmt.Print("( ")
		for _, el := range row {
			fmt.Print(el)
			fmt.Print(" ")
		}
		fmt.Println(")")
	}
}

func (m *Matrix) addMatrix(m2 *Matrix) Matrix {
	mat := newMatrix(N, 0)
	for i := range m.elements {
		for j := range m.elements {
			mat.elements[i][j] = m.elements[i][j] + m2.elements[i][j]
		}
	}
	return mat
}

func (m *Matrix) multMatrix(m2 *Matrix) Matrix {
	mat := newMatrix(N, 0)
	for i := range m.elements {
		for j := range m.elements {
			for k := range m.elements {
				mat.elements[i][j] += m.elements[i][k] * m2.elements[k][j]
			}
		}
	}
	return mat
}

func (m *Matrix) transMatrix() {
	for i := range m.elements {
		for j := range m.elements {
			m.elements[i][j] = m.elements[j][i]
		}
	}
}
