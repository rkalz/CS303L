package edu.uab.cis;

import java.io.BufferedReader;
import java.io.IOException;

public class UndirectedGraph extends Graph {
	
	public UndirectedGraph(BufferedReader reader) throws IOException { super(reader); }
	
	// Add v to w's adjacency list and vice versa
	public void addEdge(int v, int w) 
	{
		adj[v].add(w);
		adj[w].add(v);
    }


}
