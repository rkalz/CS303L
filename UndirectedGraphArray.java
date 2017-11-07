package edu.uab.cis;

import java.io.BufferedReader;
import java.io.IOException;

public class UndirectedGraphArray extends GraphArray {
	
	public UndirectedGraphArray(BufferedReader reader) throws IOException { super(reader); }

	@Override
	public void addEdge(int v, int w) {
		adj[v][w] = true;
		adj[w][v] = true;

	}

}
