import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.lang.Exception;
import java.util.ArrayList;

public class ComplexMarketAnalysis{
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
    
    static class Pair{
        int first;
        boolean second;
        public Pair(int first,boolean second){
            this.first=first;
            this.second=second;
        }
    }
    
    static FastReader sc=new FastReader();
    static int nMax=1000000;
    static boolean[] notPrime=new boolean[nMax+1];
    
    static void prec(){
        notPrime[0]=notPrime[1]=true;
        for(int i=2;i*i<=nMax;i++){
            if(!notPrime[i]){
                for(int j=i*i;j<=nMax;j+=i){
                    notPrime[j]=true;
                }
            }
        }
    }
    
    static void solve(){
        int n=sc.nextInt();
        int e=sc.nextInt();
        Pair[] a=new Pair[n];
        for(int i=0;i<n;i++){
            int x=sc.nextInt();
            a[i]=new Pair(x,false);
        }
        long sum=0;
        ArrayList<Integer> list=new ArrayList<Integer>();
        for(int i=0;i<n;i++){
            int mem=1;
            int cnt=0;
            int j=i;
            if(!a[j].second&&(!notPrime[a[j].first]||a[j].first==1)){
                while(j<n){
                    a[j].second=true;
                    if(!notPrime[a[j].first]){
                        list.add(cnt);
                        cnt=0;
                    }else if(a[j].first==1){
                        cnt++;
                    }else{
                        list.add(cnt);
                        mem=0;
                        break;
                    }
                    j+=e;
                }
                if(mem==1) list.add(cnt);
            }else continue;
            int sz=list.size();
            for(int k=0;k<sz-1;k++){
                sum+=(long)list.get(k)*(list.get(k+1)+1)+list.get(k+1);
            }
            list.clear();
        }
        System.out.println(sum);
    }
    
    public static void main(String args[])throws java.lang.Exception{
        prec();
        int t=sc.nextInt();
        while(t-->0){
            solve();
        }
    }
}
