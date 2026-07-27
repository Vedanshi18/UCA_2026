#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
int main(int argc, char *argv[]) {
    struct stat file;

    // Check command-line arguments
    if(argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]); // Prints  Usage: ./stat <file_path>
        return 1; //Exit
    }

    // Get file information
    if (stat(argv[1], &file) == -1)
    {
        printf("Error: Cannot access file.\n");
        return 1;
    }

    printf("=== File Attributes for: %s ===\n", argv[1]);
    
    // File Type
    if (S_ISREG(file.st_mode))
        printf("File Type:            Regular File\n");
    else if (S_ISDIR(file.st_mode))
        printf("File Type:            Directory\n");
    else
        printf("File Type:            Other\n");

    // Permissions
    printf("Permissions:          %04o\n", file.st_mode & 0777);
    printf("File Size:            %ld bytes\n", file.st_size);
    printf("Hard Links Count:     %ld\n", file.st_nlink);
    printf("Owner (UID):          %d\n", file.st_uid);
    printf("Group (GID):          %d\n", file.st_gid);

    printf("Last Access Time:     %s", ctime(&file.st_atime));
    printf("Last Modification:    %s", ctime(&file.st_mtime));
    printf("Status Change Time:   %s", ctime(&file.st_ctime));
    
}