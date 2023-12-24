#include <stdio.h>

#define NUM_SYMBOLS 7
#define MAX_ROMAN_NUMBER_LENGTH 16  // the longest roman number has 15 digits + the null character

#define DEBUG 1

#ifdef DEBUG

    #include <string.h>
    #include <assert.h>

    #define NUM_DIGITS  30

    char roman_digits[NUM_DIGITS][5] = {
        "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", // 8
        "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", // 17
        "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", // 26
        "M", "MM", "MMM"                                        // 30
    };

    /// TESTs if all the main roman digits are well converted
    _Bool test_digit_conversion(void);


    /** TESTs if all the possible roman number are really converted correctly.
     *  Integers are converted into roman numbers by the int2roman function
     *  Then the roman number is converted back to an unsigned integer via the roman2int function
     *  If all the integers obtained are equals to the integers before conversion then this function will return true
     *  Otherwise returns false
     */
    _Bool test_all_roman_number_conv(void);


    /// TESTs all possible bad syntaxes. **All bad syntaxes data are not guaranteed yet**
    _Bool test_bad_syntax (void);


    /// Converts an unsigned integer into a roman number string that will be wrotten inside dest
    void int2roman(char* dest, unsigned int n);

#endif // DEBUG

const enum {
    I = 0,
    V,
    X,
    L,
    C,
    D,
    M
} ROMAN_SYMBOLS;

/// The list of all the characters used to write a roman number
char ALPHABET[NUM_SYMBOLS] = { 'I','V', 'X', 'L', 'C', 'D', 'M'};

///my basic toupper function
char to_upper(char c)
{
    #define ASCII_JMP_CASE 32

    if (c >= 'a' && c <= 'z')
        return c - ASCII_JMP_CASE;
    else
        return c;
}


/// my basic function search of the first occurence of a character in a string. Returns -1 if the character is not inside the string
int strpos(char* str, size_t len, char c)
{
    for (size_t i = 0; i < len; i++)
        if (c == str[i])
            return i;

    return -1;
}


/// Checks if the characters of the string are all roman numbers
_Bool is_lexical_correct (char* str);

/// Checks if the roman number is well constructed
_Bool is_syntax_correct (char* str);

/// Converts a roman number into an unsigned integer
unsigned int roman2int(char* str); // convert a roman number string into an unsigned number (roman numbers do not know negative values)

/// contains the program's logic
void run(char *str);


int main (void) {

    //#undef DEBUG

    char roman[MAX_ROMAN_NUMBER_LENGTH] = { '\0' };

    printf("ROMAN TO INTEGER CONVERTER\n");

    #ifdef DEBUG
        assert(test_digit_conversion());
        assert(test_all_roman_number_conv());
        assert(test_bad_syntax());
    #endif // DEBUG

    run(roman);

    printf("\nThanks for using this program !\n");

    return 0;
}


_Bool is_lexical_correct (char* str)
{
    size_t j;

    for (size_t i = 0; str[i] != '\0'; i++) {
        for (j = 0; j < NUM_SYMBOLS; j++) {
            if (to_upper(str[i]) == ALPHABET[j]) {
                break;
            }
        }

        if (j == NUM_SYMBOLS)
            return 0;
    }

    return 1;
}


/// TODO: some incorrect syntaxes are still valid
_Bool is_syntax_correct (char* str)
{
    size_t i, j;
    size_t bad_sym_idx_start, alpha_idx;
    char substractor;

    for (i = 0; str[i+1] != '\0'; i++) {
        switch(str[i]) {
        case 'i':
        case 'I':
            bad_sym_idx_start = L;
            break;

        case 'v':
        case 'V':
            substractor = 'I';
            bad_sym_idx_start = X;
            break;

        case 'x':
        case 'X':
            substractor = 'I';
            bad_sym_idx_start = D;
            break;

        case 'l':
        case 'L':
            substractor = 'X';
            bad_sym_idx_start = C;
            break;

        case 'c':
        case 'C':
            substractor = 'L';
            continue;

        case 'd':
        case 'D':
            substractor = 'C';
            bad_sym_idx_start = M;
            break;

        case 'm':
        case 'M':
            substractor = 'C';
            continue;
        }

//        char upper_next = to_upper(str[i+1]);

        //---
//        for (j = bad_sym_idx_start; j < NUM_SYMBOLS; j++) {
//            if (upper_next == ALPHABET[j])
//                return 0;
//        }
        //---

        int pos_char =  strpos(ALPHABET, NUM_SYMBOLS, to_upper(str[i]));
        int pos_prev_char = (i == 0) ? -1 : strpos(ALPHABET, NUM_SYMBOLS, to_upper(str[i-1]));
        int pos_next_char = strpos(ALPHABET, NUM_SYMBOLS, to_upper(str[i+1]));

        printf(
            "\nbad_sym_start=%d\
            \nc=%c\
            \n[i-1]=%d\
            \n[i]=%d\
            \n[i+1]=%d\
            \n",
        bad_sym_idx_start, str[i], pos_prev_char, pos_char, pos_next_char);

        if (pos_next_char >= bad_sym_idx_start) {
            return 0;
        }

        if (i > 0) {
            if (pos_prev_char <= pos_char && pos_char > pos_next_char) {
                return 0;
            }

            if (pos_prev_char >= pos_char && pos_char < pos_next_char) {
                return 0;
            }
        }

//        if (i > 0
//            && str[i] != 'I'
//            && str[i] != 'i'
//            && (str[i] == str[i+1]
//                || upper_next == substractor)
//            && to_upper(str[i-1]) == substractor
//        ) {
//            return 0;
//        }
    }

    return 1;
}


