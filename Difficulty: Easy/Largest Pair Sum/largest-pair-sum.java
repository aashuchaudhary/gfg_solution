//{ Driver Code Starts
import java.io.*;
import java.util.*;

class IntArray {
    public static int[] input(BufferedReader br, int n) throws IOException {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = Integer.parseInt(s[i]);

        return a;
    }

    public static void print(int[] a) {
        for (int e : a) System.out.print(e + " ");
        System.out.println();
    }

    public static void print(ArrayList<Integer> a) {
        for (int e : a) System.out.print(e + " ");
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;
            Solution obj = new Solution();
            int res = obj.pairsum(arr);

            System.out.println(res);
        }
    }
}

// } Driver Code Ends



class Solution {
    public static int pairsum(int[] arr) {
        // Initialize the first and second maximums
        int first_max = Integer.MIN_VALUE, second_max = Integer.MIN_VALUE;

        // Traverse the array to find the two largest elements
        for (int num : arr) {
            if (num > first_max) {
                second_max = first_max;  // Update second_max
                first_max = num;         // Update first_max
            } else if (num > second_max) {
                second_max = num;        // Update second_max if it's smaller than first_max but larger than second_max
            }
        }

        // Return the sum of the two largest numbers
        return first_max + second_max;
    }
}
