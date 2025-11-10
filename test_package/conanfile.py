from conan import ConanFile
from conan.tools.cmake import cmake_layouts, CMake
import os


class TestPackageConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps", "VirtualRunEnv"
    test_type = "explicit"

    def layout(self):
        cmake_layouts(self)

    def requirements(self):
        self.requires(self.tested_reference_str)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def test(self):
        if self.settings.os == "Windows":
            self.run(os.path.join(self.folders.cpp.build, "test_package.exe"))
        else:
            self.run(os.path.join(self.folders.cpp.build, "test_package"))