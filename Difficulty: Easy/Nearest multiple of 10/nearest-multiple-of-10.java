//{ Driver Code Starts
// Initial Template for Java

// Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;


// } Driver Code Ends
// User function Template for Java
import java.math.BigInteger;
class Solution {

    String roundToNearest(String str) {
        // Complete the function// Handle leading zeros explicitly
        int leadingZeros = 0;
        while (leadingZeros < str.length() && str.charAt(leadingZeros) == '0') {
            leadingZeros++;
        }

        BigInteger num = new BigInteger(str);
        BigInteger ten = new BigInteger("10");
        BigInteger lastDigit = num.mod(ten);  // Get the last digit

        // If the last digit is exactly 5
        if (lastDigit.equals(new BigInteger("5"))) {
            num = num.divide(ten).multiply(ten);
        } else if (lastDigit.compareTo(new BigInteger("5")) > 0) {  // If last digit > 5
            num = num.divide(ten).multiply(ten).add(ten);
        } else {  // If last digit < 5
            num = num.divide(ten).multiply(ten);
        }

        // Convert result back to string and prepend leading zeros
        String result = num.toString();
        return "0".repeat(leadingZeros) + result;
    }
}


//{ Driver Code Starts.

// Driver class
class Array {

    // Driver code
    public static void main(String[] args) throws IOException {
        // Taking input using buffered reader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int testcases = Integer.parseInt(br.readLine());

        // looping through all testcases
        while (testcases-- > 0) {

            String str = br.readLine().trim();

            Solution obj = new Solution();

            String res = obj.roundToNearest(str);

            System.out.println(res);
        }
    }
}

// } Driver Code Ends