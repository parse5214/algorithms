import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.lang.Exception;
import java.util.Arrays;
import java.util.HashMap;

public class ArrayAndOperations{
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
    static void solve(){
        int n=sc.nextInt();
        int k=sc.nextInt();
        int[] a=new int[n];
        for(int i=0;i<n;i++) a[i]=sc.nextInt();
        Arrays.sort(a);
        HashMap<Integer,Integer> fq=new HashMap<Integer,Integer>();
        for(int i=n-1;i>=n-2*k;i--){
            if(fq.containsKey(a[i])){
                fq.replace(a[i],fq.get(a[i])+1);
            }else{
                fq.put(a[i],1);
            }
        }
        int maxfq=0;
        for(var it:fq.values()){
            if(maxfq<it) maxfq=it;
        }
        int num=maxfq-k;
        int sum=0;
        if(num>0) sum+=num;
        for(int i=0;i<n-2*k;i++) sum+=a[i];
        System.out.println(sum);
    }
    public static void main(String args[])throws java.lang.Exception{
        int t=sc.nextInt();
        while(t-->0){
            solve();
        }
    }
}
