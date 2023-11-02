#include <stdio.h>
#include <windows.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <command> [arg1] [arg2] ...\n", argv[0]);
    return 1;
  }

  // Record the start time
  LARGE_INTEGER start_time, end_time, frequency;
  QueryPerformanceFrequency(&frequency);
  QueryPerformanceCounter(&start_time);

  // Create the process
  STARTUPINFO startup_info;
  PROCESS_INFORMATION process_info;

  ZeroMemory(&startup_info, sizeof(startup_info));
  startup_info.cb = sizeof(startup_info);

  if (CreateProcess(NULL, GetCommandLine(), NULL, NULL, FALSE, 0, NULL, NULL, &startup_info, &process_info)) {
    // Wait for the child process to complete
    WaitForSingleObject(process_info.hProcess, INFINITE);

    // Record the end time
    QueryPerformanceCounter(&end_time);

    // Calculate the elapsed time
    double elapsed_time = (end_time.QuadPart - start_time.QuadPart) / (double)frequency.QuadPart;

    printf("Execution time: %.2f seconds\n", elapsed_time);

    // Close process handles
    CloseHandle(process_info.hProcess);
    CloseHandle(process_info.hThread);
  } else {
    printf("Failed to create the process. Error code: %d\n", GetLastError());
    return 1;
  }

  return 0;
}
