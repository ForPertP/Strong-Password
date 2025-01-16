int minimumNumber(int n, string password)
{
    int count = 0;
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


int minimumNumber(int n, string password) {
    // 이미 길이가 6 이상이고 모든 조건을 만족하면 바로 0 반환
    int a = 0, b = 0, c = 0, d = 0;
    
    for (char check : password) { // const auto& 대신 char 사용
        if (isdigit(check)) a = 1;
        else if (isupper(check)) b = 1;
        else if (islower(check)) c = 1;
        else d = 1;
        
        // 모든 조건이 만족되면 루프 종료
        if (a && b && c && d) break;
    }
    
    return std::max(6 - n, 4 - (a + b + c + d));
}


int minimumNumber(int n, string password) {
    uint8_t flags = 0;
    
    for (char c : password) {
        if (isdigit(c)) flags |= 1;
        else if (isupper(c)) flags |= 2;
        else if (islower(c)) flags |= 4;
        else flags |= 8;
        
        if (flags == 15) break; // 모든 비트가 설정되면 종료
    }
    
    return std::max(6 - n, 4 - __builtin_popcount(flags));
}
