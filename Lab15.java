package edu.uab.cis;

public class Lab15 {

	
	public static void main(String[] args) {
		
		int i = 50;
		int j = 3;
		System.out.println("Recursive: " + BCR(i,j));
		System.out.println("Dynamic:   " + BCDP(i,j));
		

	}
	
	public static int BCR(int n, int k) {
		if (k == 0 || k == n) return 1;
		else return BCR(n-1, k-1) + BCR(n-1, k);
	}
	
	public static int BCDP(int n, int k) {
		int dp[][] = new int[n+1][n+1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (i == 0 || j > i) dp[i][j] = 0;
				else if (j == 0 || j == i) dp[i][j] = 1;
				else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			}
		}
		
		return dp[n][k];
	}

}

