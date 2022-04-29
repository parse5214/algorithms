import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.lang.Exception;

public class PalindromesColoring{
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
        String str=sc.nextLine();
        int[] fq=new int[26];
        for(int i=0;i<n;i++){
            fq[str.charAt(i)-'a']++;
        }
        int nOdds=0;
        for(int i=0;i<26;i++){
            if((fq[i]&1)==1) nOdds++;
        }
        int nAv=n-nOdds;
        nAv/=2;
        int result=0;
        if(nAv>=k){
            int res=nAv%k;
            int quot=nAv/k;
            if(nOdds+res*2>=k){
                result=2*quot+1;
            }else{
                result=2*quot;
            }
        }else{
            result=1;
        }
        System.out.println(result); 
    }
    public static void main(String args[])throws java.lang.Exception{
        int t=sc.nextInt();
        while(t-->0){
            solve();
        }
    }
}
