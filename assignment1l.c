#include<stdio.h>
#include<string.h>
#include<windows.h>

void serchFile(char *dir_name, char *file_name){

    WIN32_FIND_DATA find_data;
    HANDLE find_handle;
    char path[MAX_PATH];

    snprintf(path, sizeof(path), "%s\\*", dir_name);
    find_handle = FindFirstFile(path, &find_data);
    if(find_handle!=INVALID_HANDLE_VALUE){
        do{
            if()
        }
    }
}

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        printf("Usage: %s <directory> %s <filename> \n", argv[1], argv[2]);
        return -1;
    }
    searchFile(argv[1],argv[2]);
    return 0;
}