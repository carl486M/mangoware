#include <string>

#ifdef _WIN32
    #include <windows.h>
    typedef LONG(WINAPI* RtlGetVersionPtr)(PRTL_OSVERSIONINFOW);
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    #include <sys/utsname.h>
#endif

namespace mangosystem {

const char* architecture() {
    #if defined(__x86_64__) || defined(_M_X64)
        return "x86_64";
    #elif defined(__i386) || defined(_M_IX86)
        return "x86";
    #elif defined(__powerpc64__) || defined(__ppc64__) || defined(_M_PPC)
        return "ppc64";
    #elif defined(__powerpc__) || defined(__ppc__) || defined(_M_PPC)
        return "ppc";
    #elif defined(__aarch64__) || defined(_M_ARM64)
        return "arm64";
    #elif defined(__arm__) || defined(_M_ARM)
        return "arm";
    #else
        return "Unknown";
    #endif
}

const char* platform() {
    #if defined(_WIN32)
        return "Windows NT";
    #elif defined(__APPLE__) && defined(__MACH__)
        return "Darwin";
    #elif defined(__linux__)
        return "Linux";
    #elif defined(__unix__)
        return "Unix";
    #elif defined(__FreeBSD__)
        return "FreeBSD";
    #elif defined(__NetBSD__)
        return "NetBSD";
    #elif defined(__OpenBSD__)
        return "OpenBSD";
    #else
        return "Unknown";
    #endif
}

const char* compiler() {
    #if defined(_MSC_VER)
        return "Microsoft Visual Studio";
    #elif defined(__clang__)
        return "Clang/LLVM";
    #elif defined(__ICC) || defined(__INTEL_COMPILER)
        return "Intel ICC/ICPC";
    #elif defined(__GNUC__) || defined(__GNUG__)
        return "GNU GCC/G++";
    #elif defined(__MINGW32__) || defined(__MINGW64__)
        return "MinGW";
    #else
        return "Unknown";
    #endif
}

const char* compilerVersion() {
    static std::string versionStr;
    #if defined(_MSC_VER)
        versionStr = std::to_string(_MSC_VER);
    #elif defined(__clang__)
        versionStr = __clang_version__;
    #elif defined(__ICC) || defined(__INTEL_COMPILER)
        versionStr = std::to_string(__INTEL_COMPILER);
    #elif defined(__GNUC__) || defined(__GNUG__)
        versionStr = std::to_string(__GNUC__) + "." 
                   + std::to_string(__GNUC_MINOR__) + "." 
                   + std::to_string(__GNUC_PATCHLEVEL__);
    #elif defined(__MINGW32__) || defined(__MINGW64__)
        versionStr = std::to_string(__MINGW32_MAJOR_VERSION) + "." 
                   + std::to_string(__MINGW32_MINOR_VERSION);
    #else
        versionStr = "Unknown";
    #endif
    return versionStr.c_str();
}

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
const char* kernelVersion() {
    static std::string versionStr;
    struct utsname buffer;
    if (uname(&buffer) == 0) {
        versionStr = buffer.release;
        return versionStr.c_str();
    } else {
        return "Unknown";
    }
}
#elif defined(_WIN32)
const char* kernelVersion() {
    static std::string versionStr;
    HMODULE hMod = ::GetModuleHandleW(L"ntdll.dll");
    if (hMod) {
        RtlGetVersionPtr fxPtr = (RtlGetVersionPtr)::GetProcAddress(hMod, "RtlGetVersion");
        if (fxPtr != nullptr) {
            RTL_OSVERSIONINFOW rovi = { 0 };
            rovi.dwOSVersionInfoSize = sizeof(rovi);
            if (fxPtr(&rovi) == 0) {
                versionStr = "" 
                           + std::to_string(rovi.dwMajorVersion) + "."
                           + std::to_string(rovi.dwMinorVersion)
                           + " (Build " + std::to_string(rovi.dwBuildNumber) + ")";
                return versionStr.c_str();
            }
        }
    }
    versionStr = "Unknown Windows Version";
    return versionStr.c_str();
}
#endif

} // namespace mangosystem
