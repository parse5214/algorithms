import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.lang.Exception;

public class Banknotes{
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
    static int power(int a,int b){
        int result=1;
        while(b>0){
            if((b&1)==1) result*=a;
            a*=a;
            b/=2;
        }
        return result;
    }
    static void solve(){
        int n=sc.nextInt();
        int k=sc.nextInt();
        int[] a=new int[n];
        for(int i=0;i<n;i++) a[i]=sc.nextInt();
        if(n==1){
            System.out.println((long)(k+1)*power(10,a[0]));
            return;
        }
        int sum=power(10,a[1]-a[0])-1;
        int m=k+1;
        long num=0;
        for(int i=0;i<n-1;i++){
            if(m>sum){
                if(i==n-2){
                    num+=power(10,a[i+1])-power(10,a[i]);
                    num+=(long)(m-sum)*power(10,a[i+1]);
                    System.out.println(num);
                    return;
                }else{
                    num+=power(10,a[i+1])-power(10,a[i]);
                    sum+=power(10,a[i+2]-a[i+1])-1;
                }
            }else if(m==sum){
                num+=power(10,a[i+1])-power(10,a[i]);
                System.out.println(num);
                return;
            }else{
                sum-=power(10,a[i+1]-a[i])-1;
                num+=(long)(m-sum)*power(10,a[i]);
                System.out.println(num);
                return;
            }
        }
    }
    public static void main(String args[])throws java.lang.Exception{
        int t=sc.nextInt();
        while(t-->0){
            solve();
        }
    }
}
