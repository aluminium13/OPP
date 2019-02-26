
public class taskTwo extends Thread {

    private Thread t;
    private int priority;
    private int sleep;

    public taskTwo(int p, int s) {
        priority = p;
        sleep = s;
        System.out.println("T2 Started");
        if (t == null) {
            t = new Thread(this);
            t.setPriority(priority);
        }
    }

    private double[][] MA = new double[lab2.N][lab2.N];
    private double[][] MZ = new double[lab2.N][lab2.N];
    private double[][] MB = new double[lab2.N][lab2.N];

    private double[][] MK = new double[lab2.N][lab2.N];

    @Override
    public void run() {

        try {
            Thread.sleep(sleep);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        fillMat(MA, 2.0);
        fillMat(MZ, 2.0);
        fillMat(MB, 2.0);

        double[][] part1 = matMult(MA, matMult(MA, MZ));
        double[][] part2 = matTrans(MB);
        MK = matSum(part1, part2);

        displayResult(MK);
        System.out.println("T2 finished");

    }

    private void fillMat(double[][] mat, double num) {
        for (int i = 0; i < lab2.N; i++) {
            for (int j = 0; j < lab2.N; j++) {
                mat[i][j] = num;
            }
        }
    }

    private double[][] matMult(double[][] mat1, double[][] mat2) {
        double[][] res = new double[lab2.N][lab2.N];
        for (int i = 0; i < lab2.N; i++) {
            for (int j = 0; j < lab2.N; j++) {
                for (int k = 0; k < lab2.N; k++) {
                    res[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        return res;
    }

    private double[][] matSum(double[][] mat1, double[][] mat2) {
        double[][] res = new double[lab2.N][lab2.N];
        for (int i = 0; i < lab2.N; i++) {
            for (int j = 0; j < lab2.N; j++) {
                res[i][j] = mat1[i][j] + mat2[i][j];
            }
        }
        return res;
    }

    private double[][] matTrans(double[][] mat) {
        double[][] res = new double[lab2.N][lab2.N];
        for (int i = 0; i < lab2.N; i++) {
            for (int j = 0; j < lab2.N; j++) {
                res[i][j] = mat[j][i];
            }
        }
        return res;
    }

    private void displayResult(double[][] mat) {
        for (double[] row : mat) {
            System.out.print("( ");
            for (double a : row) {
                System.out.print(a + " ");
            }
            System.out.println(")");
        }
    }

}
