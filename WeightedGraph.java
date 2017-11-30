package edu.uab.cis;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.util.PriorityQueue;


public class WeightedGraph {
	
	private class Edge {
		
		public int to;
		public double weight;
		
		private Edge(int v, double w)
		{
			to = v;
			weight = w;
		}
		
		public String toString() {
			return Integer.toString(to) + "(" + Double.toString(weight) + ")";
		}
		
	}
	
	private class EdgeWeightComparator implements Comparator<Edge> {

		@Override
		public int compare(Edge a, Edge b) {
			return Double.compare(a.weight, b.weight);
		}
		
	}
	
	private static int NIL = -1;
	
	private int V;
	private int E;
	private LinkedList<Edge>[] adj;
	private int[] pi;
	private double[] key;
	private double[] d;
	
	@SuppressWarnings("unchecked")
	public WeightedGraph(BufferedReader reader) throws IOException
	{
		String line;
        line = reader.readLine();
        V = Integer.parseInt(line);
        line = reader.readLine();
        E = Integer.parseInt(line);
        adj =  new LinkedList[V];
        for (int v = 0; v < V; v++) {
            adj[v] = new LinkedList<Edge>();
        }
        while ((line = reader.readLine()) != null) {
            int tempV1, tempV2;
            double tempW;
            StringTokenizer st = new StringTokenizer(line, " ");
            tempV1 = Integer.parseInt(st.nextToken());
            tempV2 = Integer.parseInt(st.nextToken());
            tempW = Double.parseDouble(st.nextToken());
            addEdge(tempV1, tempV2, tempW);
        }
        
        pi = new int[V];
        key = new double[V];
        d = new double[V];
	}

	private void addEdge(int u, int v, double w) {
		
		Edge e = new Edge(v,w);
		adj[u].add(e);
	
	}
	
	public String toString() {
		String s = new String();
        s = "There are "+V+" vertices and "+E+" edges\n";
        for(int i=0;i<V;i++)
        {
            s = s+i+": ";
            for(int j = 0; j<adj[i].size();j++)
            {
                s = s+adj[i].get(j)+" ";
            }
            s = s+"\n";
            
        }
        return s;
	}
	
	public int[] MSTPrim(int r)
	{
		boolean[] inMST = new boolean[V];
		for (int i = 0; i < V; i++)
		{
			key[i] = Double.MAX_VALUE;
			pi[i] = NIL;
		}
		PriorityQueue<Edge> queue = new PriorityQueue<>(new EdgeWeightComparator());
		key[r] = 0;
		queue.add(new Edge(r,0));
		
		while (!queue.isEmpty())
		{
			int u = queue.remove().to;
			inMST[u] = true;
			for (Edge e : adj[u])
			{
				int v = e.to;
				if (!inMST[v] && key[v] > e.weight)
				{
					key[v] = e.weight;
					queue.add(e);
					pi[v] = u;
				}
			}
		}
		
		return pi;
	}
	
	public void Djikstra(int s)
	{
		boolean[] visited = new boolean[V];
		initializeSingleSource(s);
		LinkedList<Integer> set = new LinkedList<>();
		PriorityQueue<Edge> queue = new PriorityQueue<>(new EdgeWeightComparator());
		queue.add(new Edge(s, 0));
		while (!queue.isEmpty())
		{
			int u = queue.remove().to;
			if (!visited[u])
			{
				visited[u] = true;
				set.add(u);
				for (Edge e : adj[u])
				{
					relax(u, e.to, e.weight);
					queue.add(e);
				}
			}
		}
	}
	
	private void initializeSingleSource(int s)
	{
		for (int v = 0; v < V; v++)
		{
			d[v] = Double.MAX_VALUE;
			pi[v] = NIL;
		}
		d[s] = 0;
	}
	
	private void relax(int u, int v, double w)
	{
		if (d[v] > (d[u] + w))
		{
			d[v] = d[u] + w;
			pi[v] = u;
		}
	}
	
	public LinkedList<Integer> printPath(int i, int j)
	{
		LinkedList<Integer> path = new LinkedList<>();
		path.add(j);
		while (j != NIL && j != i)
		{
			j = pi[j];
			path.add(j);
		}
		return path;
	}
	
	public int getVertexCount() { return V; }

}
