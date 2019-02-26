
public class taskThree extends Thread {

    private Thread t;
    private int priority;
    private int sleep;

    // Конструктор таска(процеса)
    public taskThree(int p, int s) {
        priority = p;
        sleep = s;
        System.out.println("T3 Started");
        if (t == null) {
            t = new Thread(this);
            t.setPriority(priority);
        }
    }

    private double[] R = new double[lab2.N];
    private double[] S = new double[lab2.N];

    private double[][] MT = new double[lab2.N][lab2.N];
    private double[][] MP = new double[lab2.N][lab2.N];

    private double[] O = new double[lab2.N];

    @Override
    public void run() {

        try {
            Thread.sleep(sleep);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        fillVec(R, 3.0);
        fillVec(S, 3.0);
        fillMat(MT, 3.0);
        fillMat(MP, 3.0);

        double[] part1 = vecSort(vecSum(R, S));
        double[][] part2 = matMult(MT, MP);
        O = vecMacMult(part1, part2);

        displayResult(O);
        System.out.println("T3 finished");

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

    private double[] vecSum(double[] vec1, double[] vec2) {
        double[] res = new double[lab2.N];
        for (int i = 0; i < lab2.N; i++) {
            res[i] = vec1[i] + vec2[i];
        }
        return res;
    }

    private double[] vecSort(double[] vec) {
        double[] arr = vec;
        int n = lab2.N;
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1]) {
                    double temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
        return arr;
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
