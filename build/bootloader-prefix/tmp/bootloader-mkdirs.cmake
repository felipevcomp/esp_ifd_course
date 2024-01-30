# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/felipe/esp/v5.1.2/esp-idf/components/bootloader/subproject"
  "/home/felipe/Documents/PlatformIO/Projects/esp_idf_course/build/bootloader"
  "/home/felipe/Documents/PlatformIO/Projects/esp_idf_course/build/bootloader-prefix"
  "/home/felipe/Documents/PlatformIO/Projects/esp_idf_course/build/bootloader-prefix/tmp"
  "/home/felipe/Documents/PlatformIO/Projects/esp_idf_course/build/bootloader-prefix/src/bootloader-stamp"
  "/home/felipe/Documents/PlatformIO/Projects/esp_idf_course/build/bootloader-prefix/src"
  "/home/felipe/Documents/PlatformIO/Projects/esp_idf_course/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/felipe/Documents/PlatformIO/Projects/esp_idf_course/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/felipe/Documents/PlatformIO/Projects/esp_idf_course/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
