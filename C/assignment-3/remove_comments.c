#include <stdio.h>
int main() {
    FILE *fp;  // Creates a file pointer
    int ch, next;
    fp = fopen("input.c", "r"); // Open file input.c in read mode
    //fp points to beginning of the file
    if (fp == NULL) {
        printf("Cannot open file.\n"); // Failed to open
        return 1;
    }
    // Read one character at a time
    // fgetc(fp) returns a character until file ends
    while ((ch = fgetc(fp)) != EOF) {

        // String (first quote found)
        if (ch == '"') {
            putchar(ch); // Prints the character (quote)

            //Read everything until another quote found
            while ((ch = fgetc(fp)) != EOF) {
                putchar(ch);

                // Escape sequence :
                // If string is "He said \"Hi\""
                // Inside file, \" means don't end the string
                if (ch == '\\')  //To check '\'
                {
                    ch = fgetc(fp); //Skip this character, read next if '\' found ie escape seq
                    if (ch != EOF)
                        putchar(ch);
                }
                else if (ch == '"') //Last quote found
                    break;
            }
        }
        // Character constant 
        // Like in char c = 'a'
        else if (ch == '\'') { // Found ' 

            putchar(ch);

            while ((ch = fgetc(fp)) != EOF) {
                putchar(ch);

                // Escape character '\n'
                if (ch == '\\') {
                    ch = fgetc(fp);
                    if (ch != EOF)
                        putchar(ch);
                }
                else if (ch == '\'') // Another quote
                    break;
            }
        }
        // Slash
        else if (ch == '/') {
            // '/' could mean / or // or /*
            next = fgetc(fp); // Read one more char
            
            //Single line comment
            if ( next == '/') {
                // Skip everything
                while ((ch = fgetc(fp)) != EOF && ch != '\n'); 
                if (ch == '\n')
                    putchar('\n');
            }
            //Multi line comment '/*'
            else if (next == '*') {
                int prev = 0;
                while ((ch = fgetc(fp)) != EOF)
                {
                    if (prev == '*' && ch == '/')
                        break;
                    prev = ch;
                }
            }
            // Slash like in a/b
            else {
                putchar(ch);
                //If next char exists ie /b
                //We already read b, but we dont wanna lose it
                if (next != EOF)
                    ungetc(next, fp); //Put it back into the file
            }
        }
        //Normal characters
        else {
            putchar(ch);
        }
    }
    fclose(fp);
    return 0;
}