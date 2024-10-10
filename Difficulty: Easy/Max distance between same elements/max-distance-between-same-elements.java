//{ Driver Code Starts
import java.util.*;
import java.util.Scanner;


// } Driver Code Ends

import java.util.Arrays;
class Solution {
    public int maxDistance(int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int maxDist = 0;
        int n = arr.length;  // Store the size of the array

        for (int i = 0; i < n; i++) {
            // Check if the element is already in the map
            if (!map.containsKey(arr[i])) {
                // If not found, store the index
                map.put(arr[i], i);
            } else {
                // If found, calculate the max distance
                maxDist = Math.max(maxDist, i - map.get(arr[i]));
            }
        }
        return maxDist;
    }
}

//{ Driver Code Starts.
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            String input = sc.nextLine();
            String[] parts = input.split(" ");
            int[] arr = new int[parts.length];
            for (int i = 0; i < parts.length; i++) {
                arr[i] = Integer.parseInt(parts[i]);
            }
            Solution ob = new Solution();
            System.out.println(ob.maxDistance(arr));
        }
        sc.close();
    }
}
// } Driver Code Ends