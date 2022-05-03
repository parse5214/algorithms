import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.lang.Exception;
import java.util.ArrayList;
import java.util.Collections;

public class BlueRedPermutation{
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
        int[] v=new int[n];
        for(int i=0;i<n;i++){
            v[i]=sc.nextInt();
        }
        String colors=sc.next();
        ArrayList<Integer> blue=new ArrayList<Integer>(n);
        ArrayList<Integer> red=new ArrayList<Integer>(n);
        for(int i=0;i<n;i++){
            if(colors.charAt(i)=='B') blue.add(v[i]);
            else red.add(v[i]);
        }
        Collections.sort(blue);
        Collections.sort(red);
        int szb=blue.size();
        int szr=red.size();
        for(int i=0;i<szb;i++){
            if(blue.get(i)<i+1){
                System.out.println("NO");
                return;
            }
        }
        for(int i=0;i<szr;i++){
            if(red.get(i)>i+szb+1){
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
    public static void main(String args[])throws java.lang.Exception{
        int t=sc.nextInt();
        while(t-->0){
            solve();
        }
    }
}
