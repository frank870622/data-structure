#include<iostream>
using namespace std;
int count=0;
int tower(int n,char left,char middle,char right){
    if(n == 1)  {
            cout << "Move disk " << n << " from " << left << " to " << right << "\n";
            ++count;
    }
    else {
        tower(n-1,left,right,middle);
        cout << "Move disk " << n << " from " << left << " to " << right << "\n";
        ++count;
        tower(n-1,middle,left,right);
    }
}

int main(){
    int n;
    cout << "Disk:";
    cin >> n;
    tower(n,'A','B','C');
    cout << "Total steps: " << count << "\n";
    return 0;
}
