#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd;
    char *data = "Hey this is monish";

    // Open a file for reading and writing, creating it if it doesn't exist
    // with 0644 permissions
    fd = open("example.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Write the data to the file
    int bytes_written = write(fd, data, strlen(data));
    if (bytes_written == -1) {
        perror("Error writing to file");
        return 1;
    }

    // Move the file position indicator to the beginning of the file
    if (lseek(fd, 0, SEEK_SET) == -1) {
        perror("Error seeking in file");
        return 1;
    }

    // Read from the file
    char buffer[strlen(data)];
    int bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("Error reading from file");
        return 1;
    }
    printf("Read from file: %s\n", buffer);

    // Close the file
    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    // Remove the file
    if (unlink("example.txt") == -1) {
        perror("Error removing file");
        return 1;
    }

    return 0;
}

