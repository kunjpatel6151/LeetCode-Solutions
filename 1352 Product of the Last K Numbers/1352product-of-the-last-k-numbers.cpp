class ProductOfNumbers {
public:
    vector<long long> arr;
    vector<int> zeros;
    int pro=1;
    int index=0;
    ProductOfNumbers() {
        arr.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            zeros.push_back(index);
            pro=1;
            arr.push_back(1);
        }
        else{
            pro*=num;
            arr.push_back(pro);
        }
        index++;
    }

    bool haszero(int l,int r){
        for(int i=0;i<zeros.size();i++){
            int x=zeros[i];
            if(x>=l && x<=r){
                return true;
            }
        }
        return false;
    }
    
    int getProduct(int k) {
        int r=arr.size()-1;
        int l=r-k;
        if(haszero(l,r)){
            return 0;
        }
        else{
            return arr[r]/arr[l];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */