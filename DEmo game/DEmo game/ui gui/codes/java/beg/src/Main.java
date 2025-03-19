import java.util.Scanner;

// right a program to find a table of any number upto n
public class Main{

    public static void main(String[] args){

        int i,n,k;
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        for(i=1;i<=10;i++){
            k=n*i;
            System.out.println(n+"x"+i+"="+k);

        }

    }
}