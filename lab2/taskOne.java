
public class taskOne extends Thread {

    private Thread t;
    private int priority;
    private int sleep;

    // Конструктор таска(процеса)
    public taskOne(int p, int s) {
        priority = p;
        sleep = s;
        System.out.println("T1 Started");
        if (t == null) {
            t = new Thread(this);
            t.setPriority(priority);
        }
    }

    private double[] C = new double[lab2.N];
    private double[] B = new double[lab2.N];

    private double[][] MA = new double[lab2.N][lab2.N];
    private double[][] MD = new double[lab2.N][lab2.N];

    private double[] A = new double[lab2.N];

    @Override
    public void run() {

        try {
            Thread.sleep(sleep);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        fillVec(B, 1.0);
        fillVec(C, 1.0);
        fillMat(MA, 1.0);
        fillMat(MD, 1.0);

        double[] part1 = vecNumMult(B, vectorMin(C));
        double[][] part2 = matSum(matMult(MA, MD), MD);
        A = vecMacMult(part1, part2);

        displayResult(A);
        System.out.println("T1 finished");

    }

    private void fillVec(double[] vec, double num) {
        for (int i = 0; i < lab2.N; i++) {
            vec[i] = num;
        }
    }

    private void fillMat(double[][] mat, double num) {
        for (int i = 0; i < lab2.N; i++) {
            for (int j = 0; j < lab2.N; j++) {
                mat[i][j] = num;
            }
        }
    }

    private double vectorMin(double[] vector) {
        double min = vector[0];
        for (int i = 0; i < lab2.N; i++) {
            if (vector[i] < min) {
                min = vector[i];
            }
        }
        return min;
    }

    private double[] vecNumMult(double[] vec, double num) {
        double[] res = new double[lab2.N];
        for (int i = 0; i < lab2.N; i++) {
            res[i] = vec[i] * num;
        }
        return res;
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

    private double[] vecMacMult(double[] vec, double[][] mat) {
        double[] res = new double[lab2.N];
        for (int i = 0; i < lab2.N; i++) {
            for (int j = 0; j < lab2.N; j++) {
                res[i] += mat[i][j] * vec[i];
            }
        }
        return res;
    }

    private void displayResult(double[] vector) {
        System.out.print("( ");
        for (double aVector : vector) {
            System.out.print(aVector + " ");
        }
        System.out.println(")");
    }

}
