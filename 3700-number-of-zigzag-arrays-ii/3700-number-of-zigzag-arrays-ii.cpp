class Solution {
    long long mod = 1e9+7;
    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B, int m) {
        Matrix C(m, vector<long long>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int k = 0; k < m; k++) {
                if (A[i][k] == 0) continue;
                long long aik = A[i][k];
                for (int j = 0; j < m; j++) {
                    C[i][j] = (C[i][j] + aik * B[k][j]) % mod;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix A, long long p, int m) {
        Matrix res(m, vector<long long>(m, 0));
        for (int i = 0; i < m; i++) res[i][i] = 1; 
        
        while (p > 0) {
            if (p & 1) res = multiply(res, A, m);
            A = multiply(A, A, m);
            p >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        Matrix A(m, vector<long long>(m, 0));
        Matrix B(m, vector<long long>(m, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i > j) A[i][j] = 1;
                if (i < j) B[i][j] = 1;
            }
        }

        Matrix C = multiply(B, A, m);
        
        long long steps = n - 1;
        long long pairs = steps / 2;
        int rem = steps % 2;

        Matrix T = power(C, pairs, m);

        if (rem == 1) {
            T = multiply(A, T, m); 
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                ans = (ans + T[i][j]) % mod;
            }
        }
        return (ans * 2) % mod;
    }
};