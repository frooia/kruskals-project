#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

#define INPUT_FILE "input.txt" // CHANGE THIS FOR CUSTOM INPUTS
#define OUTPUT_FILE "output.txt"

using namespace std;

struct dsu {
    vector<int> p, r;
    
    dsu(int n) {
        p.resize(n);
        r.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
            r[i] = i;
        }
    }

    int f(int i) {
        if (p[i] == i)
            return i;
        p[i] = f(p[i]);
        return p[i];
    }

    void u(int x, int y) {
        int sx = f(x), sy = f(y);
        if (sx != sy) {
            if (r[sx] > r[sy]) p[sy] = sx;
            else if (r[sy] > r[sx]) p[sx] = sy;
            else { p[sy] = sx; r[sx]++; }
        }
    }
};

bool comp(vector<int>& a, vector<int>& b) {
    return a[2] <= b[2];
}

int kruskals(int n, vector<vector<int>>& e) {
    sort(e.begin(), e.end(), comp);
    dsu k(n);
    int count = 0, cost = 0;
    for (int i = 0; i < e.size(); i++) {
        if (k.f(e[i][0]) != k.f(e[i][1])) {
            k.u(e[i][0], e[i][1]);
            cost += e[i][2];
            count++;
            cout << "edge (" << e[i][0] << ", " << e[i][1] << ", " << e[i][2] << ") added" << endl;
            if (count == n-1) break;
        }
    }
    return cost;
}

int main() {
    ifstream infile(INPUT_FILE);
    int V, E;
    vector<vector<int>> edges;
    infile >> V >> E;
    for (int i = 0; i < E; i++) {
        vector<int> temp(3, 0);
        infile >> temp[0] >> temp[1] >> temp[2];
        edges.push_back(temp);
    }
    
    // debug
    cout << "input read" << endl;

    int result = kruskals(V, edges);

    cout << result << endl;

    ofstream outfile(OUTPUT_FILE);
    outfile << result << endl;
}
