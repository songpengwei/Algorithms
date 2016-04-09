#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

void select_prime(int n) {
    bool check[n];
    memset(check, false, sizeof(check));
    int prime[n];

    int cnt = 0;

    // use prime[j] to product every number:
    // like the smallest prime:2, it have the chance
    // to multiply every i.
    for (int i = 2; i < n; ++i) {
        if (!check[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt; ++j) {
            if (i * prime[j] > n) break;
            check[i*prime[j]] = true;

            // the number to be eliminated this step by i will
            // be eliminated by primes[j] in latter step.
            if (i % prime[j] == 0) break;
        }
    }
}
int main()
{
    int cnt = 0;
    int N = 0xFFFF;
    bool check[N];
    int prime[N];
    memset(check, false, sizeof(check));

    for (int i = 2; i < N; ++i) {
        if (!check[i])
            prime[cnt++] = i;
        for (int j = i+i; j < N; j += i) {
            check[j] = true;
        }
    }

    printf("There are %d prime in the range [0, %d].\n", cnt, N);
    for (int i = 0; i < cnt; ++i) printf("%d ", prime[i]);
    cout << endl;

    return 0;
}
