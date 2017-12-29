package edu.uab.cis;

import java.util.LinkedList;

public class DepthFirstPaths {
	private enum Color { WHITE, GRAY, BLACK }
	private static int NIL = -1;
	private Color[] color;
	private int[] pi;
	private int[] d;
	private int[] f;
	private int src;
	private Graph graph;
	private int time;
	private LinkedList<Integer> top;
	
	private boolean visited[];
	private boolean done;
	
	public DepthFirstPaths(Graph G, int source) 
	{
		color = new Color[G.V];
		pi = new int[G.V];
		d = new int[G.V];
		f = new int[G.V];
		src = source;
		graph = G;
		top = new LinkedList<>();
		
		DFS();
	}
	
	private void DFS()
	{
		for (int u = src; u < graph.V; u++)
		{
			color[u] = Color.WHITE;
			pi[u] = NIL;
		}
		time = 0;
		for (int u = src; u < graph.V; u++)
		{
			if (color[u] == Color.WHITE) DFSVisit(u);
		}
	}
	
	private void DFSVisit(int u)
	{
		time++;
		d[u] = time;
		color[u] = Color.GRAY;
		for (int v : graph.adj[u])
		{
			if (color[v] == Color.WHITE)
			{
				pi[v] = u;
				DFSVisit(v);
			}
		}
		color[u] = Color.BLACK;
		time++;
		f[u] = time;
		top.addFirst(u);
	}
	
	public LinkedList<Integer> topologicalSort() { return top; }
	
	
}