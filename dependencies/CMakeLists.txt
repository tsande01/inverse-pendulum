# https://approvaltestscpp.readthedocs.io/en/latest/generated_docs/CMakeIntegration.html#make-cmake-clone-approvaltests-cpp-and-catch2

# Needs CMake 3.14 or above
include(FetchContent)

# Names of targets added here:
#   ghc_filesystem Catch2::Catch2 ApprovalTests::ApprovalTests fmt::fmt

# -------------------------------------------------------------------
FetchContent_Declare(Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.4)
FetchContent_MakeAvailable(Catch2)

# -------------------------------------------------------------------
FetchContent_Declare(ApprovalTests
        GIT_REPOSITORY https://github.com/approvals/ApprovalTests.cpp.git
        GIT_TAG v.10.8.0)
FetchContent_MakeAvailable(ApprovalTests)

# -------------------------------------------------------------------
FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 7.1.3)
FetchContent_MakeAvailable(fmt)

# -------------------------------------------------------------------
FetchContent_Declare(filesystem
        GIT_REPOSITORY https://github.com/gulrak/filesystem.git
        GIT_TAG v1.5.0)
FetchContent_MakeAvailable(filesystem)

# -------------------------------------------------------------------
