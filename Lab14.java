package edu.uab.cis;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class Lab14 {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		WeightedGraph graph = new WeightedGraph(new BufferedReader(new FileReader("tinyDG.txt")));
		long start = System.nanoTime();
		graph.Djikstra(0);
		System.out.println(graph.printPath(0, 5));
		long end = System.nanoTime();
		long diff = (end - start) / 1000;
		System.out.println("Tiny: " + diff + " mus");
		
		graph = new WeightedGraph(new BufferedReader(new FileReader("mediumDG.txt")));
		start = System.nanoTime();
		graph.Djikstra(0);
		end = System.nanoTime();
		diff = (end - start) / 1000;
		System.out.println("Medium: " + diff + " mus");
		
		graph = new WeightedGraph(new BufferedReader(new FileReader("largeDG.txt")));
		start = System.nanoTime();
		graph.Djikstra(0);
		end = System.nanoTime();
		diff = (end - start) / 1000;
		System.out.println("Large: " + diff + " mus");
		
		graph = new WeightedGraph(new BufferedReader(new FileReader("XtraLargeDG.txt")));
		start = System.nanoTime();
		graph.Djikstra(0);
		end = System.nanoTime();
		diff = (end - start) / 1000;
		System.out.println("Xtra: " + diff + " mus");
		

	}
	
	

}
