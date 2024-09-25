
# I could automate that/ combine the path into my CMakeLists.txt but this is only interesting
# for the future
INSTALL_PREFIX="/Users/yoocherry/dev/git_repos/StockBeans/cmake/MyTools"
MYTOOLS_BUILD_DIR="/Users/yoocherry/dev/git_repos/MyTools/build"
MYTOOLS_SOURCE_DIR="/Users/yoocherry/dev/git_repos/MyTools"

# Function to handle errors
handle_error() {
  echo "An error occurred in the script. Exiting..."
  exit 1
}
# creates the build directory IF its not already created
mkdir -p "$MYTOOLS_BUILD_DIR" || handle_error

# Creates all the cmake files from the sources into the build directory
cmake -S "$MYTOOLS_SOURCE_DIR" -B "$MYTOOLS_BUILD_DIR" || handle_error

# Build up the project out of the files I just created
cmake --build "$MYTOOLS_BUILD_DIR" || handle_error

# install the MyToolsLib into the directory of this project
cmake --install "$MYTOOLS_BUILD_DIR" --prefix "$INSTALL_PREFIX" || handle_error

echo "Das Projekt wurde erfolgreich im Verzeichnis $INSTALL_PREFIX installiert."