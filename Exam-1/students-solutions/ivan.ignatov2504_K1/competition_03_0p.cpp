#include <bits/stdc++.h>

int n;

int arr[200100];

int main() {
    std::ios_base::sync_with_stdio(false);

    std::cin.tie(nullptr);
    
    std::cout.tie(nullptr);
    
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    
    std::sort(arr, arr + n);

    // int first = 0;
    // int second = 1;
    // int third = 2;
    // int curr = 2;
    // int max = 2;

    // while(third <= n && second <= n - 1 && first <= n - 2) {
    //     if(third == n) {
    //         ++second;
    //         --third;
    //         --curr;
    //         if(second == third) {
    //             ++first;
    //             --second;
    //         }
    //     }
    //     if(arr[first] + arr[second] > arr[third]) {
    //         ++curr;
    //         ++third;
    //     } else {
    //         ++second;
    //         --curr;
    //         if(second == n - 1) {
    //             ++first;
    //             --second;
    //         }
    //     }

    //     max = std::max(max, curr);
    // }

    int curr = 2;
    int max = 2;

    for(int i = 0; i < n - 2; ++i) {
        for(int j = i + 1; j < n - 1; ++j) {
            curr = 2;
            for(int k = j + 1; k < n; ++k) {
                if(arr[i] + arr[j] > arr[k]) {
                    ++curr;
                } else {
                    break;
                }
            }
        }
        max = std::max(max, curr);
    }

    std::cout << max << std::endl;
}