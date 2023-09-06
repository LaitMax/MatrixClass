// destructors.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <time.h>
#include<stdlib.h>

using namespace std;
template <typename T>
class Matrix
{
private:
    T** M;
    int m;
    int n;
public:
    Matrix()
    {
        n = m = 0;
        M = nullptr;
    }
    Matrix(int _m, int _n)
    {
        m = _m;
        n = _n;
        M = (T**) new T * [m];

        for (int i = 0; i < m; i++)
            M[i] = (T*)new T[n];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = 0;
    }
    Matrix(const Matrix& _M)
    {
        m = _M.m;
        n = _M.n;

        M = (T**) new T * [m];

        for (int i = 0; i < m; i++)
            M[i] = (T*) new T[n];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = _M.M[i][j];
    }
    T GetMij(int i, double j)
    {
        if ((m > 0) && (n > 0))
            return M[i][j];
        else
            return 0;
    }
    void SetMij(int i, int j, T value)
    {
        if ((i < 0) || (i >= m))
            return;
        if ((j < 0) || (j >= n))
            return;
        M[i][j] = value;
    }
    void Print(const char* ObjName)
    {
        cout << "Object: " << ObjName << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << M[i][j] << "\t";
            cout << endl;
        }
        cout << "---------------------------------------" << endl << endl;
    }
    Matrix operator = (const Matrix& _M)
    {
        if (n > 0)
        {
            for (int i = 0; i < m; i++)
                delete[] M[i];
        }
        if (m > 0)
        {
            delete[] M;
        }
        m = _M.m;
        n = _M.n;

        M = (T**) new T * [m];
        for (int i = 0; i < m; i++)
            M[i] = (T*) new T[n];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = _M.M[i][j];
        return *this;
    }
    ~Matrix()
    {
        if (n > 0)
        {
            for (int i = 0; i < m; i++)
                delete[] M[i];
        }

        if (m > 0)
        {
            delete[] M;
        }
    }
};

int main()
{
    srand(time(NULL) / 2);
    int x, i, j;
    cin >> x;
    cout << endl;
    Matrix<int> M(x, x);
    M.Print("M");
    for (i = 0; i < x; i++)
        for (j = 0; j < x; j++)
            M.SetMij(i, j, rand());

    M.Print("M");

    Matrix<int> M2 = M;
    M2.Print("M2");

    Matrix<int> M3;
    M3 = M;
    M3.Print("M3");

    Matrix<int> M4;
    M4 = M3 = M2 = M;
    M4.Print("M4");

    //Matrix<int> M5;
    //M5 = M;
    //M5.transpose(x, x);
    //M5.Print("M5");

    cout << "Hello World!\n";
}