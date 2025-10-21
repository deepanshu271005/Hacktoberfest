class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        

       sort(power.begin(),power.end());
      
       vector<long long >pow;
         pow.push_back(power[0]);
         for(int i=1;i<power.size();i++){
            if(pow[pow.size()-1]!=power[i]){
                pow.push_back(power[i]);
            }
         }
         //all the disticnt element are now pushed 
          vector<long long>freq;
          int num =power[0];
          int cnt=1;
          for(int i=1;i<power.size();i++){
                if(power[i]!=num){
                      freq.push_back(cnt);
                      cnt=1;
                      num=power[i];
                }
                else cnt++;
          }freq.push_back(cnt);



  // now the dp[i] will denote that if i am at this index then what can be the max sum that is possile 

  vector<long long>dp(pow.size(),-1);
   //set the base power that is the first index 0
   dp[0]=freq[0]*pow[0];
   for(int i=1;i<pow.size();i++){
    //as this is in sorted order so we wil only have to track back to find that if the last number is <
    //dp[i]=dp[last index whose power is less than of 2 than this ]
    int index=-1;
      for(int j=i-1;j>=0;j--){
         if(pow[i]-pow[j]>2){
          index=j;
          break;
         }
      }
      long long  ans1,ans2;
      if(index==-1){
        ans1=freq[i]*pow[i];
      }
      else ans1=dp[index]+freq[i]*pow[i];
      ans2=dp[i-1];
       dp[i]=max(ans1,ans2);

   }
   
//           for(auto i:pow){
//             cout<<i<<" ";

//           }
//           cout<<endl;
//           for(auto i:freq){
//             cout<<i<<" ";
//           }
// cout<<endl;
//    for(auto i:dp){
//     cout<<i<<" ";
//    }


    
          return dp[dp.size()-1];

    }
};
