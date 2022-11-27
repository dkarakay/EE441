// function returning the nth prime number


bool prime_num(int num){
    bool prime = true;
    if(num < 2)
        return false;
    for (int i = 2; i<num; i++){
        // check the mods for the increasing values
        if(num % i == 0)
            prime = false;
    }
    return prime;
}

int nth_prime(int n){
    int counter = 0;
    for(int i=0; counter <= n; i++){
        if(prime_num(i)){
            // if prime number, increase the counter by one
            counter++;
            if(counter == n)
                /* return the n'th prime number when the counter is reached
                   the desired one */
                return i;
        }
    }
}

