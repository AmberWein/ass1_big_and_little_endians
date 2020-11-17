// 208783522 Amber Weiner

/**
 * this function checks if the system works with little endian or big endian
 * @return 1 if it is big endian and 0 otherwise.
 */
int is_big_endian() {
    long number_for_testing = 1;
    char *chars_of_the_number = (char*)&number_for_testing;
    // check if it is little endian
    if (*chars_of_the_number == 1)
        return 0;
    else
        // it is big endian
        return 1;
}

/**
 * this function returns a new word (assumed to be long) made by two parts:
 * 1. half of the bites in y starting from the LSB bit
 * 2. rest of the bytes in x
 * @param x unsigned long number
 * @param y unsigned long number
 * @return new unsigned long number (word) which combine x and y.
 */
unsigned long merge_bytes(unsigned long x, unsigned long int y) {
    // shift right, moves on byte right (last byte was removed)
    x = x >> 32u;
    // put '00' on the last byte
    x = x << 32u;
    // take the first byte from y
    y = y & 0xFFFFFFFFu;
    return y | x;
}

/**
 * this function replaces value at i-th (index) place with value band put it on x
 * @param x unsigned long - a word
 * @param b unsigned char
 * @param i - an index in x
 * @return x after replacement.
 */
unsigned long put_byte(unsigned long x, unsigned char b, int i) {
    // points to the beginning of the word
    char *starting_point = (char*)&x;
    /** check if the system works with little endian or big endian
     * and update x accordingly */
    if(is_big_endian()) {
        // moves the pointer to the i-th byte
        starting_point += i;
    } else {
        // little endian
        int length = sizeof(x);
        // moves the pointer to the i-th place
        starting_point += (length - 1) - i;
    }
    // change the value to b
    *starting_point = (char)b;
    return x;
}

