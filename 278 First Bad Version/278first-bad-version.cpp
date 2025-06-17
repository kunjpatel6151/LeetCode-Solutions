// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int num=n;
        while(isBadVersion(num) && num>0){
            num--;
        }
        return num+1;
    }
};