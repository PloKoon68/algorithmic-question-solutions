//https://leetcode.com/problems/product-of-the-last-k-numbers/description/?envType=daily-question&envId=2025-02-14

class ProductOfNumbers {
public:
    vector<long long> products;
    long long totalProduct;
    int zeroIndex;
    ProductOfNumbers() {
        products = {1};
        totalProduct = 1;
        zeroIndex = 0;
    }
    
    void add(int num) {
        if(num) totalProduct *= (long long)num;
        else {
            zeroIndex = products.size();
            totalProduct = 1;
        }
        products.push_back(totalProduct);
    }
    
    int getProduct(int k) {
        return (k < products.size() - zeroIndex)? (int)(totalProduct / products[products.size() - 1 - k]): 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
