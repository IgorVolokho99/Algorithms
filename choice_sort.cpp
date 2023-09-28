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

void choice_sort(vector<int> &A)
{
    int N = A.size();
    for (int pos = 0; pos < N - 1; pos++)
        for (int i = pos + 1; i < N; i++)
            if (A[i] < A[pos])
                swap(A[i], A[pos]);

}


int main()
{
    vector<int> A(5);

    input_vector(A);

    print_vector(A);
    choice_sort(A);
    print_vector(A);


    return 0;
}
