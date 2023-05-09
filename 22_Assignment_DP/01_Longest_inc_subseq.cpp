#include <iostream>
using namespace std;

int longest_inc_subseq(int arr[], int n, int* max)
{
	// Base case
	if (n == 1) return 1;

	// 'max_ending_here' is length of LIS ending with arr[n-1]
	int res, max_ending_here = 1;

	for (int i = 1; i < n; i++) {
		res = longest_inc_subseq(arr, i, max);
		if (arr[i - 1] < arr[n - 1] && res + 1 > max_ending_here){
			max_ending_here = res + 1;
        }
	}

	// Compare max_ending_here with the overall max. And update the overall max if needed
	if (*max < max_ending_here) *max = max_ending_here;

	// Return length of LIS ending with arr[n-1]
	return max_ending_here;
}

int lis(int arr[], int n)
{
	int max = 1;
	longest_inc_subseq(arr, n, &max);
	return max;
}

// DP
int lis_DP(int *input, int n){
    int *output = new int[n];
    output[0] = 1;
    for (int i = 1; i < n; i++){
        output[i] = 1;
        for (int j = i-1; j >= 0; j--){
            if (input[j] >= input[i]){
                continue;
            }
            int possibleAns = output[j] + 1;
            if (possibleAns > output[i]){
                output[i] = possibleAns;
            }
        }
    }
    int best = 0;
    for (int i = 0; i < n; i++) {
        if (best < output[i]){
            best = output[i];
        }
    }
    delete [] output;
    return best;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << lis(a, n) << endl;
    cout << lis_DP(a, n) << endl;
    return 0;
}

/*
input
6
5 4 11 1 16 8

output
3

input
3
1 2 2

output
2
*/