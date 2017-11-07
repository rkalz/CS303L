package edu.uab.cis;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;

public class Lab10 {

	public static void main(String[] args) throws FileNotFoundException, IOException 
	{
		long start = System.nanoTime();
		UndirectedGraph undirectedList = new UndirectedGraph(new BufferedReader(new FileReader("mediumG.txt")));
		long end = System.nanoTime();
		long diff = (end-start)/1000;
		System.out.println("Undirected Graph (Adj List): " + diff + " mus");
		
		start = System.nanoTime();
		DirectedGraph directedList = new DirectedGraph(new BufferedReader(new FileReader("tinyDG.txt")));
		end = System.nanoTime();
		diff = (end-start)/1000;
		System.out.println("Directed Graph (Adj List): " + diff + " mus");
		System.out.println();
		
		start = System.nanoTime();
		UndirectedGraphArray undirectedArray = new UndirectedGraphArray(new BufferedReader(new FileReader("mediumG.txt")));
		end = System.nanoTime();
		diff = (end-start)/1000;
		System.out.println("Undirected Graph (Adj Matrix): " + diff + " mus");
		
		start = System.nanoTime();
		DirectedGraphArray directedArray = new DirectedGraphArray(new BufferedReader(new FileReader("tinyDG.txt")));
		end = System.nanoTime();
		diff = (end-start)/1000;
		System.out.println("Directed Graph (Adj Matrix): " + diff + " mus");
		System.out.println();
		
		int n = 17;
		
		start = System.nanoTime();
		BFS(undirectedList, n);
		end = System.nanoTime();
		diff = (end-start)/1000;
		System.out.println("BFS (Adj List): " + diff + " mus");
		
		start = System.nanoTime();
		BFS(undirectedArray, n);
		end = System.nanoTime();
		diff = (end-start)/1000;
		System.out.println("BFS (Adj Matrix): " + diff + " mus");
	}
	
	static String BFS(Graph graph, int target)
	{
		boolean[] visited = new boolean[graph.V];
		Queue<Integer> queue = new LinkedList<>();
		String s = new String();
		
		queue.add(0);
		visited[0] = true;
		while (!queue.isEmpty())
		{
			int parent = queue.remove();
			s = s + parent + " ";
			if (parent == target) break;
			LinkedList<Integer> adj = graph.adj[parent];
			for (int child : adj)
			{
				if (!visited[child])
				{
					queue.add(child);
					visited[child] = true;
				}
			}
		}
		s = s + "\n";
		return s;
	}
	
	static String BFS(GraphArray graph, int target)
	{
		boolean[] visited = new boolean[graph.V];
		Queue<Integer> queue = new LinkedList<>();
		String s = new String();
		
		queue.add(0);
		visited[0] = true;
		while (!queue.isEmpty())
		{
			int parent = queue.remove();
			s = s + parent + " ";
			if (parent == target) break;
			boolean[] children = graph.adj[parent];
			for (int i = 0; i < graph.V; i++)
			{
				if (children[i] && !visited[i])
				{
					queue.add(i);
					visited[i] = true;
				}
			}
		}
		s = s + "\n";
		return s;
	}

}
