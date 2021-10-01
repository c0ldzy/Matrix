//OLE4KA
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <map>
#include <iomanip>

using namespace std;

#define rep(i, a, b) for(int i = a; i < b; i++)

template<typename T>
class Matrix
{
    int n;
    int m;
    vector<vector<T> > data;

public:
    Matrix(vector<vector<T> >);
    Matrix(int n_, int m_);

    int nsize() const {return n;};
    int msize() const {return m;};
    pair<int, int> size() const {return {n, m};};

    const Matrix operator+(const Matrix&) const;
    const Matrix operator*(T) const;
    const Matrix operator*(const Matrix&) const;
    const Matrix operator^(int) const;

    Matrix trans() const
    {
        vector<vector<T> > res;
        res.resize(m, vector<T> (n));
        rep(i, 0, n) rep(j, 0, m) res[j][i] = data[i][j];
        return Matrix(res);
    }

    Matrix pow(int i) const
    {
        if(i == 1) return Matrix(data);
        if(i % 2 == 0) return (Matrix(data) * Matrix(data)).pow(i / 2);
        if(i % 2 == 1) return Matrix(data) * Matrix(data).pow(i - 1);
    }

    vector<T>& operator[](int i) {return data[i];};
    const vector<T>& operator[](int i) const {return data[i];};

    template<typename Type> friend istream& operator>>(istream&, Matrix<Type>&);
    template<typename Type> friend ostream& operator<<(ostream&, const Matrix<Type>&);
};

template<typename T>
Matrix<T>::Matrix(vector<vector<T> > matr)
{
    data = matr;
    n = matr.size();
    m = matr[0].size();
}

template<typename T>
Matrix<T>::Matrix(int n_, int m_)
{
    n = n_;
    m = m_;
    rep(i, 0, n) data[i].assign(m, 0);
}

template<typename T>
const Matrix<T> Matrix<T>::operator+(const Matrix& a) const
{
    vector<vector<T> > res(n, vector<T> (m));
    if (a.n == n && a.m == m)
        rep(i, 0, n) rep(j, 0, m)
            res[i][j] = data[i][j] + a.data[i][j];
    return Matrix(res);
}

template<typename T>
const Matrix<T> Matrix<T>::operator*(T k) const
{
    vector<vector<T> > res(n, vector<T> (m));
    rep(i, 0, n) rep(j, 0, m)
        res[i][j] = data[i][j] * k;
    return Matrix(res);
}

template<typename T>
const Matrix<T> Matrix<T>::operator*(const Matrix& a) const
{
    vector<vector<T> > res(n, vector<T> (a.m));
    if(m == a.n)
    {
        rep(i, 0, n)
            rep(j, 0, a.m)
            {
            //cout << i << " " << j << endl;
                res[i][j] = 0;

                rep(k, 0, m)
                    res[i][j] += data[i][k] * a[k][j];
            }

    }
    return Matrix(res);
}

template<typename T>
const Matrix<T> Matrix<T>::operator^(int x) const
{
    vector<vector<T> > res(n, vector<T> (m));
    if(n == m)
    {

    }
    return Matrix(res);
}

template<typename T>
ostream& operator<<(ostream& out, const Matrix<T>& a)
{
    rep(i, 0, a.n) {rep(j, 0, a.m)
        out << a[i][j] << " "; cout << endl;}
    return out;
}

template<typename T>
istream &operator>>(istream& in, Matrix<T>& a)
{
    rep(i, 0, a.n) rep(j, 0, a.m)
        in >> a[i][j];
    return in;
}

