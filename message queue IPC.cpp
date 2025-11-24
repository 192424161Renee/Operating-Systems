#include <windows.h>
#include <stdio.h>
int main() {
    HANDLE pipe;
    char buffer[100];
    DWORD bytesRead, bytesWritten;
    pipe = CreateNamedPipe(
        TEXT("\\\\.\\pipe\\MyPipe"),
        PIPE_ACCESS_DUPLEX,
        PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,
        1,
        1024,
        1024,
        0,
        NULL);
    if (pipe == INVALID_HANDLE_VALUE) {
        printf("Error creating pipe.\n");
        return 1;
    }
    printf("Waiting for client...\n");
    ConnectNamedPipe(pipe, NULL);
    char message[] = "Hello from Parent via Message Queue!";
    WriteFile(pipe, message, sizeof(message), &bytesWritten, NULL);
    printf("Parent sent: %s\n", message);
    ReadFile(pipe, buffer, sizeof(buffer), &bytesRead, NULL);
    buffer[bytesRead] = '\0';
    printf("Child received: %s\n", buffer);
    CloseHandle(pipe);
    return 0;
}