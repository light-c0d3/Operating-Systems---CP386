// Question 1

// operation on files / directories/ associated sys functions

#include <stdio.h>    // i/o operations
#include <sys/stat.h>  // file system status + activity
#include <fcntl.h>
#include <unistd.h> // for write and close system calls


// create a directory with the goven name and permisson
void create_directory(const char *dir_name, mode_t mode){    
    if (mkdir(dir_name, mode) == -1) {
        printf("Failed to create the directory. Returned -1");
    } else {
        printf("Directory created!");
    }
}

// create a file with given name + write "Operating System is Fun!!" to file
void create_write_file(const char *file_name, const char *content) {
    int file_created = creat(file_name, 0644); // 0644 for creating file instead of O_CREAT
    
    if (file_created == -1) {
        printf("Could not create the file");
    } else {
        printf("File created"); 
        
        // open file + write
        int len_file = sizeof("Operating System is Fun!!") - 1;
        write(file_created, content, len_file);
        close(file_created);
    }
}

// 
void read_proc_mem_info_to_file(const char *file_name){
    
}

//
void directory_listing(const char *start_dir) {
   
}

//
void remove_directory(const char *dir_name){
    
}


int main() {

    printf("x");




}