import java.io.*;
import java.util.*;

public class OddNumberOfTimes {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(br.readLine().trim());
        while (testcases-- > 0) {
            String[] inputLine;
            inputLine = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputLine[0]);
            int[] arr = new int[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }
            int ans = new Solution().getOddOccurrence(arr, n);
            System.out.println(ans);
        }
    }
}
class Solution {
    int getOddOccurrence(int[] arr, int n) {
        int res=0;
        for(int i=0;i<n;i++)
        {
           res=res^arr[i]; 
        }
        return res;
    }
}
