class Solution {
public:
    int strStr(string haystack, string needle) {
     auto index=haystack.find(needle);
     if (index!=string::npos){
      return index;
     }
     return -1;
    }
};