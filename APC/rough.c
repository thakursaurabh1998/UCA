#include <stdio.h>
#include <math.h>

// int getByte(int x, int n){
//     return ((x>>8*n)&255);
// }

// int main(){
//     printf("%d",getByte(512,1));
//     printf("\n%d",~1);
//     return 0;
// }

// int reverse(int n)
// {
//     int rev = 0;
//     int num = n;
//     while (num)
//     {
//         rev = rev * 10 + num % 10;
//         num /= 10;
//     }
//     if (rev == n)
//         return 1;
//     else
//         return 0;
// }

// int main()
// {
//     int n, num;
//     scanf("%d", &n);
//     while (n--)
//     {
//         scanf("%d", &num);
//         if (reverse(num))
//             printf("Equal");
//         else
//             printf("Not Equal");
//     }
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//     return 0;
// }

// int prime(int n){
//   int i;
//   for(i=2;i<n;i++)
//       if(n%i==0)
//         return 0;
//   return 1;
// }

// int main()
// {
// 	int i,n,sum=0;
// 	scanf("%d",&n);
//   	for(i=2;i<=n;i++)
//       if(prime(i)) printf("%d",i);
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//     return 0;
// }

int bang(int x)
{
}

int main()
{
  int a = ~0 + 1;
  printf("%d", a);
  return 0;
}