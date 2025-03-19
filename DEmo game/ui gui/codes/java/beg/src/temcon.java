
// write a program that take input temparature as fernehit and convert it to celsius and print it
// now write a code that  the user have option to choose the input either in celius or farenhit


import java.util.Scanner;

public class temcon {
    public static void main(String[] args ){
        Scanner scan = new Scanner(System.in);
        System.out.println("if you want to input celcius press c or else press f for farenhit : ");
        char c = scan.next().charAt(0);
        if(c=='f'){
            System.out.println("enter the temparature in farenhit :");
        float  f = scan.nextFloat();


        float  l =  (float)5/9 * (f-32);
        System.out.println("the converted temparature in celcius is : "+l);}
        else{
            System.out.println("enter the temparature in clecius :");
            float j = scan.nextFloat();
            float k = ((float)9/5*j)+32;
            System.out.println("the converted temparature in farenhit is :"+k);
        }




    }
}





