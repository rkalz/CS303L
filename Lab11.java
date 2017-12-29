package edu.uab.cis;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class Lab11 {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		
		UndirectedGraph medium = new UndirectedGraph(new BufferedReader(new FileReader("mediumG.txt")));
		UndirectedGraph tiny = new UndirectedGraph(new BufferedReader(new FileReader("tinyDG.txt")));
		DepthFirstPaths dfpM = new DepthFirstPaths(medium, 17);
		DepthFirstPaths dfpT = new DepthFirstPaths(tiny, 10);
		
		//System.out.println(dfpM.topologicalSort());
		System.out.println(dfpT.topologicalSort());
		

	}

}
