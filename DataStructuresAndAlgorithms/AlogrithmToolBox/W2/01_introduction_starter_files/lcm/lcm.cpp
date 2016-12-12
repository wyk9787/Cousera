#include <iostream>



long long gcd(long long a, long long b){
    if(a < b){
        long long temp = b;
        b = a;
        a = temp;
    }
    if(b == 0)
        return a;
    else{
        long long temp2 = b;
        b = a % b;
        a = temp2;
        return gcd(a, b);
    }
}



long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
