int binaryToDecimal(int n)
{
  int sum = 0, i;
  int k = 0;
  while (n)
  {
    i = n % 10;
    sum += pow(2, k) * i;
    k++;
    n /= 10;
  }
  //   printf("%d\n",sum);
  return sum;
}

int decimalToBinary(int n)
{
  int a = 0x40000000;
  long long bin = 0;
  while (a)
  {
    bin *= 10;
    if (n & a)
      bin += 1;
    a >>= 1;
  }
  return bin;
}