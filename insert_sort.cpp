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

void insert_sort(vector<int> &A)
{
    int N = A.size();
    for (int pos = 1; pos < N; pos++)
    {
        int i = pos;
        while (i > 0 && A[i - 1] > A[i])
        {
            swap(A[i - 1], A[i]);
            i -= 1;
        }
        print_vector(A); // DEBUG_PRINT
    }


}


int main()
{
    vector<int> A(5);

    input_vector(A);

    print_vector(A);
    insert_sort(A);
    print_vector(A);


    return 0;
}
