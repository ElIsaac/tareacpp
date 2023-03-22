#pragma once
#ifndef REQUIRE_H
#define REQUIRE_H
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>

inline void require(bool requirement,
    const std::string& msg = "Requirementfailed") {
    using namespace std;
    if (!requirement) {
        fputs(msg.c_str(), stderr);
        fputs("\n", stderr);
        exit(1);
    }
}

inline void requireArgs(int argc, int args,
    const std::string& msg = "Mustuse%darguments") {
    using namespace std;
    if (argc != args + 1) {
        fprintf(stderr, msg.c_str(), args);
        fputs("\n", stderr);
        exit(1);
    }
}

inline void
requireMinArgs(int argc, int minArgs,
    const std::string& msg = "Mustuseatleast%darguments") {
    using namespace std;
    if (argc < minArgs + 1) {
        fprintf(stderr, msg.c_str(), minArgs);
        fputs("\n", stderr);
        exit(1);
    }
}

inline void assure(std::ifstream& in, const std::string& filename = "") {
    using namespace std;
    if (!in) {
        fprintf(stderr, "Couldnotopenfile%s\n", filename.c_str());
        exit(1);
    }
}

inline void assure(std::ofstream& out, const std::string& filename = "") {
    using namespace std;
    if (!out) {
        fprintf(stderr, "Couldnotopenfile%s\n", filename.c_str());
        exit(1);
    }
}

#endif // REQUIRE_H///:~
