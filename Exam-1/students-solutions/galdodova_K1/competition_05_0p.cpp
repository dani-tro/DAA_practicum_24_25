#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long N;
bool canWeFindKStudents(long long student, vector<long long> results) {

    for (size_t i = 0; i < N - 1; i++)
    {
        if (results[i] + results[i + 1] < student) {
           return false;
        }
    
    }
    return true;
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
    std::sort(results.rbegin(), results.rend());
    long long ans = 0;
    for (size_t i = 1; i < N-1; i++)
    {
        if (canWeFindKStudents(results[i], results)) ans++;
    }
    
  
    cout << ans;
    return 0;
}