void int2roman(char* dest, unsigned int n)
{
    assert(n > 0 && n < 1000000);

    unsigned short level[4] = {0}; // 1: units, 2: tens, 3: hundreds, 4: thousands

    level[0] = n % 10;
    n /= 10;
    level[1] = n % 10;
    n /= 10;
    level[2] = n % 10;
    n /= 10;
    level[3] = n % 10;

    if (level[3] != 0)
        strcat(dest, roman_digits[level[3] + 26]);

    if (level[2] != 0)
        strcat(dest, roman_digits[level[2] + 17]);

    if (level[1] != 0)
        strcat(dest, roman_digits[level[1] + 8]);

    if (level[0] != 0)
        strcat(dest, roman_digits[level[0] - 1]);
}


unsigned int roman2int(char* str)
{
    unsigned int answer = 0;

    for (size_t i = 0; str[i] != '\0'; i++) {
        switch (str[i]) {
        case 'i':
        case 'I':
            switch (str[i+1]) {
            case 'v':
            case 'V':
                answer += 4;
                i++;
                break;
            case 'x':
            case 'X':
                answer += 9;
                i++;
                break;
            default:
                answer += 1;
            }
            break;

        case 'v':
        case 'V':
            answer += 5;
            break;

        case 'x':
        case 'X':
            switch (str[i+1]) {
            case 'l':
            case 'L':
                answer += 40;
                i++;
                break;
            case 'c':
            case 'C':
                answer += 90;
                i++;
                break;
            default:
                answer += 10;
            }
            break;

        case 'l':
        case 'L':
            answer += 50;
            break;

        case 'c':
        case 'C':
            switch(str[i+1]) {
            case 'd':
            case 'D':
                answer += 400;
                i++;
                break;
            case 'm':
            case 'M':
                answer += 900;
                i++;
                 break;
            default:
                answer += 100;
            }
            break;

        case 'd':
        case 'D':
            answer += 500;
            break;

        case 'm':
        case 'M':
            answer += 1000;
            break;

        default:
            printf("Default case reached.\n");
        }
    }

    return answer;
}


void run (char* roman) {
    while (1) {
        printf("\n** Press `n` or `N` to exit ** \n");

        while(1) {
            printf("\nWrite a roman number: ");
            scanf("%s", roman);

            if (roman[0] == 'n' || roman[0] == 'N')
                return;

            if (is_lexical_correct(roman)) {
                if (is_syntax_correct(roman))
                    printf("%s is %u in decimal\n", roman, roman2int(roman));
                else
                    printf("This number is not well constructed.");
            }
            else { continue; }

        }
    }
}


_Bool test_digit_conversion(void) {

    unsigned int real_value, converted;

    char* digit;

    for (size_t i = 0; i < NUM_DIGITS; i++) {
        digit = roman_digits[i];
        if (!is_lexical_correct(digit)) {
            printf("\ntest_digits() failed at lexical verification on %s", digit);
            return 0;
        }

        if (!is_syntax_correct(digit)) {
            printf("\ntest_digits() failed at syntax verification on %s", digit);
            return 0;
        }

        real_value = (i <= 8) ? i+1 :                   // If we are in the units
                        (i <= 17) ? (i-8) * 10 :        // If we are going through tens
                            (i <= 26) ? (i-17) * 100 :  // If we are going through hundreds
                                (i-26) * 1000;          // If we are going through thousands

        converted = roman2int(digit);

        //printf("\n%5s -> %5u", digit, converted);

        if (converted != real_value) {
            printf("\ntest_digits() failed at %s == %u where it should be %s == %u",
                digit,
                real_value,
                digit,
                converted
            );

            return 0;
        }
    }

    printf("\ntest_digits() ended successfully.");
    return 1;
}


_Bool test_all_roman_number_conv (void)
{
    #define NB_NUMBERS 3000

    unsigned int converted;

    for (unsigned int n = 1; n < NB_NUMBERS; n++) {
        char roman[MAX_ROMAN_NUMBER_LENGTH] = {'\0'};

        int2roman(roman, n);

        converted = roman2int(roman);

       if (n != converted) {
            printf("%u == %s == %u\n", n, roman, converted);
            return 0;
       }
    }

    printf("\ntest_all_roman_number_conv() ended successfully.\n");
    return 1;
}

_Bool test_bad_syntax (void) {
// SYMBOLS:  'I','V', 'X', 'L', 'C', 'D', 'M',
    char bad_syntax_patterns[][10] = { // 10 is magic number (v_V)
        "IL", "IC", "ID", "IM",
        "VX", "VL", "VC", "VD", "VM",
        "XD", "XM",
        "LC", "LD", "LM",
        "IXI", "IVI"
    };

    for (size_t i = 0; i < sizeof bad_syntax_patterns / sizeof bad_syntax_patterns[0]; i++) {
        if (is_syntax_correct(bad_syntax_patterns[i])) {
            printf("\nBad syntax %s has not been taken care of.\n", bad_syntax_patterns[i]);
            return 0;
        }
    }

    printf("\ntest_bad_syntax() ended successfully.\n");
    return 1;
}
