from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layouts, CMakeDeps
from conan.tools.files import copy


class MoneyConan(ConanFile):
    name = "money"
    version = "1.0.0"
    
    # Optional metadata
    license = "MIT"
    author = "Mihail Croitor <mcroitor@gmail.com>"
    url = "https://github.com/mcroitor/money"
    description = "A comprehensive C++ library for handling monetary values with ISO 4217 currency support"
    topics = ("currency", "money", "iso4217", "finance", "monetary")
    
    # Package metadata
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "shared": [True, False],
        "fPIC": [True, False],
        "with_tests": [True, False]
    }
    default_options = {
        "shared": False,
        "fPIC": True,
        "with_tests": False
    }
    
    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "*.cpp", "*.hpp", "tests/*"
    
    def config_options(self):
        if self.settings.os == "Windows":
            self.options.rm_safe("fPIC")
    
    def configure(self):
        if self.options.shared:
            self.options.rm_safe("fPIC")
    
    def layout(self):
        cmake_layouts(self)
    
    def requirements(self):
        if self.options.with_tests:
            self.requires("catch2/3.4.0")
    
    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.variables["BUILD_TESTING"] = self.options.with_tests
        tc.generate()
    
    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        if self.options.with_tests:
            cmake.test()
    
    def package(self):
        copy(self, "LICENSE", dst=self.folders.licenses, src=self.folders.source)
        cmake = CMake(self)
        cmake.install()
    
    def package_info(self):
        self.cpp_info.libs = ["money"]
        self.cpp_info.set_property("cmake_file_name", "money")
        self.cpp_info.set_property("cmake_target_name", "money::money")
        
        # For legacy support
        self.cpp_info.names["cmake_find_package"] = "money"
        self.cpp_info.names["cmake_find_package_multi"] = "money"