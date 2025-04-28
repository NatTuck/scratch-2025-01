// Asymptotic complexity
//
// How does the number of operations nesssiary to complete
// a function (or program) grow as the input size increases.

public class CatDemo {
  record Cat(String name, int age) {}

  public static void main1(String[] args) {
    Cat[] cats = { 
      new Cat("Spot", 7), new Cat("Michael", 20),
      new Cat("Peter", 15), new Cat("Bob", 2),
      new Cat("Sphinx", 2000)
    };

    int nn = cats.length;
    System.out.println(firstName(cats));
  }

  // This only does two operations no matter
  // how big the array.
  //  Cats | Operations
  //  -----+-----------
  //   1   |   2
  //   20  |   2
  //   900 |   2
  //
  //  Grows at O(1)
  static String firstName(Cat[] xs) {
    return xs[0].name();
  }

  // Does a constant number of operations per
  // cat in the list.
  //
  //  Cats  | Operations
  // -------+-------------
  //   1    |  3
  //   10   |  30
  //   100  |  300
  //   n    |  3*n
  //
  // Grows at O(n)
  /*
  static int totalCatAge(Cat[] xs) {
    int total = 0;
    for (Cat cc : xs) {
      total += cc.age();
    }
    return cc;
  }
  */

  // Count older cats.
  //
  // Grows at a rate of O(n^2)
  static int[] olderCatsEach(Cat[] xs) {
    int[] ys = new int[xs.length];
    for (int ii = 0; ii < xs.length; ++ii) {
      int older = 0;
      for (Cat cc : xs) {
        if (cc.age() > xs[ii].age()) {
          older++;
        }
      }
      ys[ii] = older;
    }
    return ys;
  }

  static int olderOps(int n) {
    int ops = 0;
    for (int ii = 0; ii < n; ++ii) {
      int older = 0;
      for (int jj = 0; jj < n; ++jj) {
        ops += 2;
      }
      ops += 3;
    }
    return ops;
  }

  public static void main2(String[] args) {
    System.out.println("n\tops(n)\tn^2\t3*n^2");
    for (int n = 1; n < 100; ++n) {
      System.out.println("" + n + "\t" + olderOps(n) + "\t" + (n*n) + "\t" + (3*n*n));
    }
  }
 
  public static int pow(int x, int y) {
    int z = x;
    for (int ii = 0; ii < y; ++ii) {
      z = z * x;
    }
    return z;
  }

  public static void main(String[] args) {
    for (int ii = 0; ii < 100; ++ii) {
      System.out.println("2 to the i = " + pow(2, ii));
    }
  }

}
