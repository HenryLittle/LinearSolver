#include "matrix.h"
#include "vanillaSimplexSolver.h"
#include "dualSimplexSolver.h"
#include <iostream>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    Matrix c(1, n);
    cin >> c;

    Matrix mat(m, n + 2);
    cin >> mat;

    Matrix a = mat.getColumns(0, n);
    Matrix b = mat.getColumn(n);
    Matrix d = mat.getColumn(n + 1);

    Matrix e(1, n);
    cin >> e;

    VanillaSimplexSolver vanillaSimplexSolver(n, m, c, a, b, d, e);
    DualSimplexSolver dualSimplexSolver(n, m, c, a, b, d, e);

#ifdef DEBUG
    cout << "===============  Origin  ===============" << endl;
    vanillaSimplexSolver.print();

    cout << "=============  Relaxation  =============" << endl;
    vanillaSimplexSolver.relax();
    vanillaSimplexSolver.print();

    cout << "============  Normalization  ===========" << endl;
    vanillaSimplexSolver.normalize();
    vanillaSimplexSolver.print();
#else
    vanillaSimplexSolver.normalize();
#endif

    int k;
    double y;
    Matrix x(1, n + 2 * m);

    cout << endl;
    cout << ">>> Simplex Method" << endl;
    vanillaSimplexSolver.solve(k, y, x);
//    vanillaSimplexSolver.printSimplexTable();
    vanillaSimplexSolver.recover(x);
    cout << k << endl;
    if (k == 1) {
        cout << y << endl;
        for (int i = 0; i < n; i++) {
            cout << x[0][i] << " ";
        }
    }
    cout << endl;

//    cout << endl;
//    cout << ">>> Dual Simplex Method" << endl;
//    dualSimplexSolver.normalize();
//    dualSimplexSolver.solve(k, y, x);
//    vanillaSimplexSolver.recover(x);
//    cout << k << endl;
//    if (k == 1) {
//        cout << y << endl;
//        for (int i = 0; i < n; i++) {
//            cout << x[0][i] << " ";
//        }
//    }
//    cout << endl;

    return 0;
}