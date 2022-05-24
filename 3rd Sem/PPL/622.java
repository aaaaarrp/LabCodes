/**  Declaring, printing and finding the length of a string in java */

import java.util.*;

class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int l;
    String name;
    System.out.println("Enter the string");
    name = sc.nextLine();
    l = name.length();
    System.out.println("The string length is " + l);
  }
}
