import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.lang.Exception;

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
    static long binarySearch(long k,long x){
        long low=0;
        long high=2*k;
        long mid=(low+high)/2;
        long sum=0;
        while(high>low){
            if(mid>k) sum=k*k-((2*k-mid-1)*(2*k-mid))/2;
            else sum=(mid*(mid+1))/2;
            if(sum>=x) high=mid;
            else low=mid+1;
            mid=(low+high)/2;
        }
        if(mid==2*k) return mid-1;
        return mid;
    }
    static void solve(){
        long k=sc.nextLong();
        long x=sc.nextLong();
        long result=binarySearch(k,x);
        System.out.println(result);
    }
    public static void main(String args[])throws java.lang.Exception{
        int t=sc.nextInt();
        while(t-->0){
            solve();
        }
    }
}
