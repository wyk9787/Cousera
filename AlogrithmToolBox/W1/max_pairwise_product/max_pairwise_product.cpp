#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

long long MaxPairwiseProduct(const vector<int>& numbers) {
    long long result = 0;
    int n = numbers.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
//            cout << numbers[i] << " " << numbers[j] << " " << numbers[i] * numbers[j] << endl;
            if ((long long)numbers[i] * numbers[j] > result) {
                result = (long long)numbers[i] * numbers[j];
//                cout << numbers[i] << " " << numbers[j] << endl;
            }
        }
    }
  return result;
}

long long MaxPairwiseProductFast(const vector<int> &numbers){
    long long max1 = -1, max2 = -1;
    long long j;
    for(long long i = 0; i < numbers.size(); i++)
        if(max1 == -1 || numbers[i] > max1){
            max1 = numbers[i];
            j = i;
        }
    
    for(long long i = 0; i < numbers.size(); i++)
        if(i != j && (max2 == -1 || numbers[i] > max2))
            max2 = numbers[i];
    return max1 * max2;
    
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
//    while(true){
//
//        n = rand()%10+1;
//        for(int i = 0; i < n; i++){
//            long long j = rand() % 100000;
//            cout << j << " ";
//            numbers.push_back(j);
//        }
//        cout << endl;
//        long long result1 = MaxPairwiseProduct(numbers);
//        long long result2 = MaxPairwiseProductFast(numbers);
//        cout << result1 << " " << result2 << endl;
//        if(result1 == result2)
//            cout << "OK" << endl;
//        else{
//            cout << "Wrong!!!" << endl;
//            return 0;
//        }
//    }
    long long result = MaxPairwiseProductFast(numbers);
    cout << result << "\n";
    return 0;
}
