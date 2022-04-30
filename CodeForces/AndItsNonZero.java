import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.lang.Exception;
import java.lang.Math;

public class Main{
    static class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br=new BufferedReader(new InputStreamReader(System.in));
        }
        String next(){
            while(st==null||!st.hasMoreElements()){
                try{
                    st=new StringTokenizer(br.readLine());
                }catch(IOException e){
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt(){return Integer.parseInt(next());}
        long nextLong(){return Long.parseLong(next());}
        double nextDouble(){return Double.parseDouble(next());}
        String nextLine(){
            String str="";
            try{
                if(st.hasMoreTokens()) str=st.nextToken("\n");
                else str=br.readLine();
            }catch(IOException e){
                e.printStackTrace();
            }
            return str;
        }
    }
    static FastReader sc=new FastReader();
    static int nMax=200000;
    static int[][] dp=new int[nMax+1][18];
    static void prec(){
        for(int i=0;i<18;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<nMax+1;i++){
            int j=17;
            int x=i;
            while(x>0){
                dp[i][j]=x%2+dp[i-1][j];
                x/=2;
                j--;
            }
        }
    }
    static void solve(){
        int l=sc.nextInt();
        int r=sc.nextInt();
        int m=0;
        for(int i=0;i<18;i++){
            m=Math.max(m,dp[r][i]-dp[l-1][i]);
        }
        System.out.println(r-l+1-m);
    }
    public static void main(String args[])throws java.lang.Exception{
        prec();
        int t=sc.nextInt();
        while(t-->0){
            solve();
        }
    }
}
