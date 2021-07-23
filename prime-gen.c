#include <stdio.h>
#include <time.h>
#include <gmp.h>

int is_prime(const mpz_t p)
{
    // miller-rabin test
    return mpz_probab_prime_p(p, 32);
}

int main(void)
{
    mpz_t candidate;
    mpz_init(candidate);
    gmp_randstate_t generator;
    gmp_randinit_default(generator);
    gmp_randseed_ui(generator, (unsigned long int) time(NULL));
    unsigned long long i = 0;
    do {
        i++;
        mpz_urandomb(candidate, generator, 256);
    } while(!is_prime(candidate));
    mpz_out_str(stdout, 10, candidate);
    printf("took %zu tries\n", i);
    return 0;
}
