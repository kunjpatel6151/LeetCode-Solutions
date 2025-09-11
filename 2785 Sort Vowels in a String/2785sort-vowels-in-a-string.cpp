class Solution {
public:
    string sortVowels(string s) {
        vector<int> vowel(10,0);
        vector<int> pos;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                pos.push_back(i);
                if(c=='A') vowel[0]++;
                if(c=='E') vowel[1]++;
                if(c=='I') vowel[2]++;
                if(c=='O') vowel[3]++;
                if(c=='U') vowel[4]++;
                if(c=='a') vowel[5]++;
                if(c=='e') vowel[6]++;
                if(c=='i') vowel[7]++;
                if(c=='o') vowel[8]++;
                if(c=='u') vowel[9]++;
            }
        }
        int j=0;
        for(int i=0;i<10;i++){
            while(vowel[i]>0){
                char c;
                if(i==0) c='A';
                if(i==1) c='E';
                if(i==2) c='I';
                if(i==3) c='O';
                if(i==4) c='U';
                if(i==5) c='a';
                if(i==6) c='e';
                if(i==7) c='i';
                if(i==8) c='o';
                if(i==9) c='u';
                s[pos[j]]=c;
                j++;
                vowel[i]--;
            }
        }
        return s;
    }
};