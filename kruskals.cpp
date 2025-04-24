#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

// default input and output files
#define INPUT_FILE "testcases/input.txt"
#define OUTPUT_FILE "testcases/output.txt"

using namespace std;

// disjoint sets and union
struct dsu {
    vector<int> p, r; // parent and rank

    // constructor
    dsu(int n) {
        p.resize(n);
        r.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
            r[i] = 1;
        }
    }

    // find: recursively finds parent of node
    int f(int i) {
        if (p[i] == i)
            return i;
        p[i] = f(p[i]);
        return p[i];
    }

    // union: if same parent do nothing
    // if x has higher rank, union y under x
    // if y has higher rank, union x under y
    // if they're the same rank, arbitrarily union y under x
    void u(int x, int y) {
        int sx = f(x), sy = f(y);
        if (sx != sy) {
            if (r[sx] > r[sy]) p[sy] = sx;
            else if (r[sy] > r[sx]) p[sx] = sy;
            else { p[sy] = sx; r[sx]++; }
        }
    }
};

// custom comparater to sort edges by weight
bool comp(vector<int>& a, vector<int>& b) {
    return a[2] <= b[2];
}

// solution implementation
int kruskals(int n, vector<vector<int>>& e) {
    // sort edges by weight
    sort(e.begin(), e.end(), comp);
    dsu k(n);

    int count = 0, cost = 0;
    for (int i = 0; i < e.size(); i++) {
        // check if src and dest share the same parent
        if (k.f(e[i][0]) != k.f(e[i][1])) {
            // union src and dest with the current edge
            k.u(e[i][0], e[i][1]);
            // add cost of edge
            cost += e[i][2];
            count++;
            // when current component contains all nodes, break
            if (count == n-1) break;
        }
    }
    return cost;
}

int main(int argc, char* argv[]) {
    // read inputs from file
    string filename = INPUT_FILE;
    if (argc > 1) filename = argv[1];
    ifstream infile(filename);
    int V, E;
    vector<vector<int>> edges;
    infile >> V >> E;
    for (int i = 0; i < E; i++) {
        vector<int> temp(3, 0);
        infile >> temp[0] >> temp[1] >> temp[2];
        edges.push_back(temp);
    }
    
    // run algorithm
    int result = kruskals(V, edges);

    // print output on stdout and in file
    cout << result << endl;
    ofstream outfile(OUTPUT_FILE);
    outfile << result << endl;
}
