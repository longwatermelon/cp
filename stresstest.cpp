#include <bits/stdc++.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string>
using namespace std;
#define sz(x) ((int)size(x))
#define all(x) begin(x),end(x)
#define all1(x) begin(x)+1,end(x)
template <typename T> using vec=vector<T>;

void chk_exists(string path) {
    if (!filesystem::exists(path)) {
        printf("missing file '%s'\n", path.c_str());
        exit(0);
    }
}

std::string exec(const std::string& command) {
    std::string result;
    char buffer[128];
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) return "ERROR";

    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }

    pclose(pipe);
    return result;
}

std::string exec(const std::string& command, const std::string& input, bool& segfaulted) {
    int stdout_pipe[2], stdin_pipe[2];
    
    if (pipe(stdout_pipe) == -1 || pipe(stdin_pipe) == -1) {
        perror("pipe");
        segfaulted = false;
        return "ERROR: Pipe failed";
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        segfaulted = false;
        return "ERROR: Fork failed";
    }

    if (pid == 0) {  // Child process
        // Redirect stdout and stderr to stdout_pipe
        close(stdout_pipe[0]); // Close unused read end
        dup2(stdout_pipe[1], STDOUT_FILENO);
        dup2(stdout_pipe[1], STDERR_FILENO);
        close(stdout_pipe[1]); // Close after duplication

        // Redirect stdin from stdin_pipe
        close(stdin_pipe[1]);  // Close unused write end
        dup2(stdin_pipe[0], STDIN_FILENO);
        close(stdin_pipe[0]);  // Close after duplication

        // Execute the command (with no arguments)
        execlp(command.c_str(), command.c_str(), (char*)nullptr);
        _exit(127); // Only reached if exec fails
    }

    // Parent process:
    close(stdout_pipe[1]);  // Close write end of stdout pipe
    close(stdin_pipe[0]);   // Close read end of stdin pipe

    // Send input to child's stdin
    if (!input.empty()) {
        write(stdin_pipe[1], input.c_str(), input.size());
    }
    close(stdin_pipe[1]); // Signal EOF on stdin

    // Read output from stdout_pipe
    std::string result;
    char buffer[128];
    while (true) {
        ssize_t count = read(stdout_pipe[0], buffer, sizeof(buffer) - 1);
        if (count <= 0) break;
        buffer[count] = '\0';
        result += buffer;
    }
    close(stdout_pipe[0]);

    // Wait for child process to finish
    int status;
    waitpid(pid, &status, 0);

    // Optionally, you can also check the raw exit status:
    // std::cerr << "Raw status code: " << status << std::endl;

    // Check if the output contains "segmentation fault"
    segfaulted = (result.find("Segmentation fault") != std::string::npos);

    return result;
}

int main(int argc, char **argv) {
    if (argc==1) {
        puts("require files X.cpp, X-brute.cpp, X-gen.cpp to exist. pass X to program.");
        return 1;
    }

    puts("compiling...");

    string opt=string(argv[1])+".cpp";
    chk_exists(opt);
    string brute=string(argv[1])+"-brute.cpp";
    chk_exists(brute);
    system(("g++ "+opt+" -O2 -o opt").c_str());
    system(("g++ "+brute+" -O2 -o brute").c_str());

    string tcgen=string(argv[1])+"-gen.cpp";
    chk_exists(tcgen);
    system((string("g++ ")+tcgen+" -O2 -o tcgen").c_str());

    puts("running test cases...");
    for (int i=0; i<1e5; ++i) {
        if ((i+1)%10==0) {
            printf("\rtest case %d...", i+1);
            fflush(stdout);
        }

        string tc=exec("./tcgen");
        assert(tc!="ERROR");

        bool opt_seg, brute_seg;
        string opt_out = exec("./opt", tc, opt_seg);
        string brute_out = exec("./brute", tc, brute_seg);

        if (opt_seg) {
            puts("\nOPT SEGFAULT");
        }
        if (brute_seg) {
            puts("\nBRUTE SEGFAULT");
        }

        if (opt_out != brute_out || opt_seg || brute_seg) {
            printf("\n\033[32mFOUND TEST CASE:\033[0m\n%s\nOPT OUTPUT:\n================\n%s================\nBRUTE OUTPUT:\n================\n%s================\n", tc.c_str(), opt_out.c_str(), brute_out.c_str());
            return 0;
        }
    }
    putchar('\n');

    puts("no differences detected");
}
