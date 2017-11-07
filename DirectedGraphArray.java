package edu.uab.cis;

import java.io.BufferedReader;
import java.io.IOException;

public class DirectedGraphArray extends GraphArray {
	
	public DirectedGraphArray(BufferedReader reader) throws IOException { super(reader); }

	@Override
	public void addEdge(int v, int w) {
		adj[v][w] = true;
	}

}
