# Necessary CMake
project(XSerialFP CXX)
cmake_minimum_required(VERSION 2.8)

# Include the SDK. Adjust this path to wherever you have the SDK repository
add_subdirectory(sdk/ bin/)

# Set up the plugin
add_xplane_plugin(XSerialFP 301
  src/XSerialFP.cpp
  src/XSFPLog.cpp
  src/XSFPMenu.cpp
  src/XSFPSerial.cpp
  src/XSFPHandler.cpp
  src/XSFPFF320.cpp
  src/XSFPDebugWindow.cpp
)

