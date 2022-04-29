import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.lang.Exception;
import java.util.ArrayList;
import java.util.Collections;

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
    static void solve(){
        int n=sc.nextInt();
        boolean[] v=new boolean[n+1];
        ArrayList<Integer> v1=new ArrayList<Integer>(n);
        ArrayList<Integer> v2=new ArrayList<Integer>(n);
        for(int i=0;i<n;i++){
            int a=sc.nextInt();
            if(a>n||v[a]) v1.add(a);
            else v[a]=true;
        }
        for(int i=1;i<n+1;i++){
            if(!v[i]) v2.add(i);
        }
        Collections.sort(v1);
        Collections.sort(v2);
        for(int i=0;i<v1.size();i++){
            if(((v1.get(i)&1)==1&&v2.get(i)>v1.get(i)/2)
            ||(!((v1.get(i)&1)==1)&&v2.get(i)>v1.get(i)/2-1)){
                System.out.println(-1);
                return;
            }
        }
        System.out.println(v1.size());
    }
    public static void main(String args[])throws java.lang.Exception{
        int t=sc.nextInt();
        while(t-->0){
            solve();
        }
    }
}
