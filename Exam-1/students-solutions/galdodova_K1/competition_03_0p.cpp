#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long N;
bool canStudentParticipate(vector<long long> results) {
   
}

long long canWeFindKStudents( vector<long long> results) {
    std::sort(results.begin(), results.end());
    long long student = results[0];
    long long res = 0;
    long long cnt = 0;
    for (size_t i = 0; i < N - 1; i++)
    {
        if (results[i] + results[i + 1] < student) {
            student=results[i];
            break;
        }
        else {
            cnt++;
        }

    }
    return cnt;
  }
int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);
   
    cin >> N;
    vector<long long> results(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> results[i];
    }
  
    cout << canWeFindKStudents(results);
    return 0;
}