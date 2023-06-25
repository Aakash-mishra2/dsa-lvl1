#include <bits/stdc++.h>
using namespace std;

int countingTrees(int nodes)
{
    int ans = 0;
    if (nodes == 1 or nodes == 0)
        return 1;

    for (int i = 1; i <= nodes; i++)
    {
        ans += countingTrees(i - 1) * countingTrees(nodes - i);
    }
    return ans;
}

int main()
{
    // for each node i as root we have i-1 nodes on left, n-i nodes on right
    // how many BST are possible, I can choose
    // 1 BST from left possible trees, 1 BST from right possible trees.
    // xC1 = x , yC1 = y so x.y => f(i-1).f(n-i)

    int n = 4;
    // cin >> n;
    cout << countingTrees(n) << endl;
    return 0;
}