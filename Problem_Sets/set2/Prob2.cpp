#include <iostream>
#include <vector>

using namespace std;

// return cost value basing on given begin and end
float get_cost(int begin, int end, vector<int> &demand, int K, float h, vector<float> &optimal_cost) {
    float rslt = K + optimal_cost[end];
    for (int i = end - begin - 1; i >= 0; --i) {
        rslt += h * i * demand[begin + i];
    }
    return rslt;
}


void
get_min_cost(int begin, int end, vector<int> &demand, int K, float h, vector<float> &optimal_cost, vector<int> &s) {
    float temp = INT_MAX;
    int index;
    for (int i = begin + 1; i <= end; ++i) {
        float cost = get_cost(begin, i, demand, K, h, optimal_cost);
        if (temp > cost) {
            temp = cost;
            index = i;
        }
    }
    optimal_cost[begin] = temp;
    s[begin] = index;
}

void order(vector<int> &demand, vector<int> &s, vector<int> &orders) {
    int curr = 0;
    int sum = 0;
    for (int i = 0; i < demand.size(); ++i) {
        if (i == s[curr]) {
            orders[curr] = sum;
            sum = 0;
            curr = s[curr];
        }
        sum += demand[i];
    }
    orders[curr] = sum;
}

int main(int argc, char const *argv[]) {
    int K = 1100;
    float h = 2.4;
    vector<int> demand = {108, 112, 123, 129, 147, 150, 156, 174, 189, 197, 202, 207, 228, 240, 242, 241, 266, 267, 270,
                          290, 303, 301, 329, 325, 345, 343, 367, 340, 337, 323, 325, 309, 305, 293, 273, 273, 252, 249,
                          243, 235, 226, 204, 204, 183, 175, 164, 162, 154, 145, 137, 112, 112};

//    simple test case
//    int K = 500;
//    float h = 2;
//    vector<int> demand = {90, 120, 80, 70};

    int size = demand.size();
    vector<float> optimal_cost(size + 1, 0);
    vector<int> s(size);
    vector<int> orders(size);

    for (int i = size - 1; i >= 0; --i) {
        get_min_cost(i, size, demand, K, h, optimal_cost, s);
    }

    for (float i : optimal_cost) {
        cout << i << ' ';
    }
    cout << '\n' << '\n';
    for (int i : s) {
        cout << i+1 << ' ';
    }
    cout << '\n' << '\n';

    order(demand, s, orders);
    for (int i : orders) {
        cout << i << ' ';
    }
    return 0;
}
