import qbs

CppApplication {
    consoleApplication: true
    Group {
        name: "Sources"
        files: "*.c"
    }

    Group {
        name: "Headers"
        files: "*.h"
    }

    cpp.cFlags: ["-Wall", "-Werror", "-std=c99"]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
