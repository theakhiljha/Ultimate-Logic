public class BubbleSorting {
	
	int array[];

	public BubbleSorting() {
		setArray();
	}
	
	public static void main(String[] args) {
		BubbleSorting bs = new BubbleSorting();
		bs.printTheArray();
		bs.sortTheArray();
		bs.printTheArray();
	}
	
	private void sortTheArray() {	
		int i,temp;//temp is for swapping
		boolean sorted = false;
		
		while(!sorted){
			
			sorted=true;
			for(i=0;i<array.length-1;i++){
				if(array[i]>array[i+1]){
					temp = array[i];
					array[i]=array[i+1];
					array[i+1]=temp;
					sorted=false;
				}
			}
		}
		
	}
	
	private void printTheArray() {
		for(int i=0; i<array.length; i++) {
			System.out.print(array[i]+" ");
		}
		System.out.println();
	}

	private void setArray() {
		int[] a = {72,21,69,38,96,77,30,19,42,55,99};
		array = a;
	}

}
