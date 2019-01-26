import java.util.*;

public class Main 
{ 
 //   static int n;
    public static int parenthesis[][];
    
    public static int Matrixmul(int p[], int n) 
    { 
        if(n==0)
            return 0;
        int dp[][] = new int[n][n];
        parenthesis = new int[n][n]; 
        int i, j;
        int k, l;
        int min;
        for(i=1; i<n; i++){
            dp[i][i] = 0;
        } 
        for (l=2; l<n; l++) 
        { 
            for (i=1; i<n-l+1; i++) 
            { 
                j = i+l-1; 
                dp[i][j] = Integer.MAX_VALUE; 
                for (k=i; k<=j-1; k++) 
                { 
                    min = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                    //dp[i][j] = Math.min(dp[i][j], min);
                    if(min < dp[i][j]){
                        dp[i][j] = min;
                        parenthesis[i][j] = k;
                    }
                            
                } 
            } 
        }
        return dp[1][n-1]; 
    }
    public static void printParenthesis(int parenthesis[][], int start, int end){
        if(start == end){
            System.out.print(start);
        }
        else{
            System.out.print("(");
            printParenthesis(parenthesis, start, parenthesis[start][end]);
            printParenthesis(parenthesis, parenthesis[start][end] + 1, end);
            System.out.print(")");
        }
    }
    public static void main(String args[]) 
    { 
        int arr[] = new int[] {30, 35, 15, 5, 10, 20, 25}; 
        int size = arr.length;
        System.out.println("Minimum number of multiplications is "+ 
                           Matrixmul(arr, size));
        printParenthesis(parenthesis, 1, size - 1);
        System.out.println();
    } 
}