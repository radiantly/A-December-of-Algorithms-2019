#include<stdio.h>
#include<math.h>
int isPrime(int num) {
    if(num == 2) return 1;
    if(num % 2 == 0) return 0;
    for(int i = 3; i <= sqrt(num); i+=2) 
        if(num % i == 0) return 0;
    return 1;
}

int main() {
    int n, first = 2, last = 3, count = 0;

    printf("Enter the value for (n): ");
    scanf("%d", &n);

    printf("Generated Fibonacci Prime Number Generation upto (%d):\n", n);
    while(count < n) {
        if(isPrime(first)) {
            printf("%d ", first);
            ++count;
        }
        last = last + first;
        first = last - first;
    }
        
   return 0;
} 
