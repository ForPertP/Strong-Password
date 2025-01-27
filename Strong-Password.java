import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'minimumNumber' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER n
     *  2. STRING password
     */

    private static int countSetBits(int num) {
        int count = 0;
        while (num > 0) {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }

    public static int minimumNumber(int n, String password) {
        int flags = 0;

        for (char c : password.toCharArray()) {
            if (Character.isDigit(c)) flags |= 1;
            else if (Character.isUpperCase(c)) flags |= 2;
            else if (Character.isLowerCase(c)) flags |= 4;
            else flags |= 8;

            if (flags == 15) break;
        }

        int requiredCharacterTypes = 4 - countSetBits(flags);
        int additionalCharactersNeeded = Math.max(0, 6 - n);

        return Math.max(requiredCharacterTypes, additionalCharactersNeeded);
    }

    
    public static int minimumNumber2(int n, String password) {
        int a = 0, b = 0, c = 0, d = 0;

        for (char check : password.toCharArray()) {
            if (Character.isDigit(check)) a = 1;
            else if (Character.isUpperCase(check)) b = 1;
            else if (Character.isLowerCase(check)) c = 1;
            else d = 1;

            if (a + b + c + d == 4) break;
        }

        return Math.max(6 - n, 4 - (a + b + c + d));
    }
}


public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        String password = bufferedReader.readLine();

        int answer = Result.minimumNumber(n, password);

        bufferedWriter.write(String.valueOf(answer));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
