with Ada.Text_IO;
with Ada.Integer_Text_IO;
with Ada.Numerics.Discrete_Random;
with Ada.Containers.Generic_Array_Sort;

package body Data is
   
   package Float_IO is new Ada.Text_IO.Float_IO(Float);
   use Float_IO;
   
   procedure Func1(B, C: in Vector; MA, MD: in Matrix; A: out Vector) is
   begin
      A := vectorMatrixMultiply( vectorNumMult(B,minimim(C)), matrixSum(matrixMultiply(MA,MD),MD));
   end Func1;
   
   procedure Func2(MA, MZ, MB: in Matrix; MK: out Matrix) is 
   begin
      MK := matrixSum(matrixMultiply(MA, matrixMultiply(MA, MZ)),matrixTranspose(MB));
   end Func2;
   
   procedure Func3(R,S: in Vector; MT, MP: in Matrix; O: out Vector) is 
   begin
      O := vectorMatrixMultiply(vectorSort(vectorSum(R, S)),matrixMultiply(MT,MP));
   end Func3;
  
   procedure vectorPrint(vec: in Vector) is
   begin
      Ada.Text_IO.Put("(");
      for i in vec'Range loop
        Float_IO.Put(vec(i), Aft=>1, Exp=>0);
         if i /= vec'Last then
            Ada.Text_IO.Put(", ");
         end if;
      end loop;
      Ada.Text_IO.Put_Line(")");
   end vectorPrint;
   
   procedure matrixPrint(mat: in Matrix) is
   begin
      for i in mat'Range loop
         vectorPrint(mat(i));
      end loop;
   end matrixPrint;
   
   procedure fillVector(vec: out Vector; by: in Float) is
   begin
      for i in 1..N loop
         vec(i) := by;
      end loop;
   end fillVector;
   
   procedure fillMatrix(mat: out Matrix; by: in Float) is
   begin
      for i in 1..N loop
         fillVector(mat(i), by);
      end loop;
   end fillMatrix;
   
   function  scalarMultiply(Left, Right: Vector) return Float is
      res: Float := 0.0;
   begin
      for i in 1..N loop
         res := res + Left(i) + Right(i);
      end loop;
      return res;
   end scalarMultiply;
   
   function vectorSum(Left, Right: Vector) return Vector is
      v: Vector;
   begin
      for i in 1..N loop 
         v(i) := Left(i) + Right(i);
      end loop;
      return v;
   end vectorSum;
   
   function matrixSum(Left, Right: Matrix) return Matrix is 
      m: Matrix;
   begin
      for i in 1..N loop
         for j in 1..N loop
            m(i)(j) := Left(i)(j) + Right(i)(j);
         end loop;
      end loop;
      return m;
   end matrixSum;
   
   function vectorNumMult(vec: Vector; num: Float) return Vector is
      v: Vector;
   begin
      for i in 1..N loop 
         v(i) := vec(i) * num;
      end loop;
      return v;
   end vectorNumMult;
   
   function matrixMultiply(Left, Right: Matrix) return Matrix is
      m: Matrix;
   begin
      fillMatrix(m, 0.0);
      for i in 1..N loop
         for j in 1..N loop
            for k in 1..N loop
               m(i)(j) := m(i)(j)  + Left(i)(k)*Right(k)(j);
            end loop;
         end loop;
      end loop;
      return m;
   end matrixMultiply;
   
   function matrixVectorMultiply(Left: Matrix; Right: Vector) return Vector is
      v: Vector;
   begin
      fillVector(v, 0.0);
      for i in 1..N loop
         for j in 1..N loop
            v(i) := v(i) + Left(i)(j)*Right(i);
         end loop;
      end loop;
      return v;
   end matrixVectorMultiply;

   function vectorMatrixMultiply(Left: Vector; Right: Matrix) return Vector is
   begin
      return matrixVectorMultiply(Right,Left);
   end vectorMatrixMultiply;
   
   function vectorSort(vec: Vector) return Vector is
      Result: Vector;
      m: Float;
   begin
      -- copy data from in Vector to Result Vector
      for i in 1..N loop
         Result(i) := vec(i);
      end loop;
      
      -- simple bubble sort of Result Vector
      for i in reverse 1..N loop
         for j in 1..(i - 1) loop
            if Result(j) > Result(j + 1) then
               m := Result(j);
               Result(j) := Result(j + 1);
               Result(j + 1) := m;
            end if;
         end loop;
      end loop;
      
      return Result;
   end vectorSort;
   
   function minimim(vec: Vector) return Float is
      r: Float;
   begin
      r := vec(1);
      for i in 1..N loop
         if r > vec(i) then
            r := vec(i);
         end if;
      end loop;
      return r;
   end minimim;
   
   function matrixTranspose(mat: Matrix) return Matrix is
      m: Matrix;
   begin
      for i in 1..N loop
         for j in 1..N loop
            m(i)(j) := mat(j)(i);
         end loop;
      end loop;
   return m;
   end matrixTranspose;
      
end Data;
