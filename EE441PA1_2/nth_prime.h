using namespace std;

// *********  nth prime number Function for Part 2.3  *********

// PrimeOrNot is the "Helper" function

int PrimeOrNot(int number)
{
    // Checking if the number is 0 or 1
    if (number <= 1)
        return 0;
    // Checking if the number is 2 or 3
    if (number == 2 || number == 3)
        return 1;

    // if the number can be divided by 2 or 3, it is NOT a Prime number
    if (number % 2 == 0 || number % 3 == 0)
        return 0;

    // Every prime number other than 2 or 3 can be represented
    // in form of (6*k + 1) or (6*k - 1) while k is some integer
    for (int i = 5; i * i <= number; i = i + 6)
        if (number % i == 0 || number % (i + 2) == 0)
            return 0;

    return 1;
}

int nth_Prime(int counter)
{
    // starting from 2 since it is the first prime number
    int number = 2;

    while(counter)
    {
        if(PrimeOrNot(number))
            // a prime number is found decrease n until it reaches 0
            // and the loop terminates
            counter--;

        //incrementing i to check the next integer
        number++;
    }
    // since the number is incremented within the loop no matter what
    // it must be decreased by one to obtain the nth prime number
    number -= 1;

    return number;
}

