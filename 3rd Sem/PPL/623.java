
/** Unexpected results due to non-short-circuit evaluations in java */ 

import java.util.*;

class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int count = 0;
    int a = 5;
    if ((count > 0) && (a / count > 1)) {
      System.out.println("If part executed");
    } else {
      System.out.println("Else part executed");
    }
  }
}
