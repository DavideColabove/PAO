#include <iostream>
#include <vector>

using namespace std;

template<class Functor>
vector<int> find_template(const vector<int>& v, Functor t) {
    vector<int> r;
    for(auto it = v.begin(); it != v.end(); ++it) 
        if (t(*it)) 
            r.push_back(*it);
    return r;
}

unsigned int find_1(const vector<int>& v, int k) {
    vector<int> w = find_template(v, [v,k] (int n) { return n > k; } );
    return w.size();
}

vector<int> find_2(const vector<int>& v) {
    return find_template(v, [v] (int n) { return n < v.size(); } );
}

vector<int> v1 = {3,6,4,6,2,5,-2,4,2};
vector<int> v2 = {-2,-6,4,4,2,5,0,4,2,3,2,0};

int main(){
    cout << find_1(v1, 2) << endl;
    cout << find_1(v2, 2) << endl;
    cout << find_2(v1).size() << endl;
    cout << find_2(v2).size() << endl;
}