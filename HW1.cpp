#include <iostream>
using namespace std;
int stair(int number){
    if(number == 0) return 1;
    return number*stair(number-1);
}
int math(int n,int k){
    if(k==0){
        return 1;
    }
    else {
        int ans = stair(n)/stair(k)/stair(n-k);
        return ans;
    }
}
int main(){
    int n,k;
    cin >> n >> k;
    int ans = math(n,k);
    cout << ans;
    return 0;
}
