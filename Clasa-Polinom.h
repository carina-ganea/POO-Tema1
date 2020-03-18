//
// Created by carin on 3/8/2020.
//

#ifndef POO_CLASA_POLINOM_H
#define POO_CLASA_POLINOM_H
#include <iostream>
#include <algorithm>
#include <string>
const int N = 1000;
using namespace std;

///citirea polinomului se face citind gradul de pe prima linie, apoi coeficentii sai
///de la cel mai nesemnificativ la cel mai semnificativ

namespace clsPolinom
{
class Polinom {
    int grad;
    double coef[N];

    friend Polinom operator+(Polinom A, Polinom B);

    friend Polinom operator+(Polinom A, double B);

    friend Polinom operator+(double B, Polinom A);

    friend Polinom operator+(Polinom A);

    friend Polinom operator-(Polinom A, Polinom B);

    friend Polinom operator-(Polinom A, double B);

    friend Polinom operator-(double B, Polinom A);

    friend Polinom operator-(Polinom A);

    friend Polinom operator*(Polinom A, Polinom B);

    friend Polinom operator*(double A, Polinom B);

    friend Polinom operator*(Polinom A, double B);

    friend Polinom operator/(Polinom A, Polinom B);

    friend Polinom operator/(double A, Polinom B);

    friend Polinom operator/(Polinom A, double B);

    friend Polinom operator%(Polinom A, Polinom B);

    friend Polinom operator%(Polinom A, double B);

    friend Polinom operator%(double A, Polinom B);

    friend Polinom operator^(Polinom A, double B);

    friend void operator+=(Polinom &A, Polinom B);

    friend void operator+=(Polinom &A, double B);

    friend void operator-=(Polinom &A, Polinom B);

    friend void operator-=(Polinom &A, double B);

    friend void operator*=(Polinom &A, Polinom B);

    friend void operator*=(Polinom &A, double B);

    friend void operator/=(Polinom &A, Polinom B);

    friend void operator/=(Polinom &A, double B);

    friend void operator%=(Polinom &A, Polinom B);

    friend void operator%=(Polinom &A, double B);

    friend bool operator==(Polinom &A, Polinom &B);

    friend bool operator==(double &A, Polinom &B);

    friend bool operator==(Polinom &A, double &B);

    friend bool operator!=(Polinom &A, Polinom &B);

    friend bool operator!=(double &A, Polinom &B);

    friend bool operator!=(Polinom &A, double &B);

    friend bool operator!(Polinom &A);

    friend int grad(Polinom &A);

public:
    Polinom() {
        grad = -N;
        for (int i = 0; i < N; i++)
            coef[i] = 0;
    }

    Polinom(int g, double *c) {
        grad = g;
        for (int i = 0; i <= g; i++)
            coef[i] = c[i];
    }

    Polinom(const Polinom &B);

    Polinom(double c);

    friend istream &operator>>(istream &in, Polinom &B);

    friend ostream &operator<<(ostream &out, const Polinom &B);

    Polinom &operator=(const Polinom &B);

    Polinom &operator=(const double &r);

    double &operator[](int i);

