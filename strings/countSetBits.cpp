#include <bits/stdc++.h>
using namespace std;
int count_setbits(int n)
{
    int count = 0;
    while (n > 0)
    {
        int last_bit = (n & 1);
        if (last_bit == 1)
        {
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int main()
{ // any number n can have at most log(n) bits.
    int n = 9;
    cout << count_setbits(n);
    return 0;
}