generic N: Integer;

package data is

   type Vector is array(1..N) of Float;
   type Matrix is array(1..N) of Vector;
   
   procedure Func1(B, C: in Vector; MA, MD: in Matrix; A: out Vector);
   procedure Func2(MA, MZ, MB: in Matrix; MK: out Matrix);
   procedure Func3(R,S: in Vector; MT, MP: in Matrix; O: out Vector);

   procedure vectorPrint(vec: in Vector);
   procedure matrixPrint(mat: in Matrix);
   
   procedure fillVector(vec: out Vector; by: in Float);
   procedure fillMatrix(mat: out Matrix; by: in Float);
   
private
   function scalarMultiply(Left, Right: Vector) return Float;
   function vectorSum(Left, Right: Vector) return Vector;
   function matrixSum(Left, Right: Matrix) return Matrix;
   function vectorNumMult(vec: Vector; num: Float) return Vector;
   function matrixMultiply(Left, Right: Matrix) return Matrix;
   function matrixVectorMultiply(Left: Matrix; Right: Vector) return Vector;
   function vectorMatrixMultiply(Left: Vector; Right: Matrix) return Vector;
   function vectorSort(vec: Vector) return Vector;
   function minimim(vec: Vector) return Float;
   function matrixTranspose(mat: Matrix) return Matrix;
   
end data;
