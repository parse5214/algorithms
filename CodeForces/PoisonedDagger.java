import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.lang.Exception;

public class PoissonedDagger{
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
    
    static long binarySearch(long[] diff,long h){
        long low=0;
        long high=h;
        long mid=(low+high)/2;
        int sz=diff.length;
        while(high>low){
            long sum=0;
            for(int i=0;i<sz;i++){
                if(mid<diff[i]) sum+=mid;
                else sum+=diff[i];
            }
            if(sum>=h) high=mid;
            else low=mid+1;
            mid=(low+high)/2;
        }
        return mid;
    }
    
    static void solve(){
        int n=sc.nextInt();
        long h=sc.nextLong();
        int[] a=new int[n];
        for(int i=0;i<n;i++) a[i]=sc.nextInt();
        long[] diff=new long[n];
        for(int i=0;i<n;i++){
            if(i==n-1) diff[i]=h;
            else diff[i]=a[i+1]-a[i];
        }
        long k=binarySearch(diff,h);
        System.out.println(k);
    }
    
    public static void main(String args[])throws java.lang.Exception{
        int t=sc.nextInt();
        while(t-->0){
            solve();
        }
    }
}
