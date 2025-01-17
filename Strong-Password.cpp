#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */


int countBits(uint8_t n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int minimumNumber0(int n, string password) {
    uint8_t flags = 0;
    
    for (char c : password) {
        if (isdigit(c)) flags |= 1;
        else if (isupper(c)) flags |= 2;
        else if (islower(c)) flags |= 4;
        else flags |= 8;
        
        if (flags == 15) break;
    }
    
    return std::max(6 - n, 4 - countBits(flags));
}


int minimumNumber1(int n, string password) {
    uint8_t flags = 0;
    
    for (char c : password) {
        if (isdigit(c)) flags |= 1;
        else if (isupper(c)) flags |= 2;
        else if (islower(c)) flags |= 4;
        else flags |= 8;
        
        if (flags == 15) break;
    }
    
    return std::max(6 - n, 4 - __builtin_popcount(flags));
}


int minimumNumber2(int n, string password) {
    int a = 0, b = 0, c = 0, d = 0;
    
    for (char check : password) {
        if (isdigit(check)) a = 1;
        else if (isupper(check)) b = 1;
        else if (islower(check)) c = 1;
        else d = 1;
        
        if (a && b && c && d) break;
    }
    
    return std::max(6 - n, 4 - (a + b + c + d));
}


int minimumNumber3(int n, string password) {
    int a = 0, b = 0, c = 0, d = 0;
    
    for (const auto & check : password )
    {
        if (isdigit(check))
        {
            a = 1;
        }
        else if (isupper(check))
        {
            b = 1;
        }
        else if (islower(check))
        {
            c = 1;
        }
        else
        {
            d = 1;
        }
    }
    
    return std::max(6 - n, 4 - a - b - c - d);
}
