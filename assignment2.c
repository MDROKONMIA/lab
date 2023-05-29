#include <stdio.h>
#include <string.h>
#include <windows.h>

void deleteDirectory(char *dirname)
{
    WIN32_FIND_DATA find_data;
    HANDLE find_handle;
    char path[MAX_PATH];

    snprintf(path, sizeof(path), "%s\\*", dirname);
    find_handle = FindFirstFile(path, &find_data);

    if (find_handle != INVALID_HANDLE_VALUE)
    {
        do
        {
            if (strcmp(find_data.cFileName, ".") == 0 || strcmp(find_data.cFileName, "..") == 0)
            {
                continue;
            }

            snprintf(path, sizeof(path), "%s\\%s", dirname, find_data.cFileName);

            if (find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                deleteDirectory(path);
            }
            else
            {
                DeleteFile(path);
            }
        } while (FindNextFile(find_handle, &find_data) != 0);

        FindClose(find_handle);
    }

    RemoveDirectory(dirname);
}

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    deleteDirectory(argv[1]);
    return 0;
}