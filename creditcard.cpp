#include <iostream>
#include<math.h>
using namespace std;

void CheckCardluhn(long long cnum){
    int len=0;
    int everynum[16];
    int i;
    int cardsum1=0; 
    int cardsum2=0;
    int newnum;
    while(cnum>0){ 
    everynum[len] = cnum % 10;
    cnum = cnum / 10;
    len++;
    }

    for (i = len - 1; i > 0; i=i-2) {
    //cout << everynum[i] << endl;
      if (everynum[i] * 2 >= 10) {
        newnum = 0;
        newnum = (everynum[i] * 2 % 10) +(everynum[i] * 2 / 10 % 10);
        cardsum1 = cardsum1 + newnum;
        //cout << newnum << endl;
      }
      else{
        cardsum1 = cardsum1 + everynum[i] * 2;     
      }
    }

    for (i = len - 2; i >= 0; i = i - 2) {
    cardsum2 = cardsum2 + everynum[i];
    }

    if ((cardsum1 + cardsum2) % 10 == 0) {
       if ((len == 16 or len == 13) and (everynum[len - 1] == 4)) {
        cout << "VISA Card!";
        }
       
       if ((len == 16) and (((everynum[len - 1] == 5) and (everynum[len - 2] == 1)) or ((everynum[len - 1] == 5) and (everynum[len - 2] == 5)))){
        cout << "MasterCard!";
        }

       if ((len == 15) and (((everynum[len - 1] == 3) and (everynum[len - 2] == 4)) or ((everynum[len - 1] == 3) and (everynum[len - 2] == 7)))){
        cout << "American Express Card!";
        }
    }
    else{
    cout << "Not Right card number!!";
    }
} 

int main() {
  long long number;
  int cardlen;
  cout << "Number:";
  cin >> number;
  CheckCardluhn(number);
  return 0;  
}    
