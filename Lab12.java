package edu.uab.cis;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class Lab12 {
	
	@SuppressWarnings("unused")
	public static void main(String[] args) throws FileNotFoundException, IOException 
	{
		long start = System.nanoTime();
		WeightedGraph graph = new WeightedGraph(new BufferedReader(new FileReader("tinyDG.txt")));
		long end = System.nanoTime();
		long diff = (end-start)/1000;
		System.out.println("Tiny Generator: " + diff + " mus");
		
		start = System.nanoTime();
		graph.MSTPrim(0);
		end = System.nanoTime();
		diff = (end-start)/1000;
		System.out.println("Tiny MST: " + diff + " mus");
		System.out.println();
		
		start = System.nanoTime();
		graph = new WeightedGraph(new BufferedReader(new FileReader("mediumDG.txt")));
		end = System.nanoTime();
		diff = (end-start)/1000;
		System.out.println("Medium Generator: " + diff + " mus");
		
		start = System.nanoTime();
		graph.MSTPrim(0);
		end = System.nanoTime();
		diff = (end-start)/1000;
		System.out.println("Medium MST: " + diff + " mus");
		System.out.println();

		
		start = System.nanoTime();
		graph = new WeightedGraph(new BufferedReader(new FileReader("largeDG.txt")));
		end = System.nanoTime();
		diff = (end-start)/1000;
		System.out.println("Large Generator: " + diff + " mus");
		
		start = System.nanoTime();
		graph.MSTPrim(0);
		end = System.nanoTime();
		diff = (end-start)/1000;
		System.out.println("Large MST: " + diff + " mus");
		System.out.println();

		
		start = System.nanoTime();
		graph = new WeightedGraph(new BufferedReader(new FileReader("XtraLargeDG.txt")));
		end = System.nanoTime();
		diff = (end-start)/1000;
		System.out.println("Xtra Generator: " + diff + " mus");
		
		start = System.nanoTime();
		graph.MSTPrim(0);
		end = System.nanoTime();
		diff = (end-start)/1000;
		System.out.println("Xtra MST: " + diff + " mus");
		
	}

}
