class Solution {
public:
    vector<string> addOperators(string num, int target) {
         vector<string> arr;
         if(num.length() == 0) return arr;
         if(num.length() == 1){
             if((int)(num[0] - '0') == target){
                 arr.push_back(num);
             }
             return arr;
         }
         
         int first = (int)(num[0] - '0');
         
         vector<string> conOp = addOperators(num.substr(1), target - first * 10);
         if(conOp.size() != 0){
             for(int i = 0; i < conOp.size() ; i ++){
                 conOp[i]= (num.substr(0,1)) + conOp[i];
             }
             arr.insert(arr.end(),conOp.begin(),conOp.end());
         }
         
         if(first != 0){
             vector<string> mulOp = addOperators(num.substr(1), target / first);
             if(mulOp.size() != 0){
                 for(int i = 0; i < mulOp.size() ; i ++){
                     mulOp[i] = num.substr(0,1) + "*" + mulOp[i];
                     
                 }
                  arr.insert(arr.end(),mulOp.begin(),mulOp.end());
             }
         }
         
         
         vector<string> addOp = addOperators(num.substr(1), target - first);
         if(addOp.size() != 0){
             for(int i = 0; i < addOp.size() ; i ++){
                 addOp[i] =  num.substr(0,1) + "+" + addOp[i];
                 
             }
             arr.insert(arr.end(),addOp.begin(),addOp.end());
         }
         
         return arr;
    }
};
