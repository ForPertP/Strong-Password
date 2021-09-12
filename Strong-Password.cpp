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

