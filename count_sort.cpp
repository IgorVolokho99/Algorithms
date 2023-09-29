#include <iostream>
#include <vector>

using namespace std;


void input_vector(vector<int> &A)
{
    int N = A.size();
    for (int i = 0; i < N; i++)
        cin >> A[i];
}

void print_vector(const vector<int> &A)
{
    int N = A.size();
    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;

}

void count_sort(vector<int> &A)
{
    // Find the max value;
    int mmax = -1;
    for (auto &x: A)
        if (x > mmax)
            mmax = x;

    // allocate memory to array of statistic and do it
    vector<int> statistic(mmax);
    for (auto &x: A)
        statistic[x] += 1;

    // use statistic to redid array
    int counter = 0;
    for (int i = 0; i <= mmax; i++)
        for (int j = 0; j < statistic[i]; j++)
    {
        A[counter] = i;
        counter++;
    }
}

int main()
{
    vector<int> A(5);

    input_vector(A);
    print_vector(A);
    count_sort(A);
    print_vector(A);


    return 0;
}
