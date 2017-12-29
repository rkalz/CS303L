package edu.uab.cis;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class Graphs {
	
	WeightedGraph graph;
	double[] dist;
	int[] last;
	
	public Graphs(String path) throws FileNotFoundException, IOException {
		graph = new WeightedGraph(new BufferedReader(new FileReader(path)));
		dist = new double[graph.getVertexCount()];
		last = new int[graph.getVertexCount()];
	}
	
	public void Djikstra(int a, int b) {
		
		for (int i = 0; i < graph.getVertexCount(); i++) {
			dist[i] = Double.MAX_VALUE;
			last[i] = -1;
		}
		
		dist[a] = 0;
		PriorityQueue<>
		
	}
	
	public void AStar(int a, int b) {
		
	}

}
