// c99
// prac sys call + implement OS basic functionality

// compile using make [make file + instructions]
// test with GCC compiler [in linux]

// submit gradescope [] put files in there FILE NAME


// functions

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    // Check for the correct number of arguments
    if (argc != 3)
    {
        printf("Insufficient parameters passed.\n");
        return 1;
    }

    // Open the input file
    int input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1)
    {
        perror("Error opening input file");
        return 1;
    }

    // Open/Create the output file with write permissions
    int output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1)
    {
        perror("Error opening/creating output file");
        close(input_fd);
        return 1;
    }

    // Buffer to store file contents
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    // Read from input and write to output
    while ((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0)
    {
        bytes_written = write(output_fd, buffer, bytes_read);
        if (bytes_written != bytes_read)
        {
            perror("Error writing to output file");
            close(input_fd);
            close(output_fd);
            return 1;
        }
    }

    if (bytes_read == -1)
    {
        perror("Error reading input file");
    }
    else
    {
        printf("The contents of file %s have been successfully copied into the %s file.\n", argv[1], argv[2]);
    }

    close(input_fd);
    close(output_fd);

    return 0;
}
