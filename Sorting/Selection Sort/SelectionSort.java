import java.util.Scanner;

public class SelectionSort {

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

    public static void selectionSort(int[] arr){
        for(int si = 0 ; si < arr.length - 1 ; si++ ){
            for( int j = si + 1 ; j < arr.length ; j++ ){
                if( arr[si] > arr[j] ){
                    int temp = arr[si];
                    arr[si] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    public static void main(String[] args) {
        System.out.println("Enter the number of elements");
        int n = scn.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the elements of the array");
        input(arr);
        selectionSort(arr);
        display(arr);
    }
}