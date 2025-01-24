using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'minimumNumber' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER n
     *  2. STRING password
     */


    private static int CountSetBits(int num)
    {
        int count = 0;
        while (num > 0)
        {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }

    public static int minimumNumber(int n, string password)
    {
        int flags = 0;

        foreach (char c in password)
        {
            if (char.IsDigit(c)) flags |= 1;
            else if (char.IsUpper(c)) flags |= 2;
            else if (char.IsLower(c)) flags |= 4;
            else flags |= 8;

            if (flags == 15) break;
        }

        return Math.Max(6 - n, 4 - CountSetBits(flags));
    }
    
        
    public static int minimumNumber2(int n, string password)
    {
        int a = 0, b = 0, c = 0, d = 0;

        foreach (char check in password)
        {
            if (char.IsDigit(check)) a = 1;
            else if (char.IsUpper(check)) b = 1;
            else if (char.IsLower(check)) c = 1;
            else d = 1;

            if (a + b + c + d == 4) break;
        }

        return Math.Max(6 - n, 4 - (a + b + c + d));
    }
}


class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int n = Convert.ToInt32(Console.ReadLine().Trim());

        string password = Console.ReadLine();

        int answer = Result.minimumNumber(n, password);

        textWriter.WriteLine(answer);

        textWriter.Flush();
        textWriter.Close();
    }
}
