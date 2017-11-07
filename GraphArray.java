package edu.uab.cis;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.StringTokenizer;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

public abstract class GraphArray {
    public int V;
    public int E;
    
    public boolean[][] adj;
    
    public GraphArray()
    {
        V = 0;
        E = 0;
    }
    
    @SuppressWarnings("unchecked")
	public GraphArray(BufferedReader reader) throws IOException
    {
        String line;
        line = reader.readLine();
        V = Integer.parseInt(line);
        line = reader.readLine();
        E = Integer.parseInt(line);
        adj = new boolean[V][V];
        while ((line = reader.readLine()) != null) {
            int tempV1, tempV2;
              StringTokenizer st = new StringTokenizer(line, " ");
              tempV1 = Integer.parseInt(st.nextToken());
              tempV2 = Integer.parseInt(st.nextToken());
              addEdge(tempV1, tempV2);
        }
    }
    
    public abstract void addEdge(int v, int w);
    
    public String toString()
    {
        String s = new String();
        s = "There are "+V+" vertices and "+E+" edges\n";
        for(int i=0;i<V;i++)
        {
            s = s+i+": ";
            for(int j = 0; j<V ;j++)
            {
            	if (adj[i][j]) s = s+j+" ";
            }
            s = s+"\n";
            
        }
        return s;
    }
    
}
