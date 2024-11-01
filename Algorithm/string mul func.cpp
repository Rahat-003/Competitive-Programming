#include <iostream>
#include <vector>
using namespace std;

vector<int> result(4, 0);

void multiply(string num1, string num2){
    int n1 = num1.size();
    int n2 = num2.size();
  /*  if (n1 == 0 || n2 == 0)
    return "0";
*/
    int i_n1 = 0;
    int i_n2 = 0;
    for (int i=n1-1; i>=0; i--){
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;
        for (int j=n2-1; j>=0; j--)
        {
            int n2 = num2[j] - '0';

            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            carry = sum/10;

            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }
}
int main(){
string a,b;
cin>>a>>b;
multiply(a,b);
//cout<<result.size();

return 0;
}
