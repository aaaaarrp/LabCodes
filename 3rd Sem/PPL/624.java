
/**  Array subscript check in java */ 

import java.util.*;

class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String string, sub;
    System.out.println("Enter the string");
    string = sc.nextLine();
    System.out.println("Enter the substring");
    sub = sc.nextLine();
    int L, l;
    L = string.length();
    l = sub.length();
    for (int i = 0; i <= (L - l); i++) {
      if (sub.equals(string.substring(i, i + l))) {
        System.out.println("The string contains the substring");
      }
    }
  }
}
