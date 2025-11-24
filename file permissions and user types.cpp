#include <stdio.h>

int main() {
    printf("Linux File Permission Illustration\n\n");
    printf("Format: drwxr-xr-- (d=directory, - = file)\n");
    printf("Triplets: owner | group | others\n");
    printf("r = read (4), w = write (2), x = execute (1)\n");
    printf("Numeric example: 754 => owner=7(rwx), group=5(r-x), others=4(r--)\n\n");

    printf("Examples:\n");
    printf("1) -rw-r--r-- (644) : owner can read/write, group and others read only\n");
    printf("2) drwxr-xr-x (755): directory owner rwx, group/others r-x\n");
    printf("3) -rwsr-xr-x : setuid bit set (s in owner execute position)\n\n");

    printf("User types:\n");
    printf("- Owner: the user who owns the file (user id)\n");
    printf("- Group: users in the file's group share the group permissions\n");
    printf("- Others: all other users\n\n");

    printf("How to check in shell (example):\n");
    printf("ls -l filename  -> shows permission string and owner/group\n");
    printf("chmod 754 filename -> set numeric permissions\n");
    printf("chown user:group filename -> change owner and group\n");

    return 0;
}
