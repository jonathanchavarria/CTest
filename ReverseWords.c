#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>

//XX
static char* append_strings(char* old, const char* new)
{
    // find the size of the string to allocate   
    const size_t len = strlen(old) + strlen(new) + 1 + 1; // + 1 (space between words) + 1 (null terminator)

    // allocate a pointer to the new string
    char* out = malloc(len);
    assert(out != NULL);

    // concat both strings in reverse order and return
    snprintf(out, len, "%s %s", new, old);

    return out;
}

// TODO: implement this function
static void ReverseWords(char* string)
{   
    char* word = strtok(string, " ");
    char* reversed_string = strdup("");
    assert(reversed_string != NULL);

    // Loop through words in string
    while (word != NULL) {

        char* temp = append_strings(reversed_string, word);
        free(reversed_string); 

        reversed_string = temp;
        word = strtok(NULL, " ");
    }

    snprintf(string, strlen(reversed_string), "%s", reversed_string);
    free(reversed_string);
}

int main()
{
    /*
    Implement the function ReverseWords() which reverses the words in a sentence.

    input: a character string consisting of words separated by whitespace
    output: the same string, with the words reversed

    Example:
    (input) "The quick brown fox jumps over the lazy dog"
    (output) "dog lazy the over jumps fox brown quick The"


    Note: when implementing, please consider other inputs other than the example string provided.
    */
    char string[] = "The quick brown fox jumps over the lazy dog";
    printf("Original String: %s\n", string);

    ReverseWords(string);
    printf("Reversed String: %s\n\n\n", string);

    printf("\nPress any key to continue...");
    char c;
    scanf("%c", &c);
}
