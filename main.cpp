#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void aThomasAlgorithm(const vector<double> &aboveDiagonal, const vector<double> &diagonal, const vector<double> &underDiagonal, vector<double> &eta);

void bThomasAlgorithm(const vector<double> &aboveDiagonal, const vector<double> &diagonal, const vector<double> &underDiagonal, const vector<double> &eta, const vector<double> &b, vector<double> &result, vector<double> &bTransformed);

void showVector(const vector<double> &v, const string &label);

int main()
{
    vector<double> aboveDiagonal{1.0 / 2.0, 1.0 / 4.0, 1.0 / 6.0, 1.0 / 8.0, 1.0 / 10.0};
    vector<double> diagonal{10.0, 20.0, 30.0, 30.0, 20.0, 10.0};
    vector<double> underDiagonal{1.0 / 3.0, 1.0 / 5.0, 1.0 / 7.0, 1.0 / 9.0, 1.0 / 11.0};
    vector<double> b{31.0, 165.0 / 4.0, 917.0 / 30.0, 851.0 / 28.0, 3637.0 / 90.0, 332.0 / 11.0};
    vector<double> eta{diagonal.at(0)};
    vector<double> bTransformed{b.at(0)};
    vector<double> result{0.0, 0.0, 0.0, 0.0, 0.0};

    aThomasAlgorithm(aboveDiagonal, diagonal, underDiagonal, eta);
    bThomasAlgorithm(aboveDiagonal, diagonal, underDiagonal, eta, b, result, bTransformed);

    showVector(aboveDiagonal, "Wektor aboveDiagonal:");
    showVector(diagonal, "Wektor diagonal");
    showVector(underDiagonal, "Wektor underDiagonal:");
    showVector(b, "Wektor b");
    showVector(eta, "Wektor eta");//zmiana nazwy
    showVector(bTransformed, "Wektor bTransformed");//zmiana nazwy
    showVector(result, "Wektor result");//zmiana nazwy
}

void aThomasAlgorithm(const vector<double> &aboveDiagonal, const vector<double> &diagonal, const vector<double> &underDiagonal, vector<double> &eta)
{
    for (int i = 1; i < diagonal.size(); ++i)
        eta.push_back(diagonal.at(i) - underDiagonal.at(i - 1) * aboveDiagonal.at(i - 1) / eta.at(i - 1));
}

void bThomasAlgorithm(const vector<double> &aboveDiagonal, const vector<double> &diagonal, const vector<double> &underDiagonal, const vector<double> &eta, const vector<double> &b, vector<double> &result, vector<double> &bTransformed)
{
    for (int i = 1; i < diagonal.size(); ++i)
        bTransformed.push_back(b.at(i) - underDiagonal.at(i - 1) * bTransformed.at(i - 1) / eta.at(i - 1));

    result.push_back(bTransformed.back() / eta.back());

    for (int i = diagonal.size() - 2; i >= 0; --i)
        result.at(i) = (bTransformed.at(i) - aboveDiagonal.at(i) * result.at(i + 1)) / eta.at(i);
}

void showVector(const vector<double> &v, const string &label)
{
    cout << label << endl;
    for (auto element: v)
        cout << "|" << setprecision(5) << element << "|" << endl;
    cout << endl;
}