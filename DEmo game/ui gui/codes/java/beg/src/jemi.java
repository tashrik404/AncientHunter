import java.util.Scanner;;
public class jemi {
    // find a factorial of a number and return the value
    public static long print( long a ){
        long i,pro=1;
        for(i=a;i>=1;i--){
            pro=pro*i;

        }

        return pro;

    }
    public static void main(String[] args) {
        for{
        Scanner scan = new Scanner(System.in);
        long a = scan.nextInt();;
        if(a<0 || a==0){
            System.out.println("program is exiting");
            break;
        }


        System.out.println("the factorial of the number is "+ print(a));}





        }
    }

