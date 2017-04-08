import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class ArraysManip {

	public static void rotate(int [] array, int k){
		k =  k % array.length;
		
		System.out.println(k);
		int[] temp = new int[array.length];
		if(k<0){
			k *= -1;
			int a=0;
			for(int iter=k;iter<array.length;iter++){
				temp[a++] = array[iter];
			}
			for(int iter = 0;iter < k;iter++){
				temp[a++] = array[iter];
			}
		}else if(k>0)
		{
			int a=0;
			for(int iter=array.length-k;iter<array.length;iter++){
				temp[a++] = array[iter];
			}
			for(int iter=0; iter < array.length-k;iter++){
				temp[a++] = array[iter];
			}
			
		}else{
			temp = array.clone();
		}
		System.out.println(Arrays.toString(array));
		System.out.println(Arrays.toString(temp));
	}
	
	public static void duplicate(int [] array){
		Set<Integer> set = new HashSet<Integer>();
		for(int i : array){
			if(set.add(i) == false){
				System.out.println(true);
				return;
			}
		}
		System.out.println(false);
	}
}
