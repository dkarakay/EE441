// recursive function taking a null-terminated string and printing it backwards

/* call by address,
   the function takes array's name which is a pointer */
void print_backwards(char const * string){
    // finish the operation when the null is reached
    if (*string  != '\0'){
        // call the function recursively to print from the end
        print_backwards(string + 1);
        // print the current current
        cout << *string;
    }
}

