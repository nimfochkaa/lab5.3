#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double j(const double x);

int main() {
    double kp, kk, z; 
    int n; 
    cout << "kp = "; cin >> kp;
    cout << "kk = "; cin >> kk;
    cout << "n = "; cin >> n;

    double dk = (kk - kp) / n;
    double k = kp;

    cout << fixed;
    cout << "------------------------------" << endl;
    cout << "|" << setw(10) << "k" << " |"
        << setw(15) << "Expression" << " |" << endl;
    cout << "------------------------------" << endl;

    while (k <= kk) 
    {
        z = j(k) + pow(j(k - 1), 2) + 2 * j(1);
        cout << "|" << setw(10) << setprecision(3) << k << " |"
            << setw(15) << setprecision(5) << z << " |" << endl;
        k += dk;
    }

    cout << "------------------------------" << endl;
    return 0;
}

double p(const double x) {
    if (abs(x) >= 1) {
        return (sin(x) + 1) / (pow(cos(x), 2) + exp(x));
    }
    else {
        double S = 0;
        int k = 0;
        double a = 1;
        S = a;
        do
        {
            k++;
            double R = (2 * x * x) / ((2 * k + 2) * (2 * k + 1));
            a *= R;
            S += a;
        }while (k <= 7);
        return S / cos(2 * x);
    }
}
