package edu.uab.cis;

import java.io.BufferedReader;
import java.io.IOException;

public class DirectedGraph extends Graph {
	
	public DirectedGraph(BufferedReader reader) throws IOException { super(reader); }
	
	// Add w to v's adjacency list, but not vice versa
	public void addEdge(int v, int w) 
	{
        adj[v].add(w);
    }

}
