import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.lang.Exception;

public class WrongAddition{
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
        String str1=sc.next();
        String str2=sc.next();
        String str3="";
        int sz1=str1.length();
        int sz2=str2.length();
        int j=sz1-1;
        for(int i=sz2-1;i>=0;i--){
            char nums;
            if(j>=0) nums=str1.charAt(j);
            else nums='0';
            if(str2.charAt(i)>=nums){
                str3=String.valueOf(str2.charAt(i)-nums)+str3;
                j--;
            }else if(i!=0){
                int num1=str2.charAt(i)-'0';
                int num2=str2.charAt(i-1)-'0';
                int num3=num2*10+num1;
                int num4=nums-'0';
                int num5=num3-num4;
                if(num5>9||num5<0){
                    System.out.println(-1);
                    return;
                }
                str3=String.valueOf(num5)+str3;
                i--;
                j--;
            }else{
                System.out.println(-1);
                return;
            }
        }
        if(j>-1){
            System.out.println(-1);
            return;
        }
        int cnt=0;
        for(int i=0;i<str3.length();i++){
            char c=str3.charAt(i);
            if(c=='0') cnt++;
            else break;
        }
        str3=str3.substring(cnt);
        System.out.println(str3);
    }
    public static void main(String args[])throws java.lang.Exception{
        int t=sc.nextInt();
        while(t-->0){
            solve();
        }
    }
}
