//Implicit type conversion in java

import java.util.*;

class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    double res;
    int c, a;
    System.out.println("Enter your integer 1");
    c = sc.nextInt();
    System.out.println("Enter your integer 2");
    a = sc.nextInt();
    res = (a * c) + (a + c);
    System.out.println("The result is " + res);
  }
}
