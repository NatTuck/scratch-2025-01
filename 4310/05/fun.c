
int
main()
{
  int xs[] = {1, 2, 3, 4};

  printf("%d\n", xs[2]); // (xs, 2, 4) 
  printf("%d\n", 1[xs]); // (2, xs, 4)

  return 0;
}