    double operator()(double x);
};

Polinom::Polinom(double c) {
    if (c == 0) {
        grad = -N;
        for (int i = 0; i < N; i++)
            coef[i] = 0;
    } else {
        grad = 0;
        coef[0] = c;
    }
}

Polinom::Polinom(const Polinom &B) {
    grad = B.grad;
    for (int i = 0; i <= grad; i++)
        coef[i] = B.coef[i];
}

ostream &operator<<(ostream &out, const Polinom &B) {
    bool ok = false;
    if (B.grad == -N)
        return out << 0;
    if (B.coef[0] != 0) {
        out << B.coef[0];
        ok = true;
    }
    for (int i = 1; i <= B.grad; i++) {
        if (B.coef[i] != 0 && B.coef[i] != 1) {
            if (!ok) {
                out << B.coef[i] << " * x";
                ok = true;
            } else
                out << " + " << B.coef[i] << " * x";
        }
        if (B.coef[i] == 1) {
            if (!ok) {
                out << "x";
                ok = true;
            } else
                out << " + " << "x";
        }
        if( i != 1)
            out << "^" << i;
    }
    out << endl;
    return out;
}

istream &operator>>(istream &in, Polinom &B) {
    cin >> B.grad;
    for( int i = 0; i <= B.grad; i++ )
        cin >> B.coef[i];
    return in;
}

Polinom &Polinom::operator=(const Polinom &B) {
    grad = B.grad;
    for (int i = 0; i <= B.grad; i++)
        coef[i] = B.coef[i];
    return *this;
}

Polinom &Polinom::operator=(const double &r) {
    grad = 0;
    coef[0] = r;
    for (int i = 1; i < N; i++)
        coef[i] = 0;
    return *this;
}

double &Polinom::operator[](int i) {
    if (i <= grad)
        return coef[i];
    else {
        cout << "ELement inexistent";
        exit(-1);
    }
}

Polinom operator+(Polinom A) {
    return A;
}

Polinom operator+(Polinom A, Polinom B) {
    Polinom C;
    C.grad = max(A.grad, B.grad);
    for (int i = C.grad; i >= 0; i--) {
        C.coef[i] = A.coef[i] + B.coef[i];
        if (C.coef[i] == 0 && i == C.grad)
            C.grad--;
    }
    if (C.grad == -1)
        C.grad = -N;
    return C;
}

Polinom operator+(Polinom A, double B) {
    Polinom C(B);
    return A + C;
}

Polinom operator+(double B, Polinom A) {
    Polinom C(B);
    return C + A;
}

Polinom operator-(Polinom A) {
    Polinom C;
    C.grad = A.grad;
    for (int i = 0; i <= A.grad; i++)
        C.coef[i] = -A.coef[i];
    return C;
}

Polinom operator-(Polinom A, Polinom B) {
    Polinom C;
    C.grad = max(A.grad, B.grad);
    for (int i = C.grad; i >= 0; i--) {
        C.coef[i] = A.coef[i] - B.coef[i];
        if (C.coef[i] == 0 && i == C.grad)
            C.grad--;
    }
    if (C.grad == -1)
        C = Polinom(0);
    return C;
}

Polinom operator-(Polinom A, double B) {
    Polinom C(B);
    return A - C;
}

Polinom operator-(double B, Polinom A) {
    Polinom C(B);
    return C - A;
}

Polinom operator*(Polinom A, Polinom B) {
    Polinom C;
    C.grad = A.grad + B.grad;
    if (C.grad < 0)
        C = Polinom(0);
    for (int i = C.grad; i >= 0; i--)
        for (int j = 0; j <= min(i, A.grad); j++)
            if (B.grad >= i - j)
                C.coef[i] += (A.coef[j] * B.coef[i - j]);
    return C;
}

Polinom operator*(Polinom A, double B) {
    Polinom C(B);
    return A * C;
}

Polinom operator*(double A, Polinom B) {
    Polinom C(A);
    return C * B;
}

Polinom operator/(Polinom A, Polinom B) {
    if (B.grad < 0) {
        cout << "Nu se imparte la polinom nul, coaie";
        exit(-1);
    }
    if (A.grad < B.grad)
        return 0;
    else {
        Polinom C;
        C.grad = A.grad - B.grad;
        for (int i = C.grad; i >= 0; i--) {
            C.coef[i] = A.coef[A.grad] / B.coef[B.grad];
            Polinom aux;
            aux.grad = i;
            aux[i] = C[i];
            aux = aux * B;
            A = A - aux;
        }
        return C;
    }
}

Polinom operator/(Polinom A, double B) {
    if (B == 0) {
        cout << "Nu se imparte la 0, coaie";
        exit(-1);
    } else {
        Polinom C(B);
        return A / C;
    }
}

Polinom operator/(double A, Polinom B) {
    Polinom C(A);
    return C / B;
}

Polinom operator%(Polinom A, Polinom B) {
    if (A.grad < B.grad)
        return A;
    else {
        Polinom C;
        C.grad = A.grad - B.grad;
        for (int i = C.grad; i >= 0; i--) {
            C.coef[i] = A.coef[A.grad] / B.coef[B.grad];
            Polinom aux;
            aux.grad = i;
            aux[i] = C.coef[i];
            aux = aux * B;
            A = A - aux;
        }
        return A;
    }
}

Polinom operator%(Polinom A, double B) {
    if (B == 0) {
        cout << "Nu se imparte la 0, coaie";
        exit(-1);
    } else {
        Polinom C(B);
        return A % C;
    }
}

Polinom operator%(double A, Polinom B) {
    Polinom C(A);
    return C % B;
}

Polinom operator^(Polinom A, double B) {
    if (B < 0) {
        cout << "Nu se ridica la putere negativa, coaie";
        exit(-1);
    }
    if (B == 0)
        return 1;
    if (B == 1)
        return A;
    Polinom C(A);
    B--;
    while (B != 0) {
        C = C * A;
        B--;
    }
    return C;
}

void operator+=(Polinom &A, Polinom B) {
    A = A + B;
}

void operator+=(Polinom &A, double B) {
    A = A + B;
}

void operator-=(Polinom &A, Polinom B) {
    A = A - B;
}

void operator-=(Polinom &A, double B) {
    A = A - B;
}

void operator*=(Polinom &A, Polinom B) {
    A = A * B;
}

void operator*=(Polinom &A, double B) {
    A = A * B;
}

void operator/=(Polinom &A, Polinom B) {
    A = A / B;
}

void operator/=(Polinom &A, double B) {
    A = A / B;
}

void operator%=(Polinom &A, Polinom B) {
    A = A % B;
}

void operator%=(Polinom &A, double B) {
    A = A % B;
}

bool operator==(Polinom &A, Polinom &B) {
    bool ok = true;
    if (A.grad != B.grad)
        return false;
    for (int i = 0; i <= A.grad; i++)
        if (A[i] != B[i])
            ok = false;
    return ok;
}

bool operator==(double &A, Polinom &B) {
    Polinom C(A);
    return C == B;
}

bool operator==(Polinom &A, double &B) {
    Polinom C(B);
    return A == C;
}

bool operator!=(Polinom &A, Polinom &B) {
    if (A.grad != B.grad)
        return true;
    int c = 0;
    for (int i = 0; i <= A.grad; i++)
        if (A[i] == B[i])
            c++;
    return c != A.grad;
}

bool operator!=(double &A, Polinom &B) {
    Polinom C(A);
    return C != B;
}

bool operator!=(Polinom &A, double &B) {
    Polinom C(B);
    return A != C;
}

bool operator!(Polinom &A) {
    Polinom C;
    return !(A == C);
}

double Polinom::operator()(double x) {
    double val = 0;
    for (int i = 0; i <= grad; i++) {
        double c = 1;
        for (int j = 0; j < i; j++)
            c *= x;
        val += coef[i] * c;
    }
    return val;
}

int grad(Polinom &A) {
    return A.grad;
}

}

#endif //POO_CLASA_POLINOM_H
