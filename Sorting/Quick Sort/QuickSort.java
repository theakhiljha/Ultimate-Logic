import java.util.Scanner;

public class QuickSort {
    
    static Scanner scn = new Scanner(System.in);

    public static void display(int[] arr) {
        for(int i = 0 ; i < arr.length ; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void input(int[] arr) {
        for(int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextInt();
        }
    }

    public static int parition(int[] arr , int low, int high) {
        int i = low , j = low, pivot = arr[high];
        while(j <= high ){
            if(arr[j] <= pivot){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
            }
            j++;
        }
        return i - 1;
    }

    public static void quickSort(int[] arr, int low, int high) {
        if( low >= high ){
            return;
        }
        int pivotIndex = parition(arr, low, high);
        quickSort(arr, low ,pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }


    public static void main(String[] args) {
        System.out.println("Enter the number of elements");
        int n = scn.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the elements of the array");
        input(arr);
        quickSort(arr, 0, arr.length - 1);
        display(arr);
    }
}