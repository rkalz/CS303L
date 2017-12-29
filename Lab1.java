package edu.uab.cis;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;

import java.util.Scanner;

public class Lab1 {

	public static void main(String[] args) throws FileNotFoundException {
		
		ArrayList<int[]> arrays = new ArrayList<>();
		
		for (int i = 4; i <= 25; i++)
		{
			int size = (int) Math.pow(2,i);
			int[] arr = new int[size];
			
			for (int j = 0; j < size; j++)
			{
				arr[j] = (int) ((size-1)*Math.random());
			}
			
			arrays.add(arr);
		}
		
		for (int[] arr : arrays)
		{
			int num = (int) ((arr.length-1)*Math.random());
			System.out.println(arr.length + ": ");
			long start = System.nanoTime();
			System.out.println("Searching For: " + num);
			System.out.println("Linear Search: " + linearSearch(arr,num)); // n
			System.out.println("Time Taken: " + Math.log10(System.nanoTime() - start));
			
			start = System.nanoTime();
			Arrays.sort(arr); // n log n
			System.out.println("Sort Time Taken: " + Math.log10(System.nanoTime() - start));
			
			start = System.nanoTime();
			System.out.println("Binary Search: " + binarySearch(arr,num)); // log n
			System.out.println("Search Time Taken: " + Math.log10(System.nanoTime() - start));
			
			System.out.println();
		}
		
		Scanner s = new Scanner(new File("input_1000.txt"));
		ArrayList<Integer> readNums = new ArrayList<Integer>();
		while (s.hasNextInt())
		{
			readNums.add(s.nextInt());
		}
		s.close();
		int[] read = new int[readNums.size()];
		for (int i = 0; i < read.length; i++)
		{
			read[i] = readNums.get(i);
		}
		
		int num = (int) ((Math.pow(2, 25)-1)*Math.random());
		System.out.println("Input file: " + read.length + ": ");
		long start = System.nanoTime();
		System.out.println("Searching For: " + num);
		System.out.println("Linear Search: " + linearSearch(read,num)); // n
		System.out.println("Search Time Taken: " + Math.log10(System.nanoTime() - start));
		
		start = System.nanoTime();
		Arrays.sort(read); // n log n
		System.out.println("Sort Time Taken: " + Math.log10(System.nanoTime() - start));
		
		start = System.nanoTime();
		System.out.println("Binary Search: " + binarySearch(read,num)); // log n
		System.out.println("Search Time Taken: " + Math.log10(System.nanoTime() - start));
		
		System.out.println();
		
		
	}
	
	public static int linearSearch(int[] array, int target)
	{
		for (int i : array)
		{
			if (i == target) return i;
		}
		
		return -1;
	}
	
	public static int binarySearch(int[] array, int target)
	{
		int min = array[0];
		int max = array[array.length - 1];
		int mid = array[array.length/2];
		
		if (target < min || target > max)
		{
			return -1;
		}
		else if (mid == target)
		{
			return mid;
		}
		else if (target < mid && target >= min) // target is between 0 and mid
		{
			int[] left = new int[array.length/2];
			System.arraycopy(array, 0, left, 0, left.length); // n, this kills the binary search
			return binarySearch(left,target);
			
		}
		else if (target > mid && target <= max) // target is between mid and length-1
		{
			int[] right = new int[array.length/2];
			System.arraycopy(array, array.length/2, right, 0, right.length); // n
			return binarySearch(right,target);
		}
		
		return -1;
		
		
	}

}
