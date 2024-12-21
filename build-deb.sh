#!/usr/bin/env bash
# Script to build a .deb package for CodeFR Interpreter

# Define package name and version
PACKAGE_NAME="codefr-interpreter"
VERSION="1.0"
ARCH="amd64" # Change this to your system's architecture
BUILD_DIR="build"
DEB_DIR="${BUILD_DIR}/${PACKAGE_NAME}_${VERSION}_${ARCH}"

# Clean up any previous builds
rm -rf $BUILD_DIR
mkdir -p "${DEB_DIR}/DEBIAN"
mkdir -p "${DEB_DIR}/usr/bin"
mkdir -p "${DEB_DIR}/usr/share/doc/${PACKAGE_NAME}"

# Copy files into the package directory
cp ./codefr "${DEB_DIR}/usr/bin/"
cp ./README.md ./LICENSE "${DEB_DIR}/usr/share/doc/${PACKAGE_NAME}/"

# Create the control file
cat << EOF > "${DEB_DIR}/DEBIAN/control"
Package: ${PACKAGE_NAME}
Version: ${VERSION}
Section: utils
Priority: optional
Architecture: ${ARCH}
Maintainer: Normich ITOUA <nitoua.dev@gmail.com>
Description: CodeFR Interpreter
 A lightweight interpreter that translates and executes French pseudocode. Simplifies algorithmic learning for French-speaking beginners.
EOF

# Create post-installation script
cat << EOF > "${DEB_DIR}/DEBIAN/postinst"
#!/bin/bash
echo "CodeFR Interpreter has been installed successfully."
EOF
chmod 755 "${DEB_DIR}/DEBIAN/postinst"

# Create pre-removal script
cat << EOF > "${DEB_DIR}/DEBIAN/prerm"
#!/bin/bash
echo "Removing CodeFR Interpreter..."
EOF
chmod 755 "${DEB_DIR}/DEBIAN/prerm"

# Build the .deb package
dpkg-deb --build "${DEB_DIR}"

# Move the generated .deb file to the current directory
mv "${DEB_DIR}.deb" "./${PACKAGE_NAME}_${VERSION}_${ARCH}.deb"

# Clean up
rm -rf $BUILD_DIR

echo "Package built successfully: ./${PACKAGE_NAME}_${VERSION}_${ARCH}.deb"