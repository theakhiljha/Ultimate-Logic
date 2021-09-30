import java.util.Scanner;

public class MergeSort {
    public static void display(int[] arr) {
        for(int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    
    public static int[] merge2sortedArray(int[] arr1, int[] arr2) { 
        int[] ans = new int[ arr1.length + arr2.length ];
        int i = 0;  // for travering arr1
        int j = 0;  // for travering arr2
        int k = 0;  // for travering ans
        while (i < arr1.length && j < arr2.length) {
            if (arr1[i] < arr2[j]) {
                ans[k] = arr1[i];
                k++; i++;
            } else {
                ans[k] = arr2[j];
                j++; k++;
            }
        }
        while (i < arr1.length){
            ans[k] = arr1[i];
            k++; i++;
        }
        while (j < arr2.length) {
            ans[k] = arr2[j];
            j++; k++;
        }
        return ans;
    }
    
    public static int[] mergeSort(int[] arr, int lo , int hi) {
        if (lo == hi) {
            int[] base = new int[1];
            base[0] = arr[lo];
            return base;
        }
        int mid = (lo + hi ) / 2;
        int[] left =  mergeSort(arr, lo, mid);
        int[] right = mergeSort(arr, mid + 1, hi);
        int[] ans = merge2sortedArray(left, right);
        return ans;
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter the size of array");
        int n = scn.nextInt(); // Size of array
        int[] arr = new int[n];
        System.out.println("Enter the elements of array");
        for (int i = 0; i < n; i++) {
            arr[i] = scn.nextInt();
        }
        int[] ans = mergeSort(arr, 0, arr.length - 1);
        System.out.println("Sorted array: ");
        for(int i = 0; i < ans.length; i++) {
            System.out.print(ans[i] + " ");
        }
    }

}