import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.lang.Exception;
import java.lang.Math;

public class BuildThePermutation{
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
        int a=sc.nextInt();
        int b=sc.nextInt();
        if(a+b>n-2||Math.abs(a-b)>1){
            System.out.println(-1);
            return;
        }
        int odd=1;
        int even=2;
        int cnt=0;
        int mem=1;
        if(a==b){
            int nn=n;
            if((nn&1)==1) nn--;
            int m=nn;
            while(m-->0){
                if(!((cnt&1)==1)&&odd<=nn){
                    System.out.print(odd+" ");
                    odd+=2;
                }else{
                    System.out.print(even+" ");
                    even+=2;
                }
                cnt++;
                if(cnt==nn-1-a-b&&mem==1){
                    cnt--;
                    mem=0;
                }
            }
            if((n&1)==1) System.out.print(n);
        }else if(a==b+1){
            int m=n;
            while(m-->0){
                if((cnt&1)==1){
                    System.out.print(even+" ");
                    even+=2;
                }else{
                    System.out.print(odd+" ");
                    odd+=2;
                }
                cnt++;
                if(cnt==n-1-a-b&&mem==1){
                    cnt--;
                    mem=0;
                }
            }
        }else if(b==a+1){
            int m=n;
            while(m-->0){
                if((cnt&1)==1){
                    System.out.print(odd+" ");
                    odd+=2;
                }else{
                    System.out.print(even+" ");
                    even+=2;
                }
                cnt++;
                if(cnt==a+b+1&&mem==1){
                    cnt--;
                    mem=0;
                }
            }
        }
        System.out.println("");
    }
    public static void main(String args[])throws java.lang.Exception{
        int t=sc.nextInt();
        while(t-->0){
            solve();
        }
    }
}
