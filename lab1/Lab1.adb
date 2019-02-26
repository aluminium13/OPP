--==========================================



-- F1: A = B*MIN(C) *(MA*MD+MD)
-- F2: MK = MA*(MA*MZ) + TRANS(MB)
-- F3: O = SORT(R + S)*(MT*MP)


--==========================================

with Data;
with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with System.Multiprocessors; use System.Multiprocessors;

procedure Lab1 is

   N: Integer := 1000;

   package LabData is new Data(N);
   use LabData;

   package Float_IO is new Ada.Text_IO.Float_IO(Float);
   use Float_IO;

   cpu0: CPU_Range := 0;
   cpu1: CPU_Range := 1;
   cpu2: CPU_Range := 2;

   procedure Tasks is

      task T1 is
         pragma Priority(1);
         pragma Storage_Size(1000000000);
         pragma CPU(cpu0);
      end;

      task body T1 is
         A, B, C: Vector;
         MA, MD: Matrix;
      begin
         Put_Line("Task T1 Started");
         fillVector(B, 1.0);
         fillVector(C, 1.0);
         fillMatrix(MA, 1.0);
         fillMatrix(MD, 1.0);
         delay 0.4;
         Func1(B, C, MA, MD, A);
         vectorPrint(A);
         Put_Line("Task T1 Ended");
      end;

      task T2 is
         pragma Priority(2);
         pragma Storage_Size(1000000000);
         pragma CPU(cpu1);
      end;

      task body T2 is
         MK, MA, MZ, MB: Matrix;
      begin
         Put_Line("Task T2 Started");
         fillMatrix(MA, 2.0);
         fillMatrix(MZ, 2.0);
         fillMatrix(MB, 2.0);
         delay 0.1;
         Func2(MA, MZ, MB, MK);
         matrixPrint(MK);
         Put_Line("Task T2 Ended");
      end;

      task T3 is
         pragma Priority(3);
         pragma Storage_Size(1000000000);
         pragma CPU(cpu2);
      end;

      task body T3 is
         R, S, O: Vector;
         MT, MP: Matrix;
      begin
         Put_Line("Task T3 Started");
         fillVector(R, 3.0);
         fillVector(S, 3.0);
         fillMatrix(MT, 3.0);
         fillMatrix(MP, 3.0);
         delay 0.3;
         Func3(R, S, MT, MP, O);
         vectorPrint(O);
         Put_Line("Task T3 Ended");
      end;

   begin
      null;
   end Tasks;

begin
   Tasks;
end Lab1;