int main()
{
    cout << "." << endl << "." << endl << "." << endl;
    cout << "Hey, follow @kazutora.empire on Instagram for free usage of this thing" << endl;
    cout << "Press Enter when u r done" << endl;
    cout << "." << endl << "." << endl << "." << endl;
    string s;
    getline(cin, s);

    cout << endl << endl << endl << endl << endl <<
    endl << endl << endl << endl << endl << endl <<
    "Aight, hope u have followed, we can start" << endl << endl;

    cout << "What do u want to do?" << endl << endl;
    cout << "U can:" << endl << endl;
    cout << "Add two matrixes (type +)" << endl;
    cout << "Multiply two matrixes (type *)" << endl;
    cout << "Multiply a matrix buy a number (type mul)" << endl;
    cout << "Transpose a matrix (type trans)" << endl;
    cout << "And even raise it to a power (type power)" << endl << endl << endl;
    cout << "(Now u r in int mode, if u want to change it, change it)" << endl << endl;

    s = ".";
    int cnt = 0;
    while(s != "+" && s != "*" && s != "mul" && s != "trans" && s != "power")
    {
        cin >> s;
        cnt++;
        if(s != "+" && s != "*" && s != "mul" && s != "trans" && s != "power")
        {
            if(cnt == 10) {cout << endl << "U r kinda silly, I quit" << endl; return 0;}
            cout << endl << "Oh, please, type smth from the above" << endl << endl;
        }
        else break;
    }

    if(s == "+")
    {
        cout << endl << endl;
        cout << "Enter the size of your matrixes" << endl << endl;

        int n, m;
        cin >> n >> m;
        cout << endl << "Now enter the elements of the first matrix" << endl << endl;

        vector<vector<int> > a(n, vector<int> (m)), b(n, vector<int> (m));
        rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];

        cout << endl << "Now enter the elements of second matrix" << endl << endl;

        rep(i, 0, n) rep(j, 0, m) cin >> b[i][j];

        Matrix<int> A = Matrix<int>(a), B = Matrix<int>(b);
        cout << endl << "Elements of ur first matrix:" << endl << endl;
        cout << A << endl << endl;
        cout << endl << "Elements of ur second matrix:" << endl << endl;
        cout << B << endl << endl;
        cout << "The result:" << endl << endl;
        Matrix<int> C = A + B;
        cout << C << endl;
    }
    if(s == "*")
    {
        cout << endl << endl;
        cout << "Enter the size of your first matrix" << endl << endl;

        int n, m;
        cin >> n >> m;
        cout << endl << "Now enter the elements of the first matrix" << endl << endl;

        vector<vector<int> > a(n, vector<int> (m));
        rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];

        cout << endl << "Now enter the second size of your second matrix" << endl << endl;

        n = m;
        cin >> m;

        cout << endl << "Now enter the elements of second matrix" << endl << endl;

        vector<vector<int> > b(n, vector<int> (m));

        rep(i, 0, n) rep(j, 0, m) cin >> b[i][j];

        Matrix<int> A = Matrix<int>(a), B = Matrix<int>(b);
        cout << endl << "Elements of ur first matrix:" << endl << endl;
        cout << A << endl << endl;
        cout << endl << "Elements of ur second matrix:" << endl << endl;
        cout << B << endl << endl;
        cout << "The result:" << endl << endl;
        Matrix<int> C = A * B;
        cout << C << endl;
    }
    if(s == "mul")
    {
        cout << endl << endl;
        cout << "Enter the size of your matrix" << endl << endl;

        int n, m;
        cin >> n >> m;
        cout << endl << "Now enter the elements of ur matrix" << endl << endl;

        vector<vector<int> > a(n, vector<int> (m));
        rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];

        int x;
        cout << "Enter the number" << endl << endl;
        cin >> x;

        Matrix<int> A = Matrix<int>(a);
        cout << endl << "Elements of ur matrix:" << endl << endl;
        cout << A << endl << endl;
        cout << "The result:" << endl << endl;
        Matrix<int> C = A * x;
        //rep(i, 0, C.nsize()) {rep(j, 0, C.msize()) cout << C[i][j] << " "; cout << endl;}
        cout << C << endl;
    }
    if(s == "trans")
    {
        cout << endl << endl;
        cout << "Enter the size of your matrix" << endl << endl;

        int n, m;
        cin >> n >> m;
        cout << endl << "Now enter the elements of ur matrix" << endl << endl;

        vector<vector<int> > a(n, vector<int> (m));
        rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];

        Matrix<int> A = Matrix<int>(a);
        cout << endl << "Elements of ur matrix:" << endl << endl;
        cout << A << endl << endl;
        cout << "The result:" << endl << endl;
        Matrix<int> C = A.trans();
        //rep(i, 0, C.nsize()) {rep(j, 0, C.msize()) cout << C[i][j] << " "; cout << endl;}
        cout << C << endl;
    }
    if(s == "power")
    {
        cout << endl << endl;
        cout << "Enter the size of your matrix (n = m, so only one number)" << endl << endl;

        int n, m;
        cin >> n;
        m = n;
        cout << endl << "Now enter the elements of ur matrix" << endl << endl;

        vector<vector<int> > a(n, vector<int> (m));
        rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];

        int x;
        cout << "Enter the power (if u enter a number < 1, I will use 17 lol)" << endl << endl;
        cin >> x;
        if(x < 1) x = 17;

        Matrix<int> A = Matrix<int>(a);
        cout << endl << "Elements of ur matrix:" << endl << endl;
        cout << A << endl << endl;
        cout << "The result:" << endl << endl;
        Matrix<int> C = A.pow(x);
        //rep(i, 0, C.nsize()) {rep(j, 0, C.msize()) cout << C[i][j] << " "; cout << endl;}
        cout << C << endl;
    }

    cout << endl << "I did a good job" << endl << endl;
    cout << "If u r not satisfied yet run me again" << endl;
    cout << endl;
    cout << "See ya" << endl << endl << endl;

    return 0;
}
