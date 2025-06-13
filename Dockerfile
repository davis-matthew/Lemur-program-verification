FROM mcr.microsoft.com/vscode/devcontainers/base:ubuntu-24.04

RUN <<EOF
apt-get -qq update
apt-get -qq install -y clang-format-15 clang curl git software-properties-common > /dev/null
add-apt-repository ppa:deadsnakes/ppa -y
apt-get -qq update
sudo apt-get install -y python3.8 python3.8-dev python3.8-distutils python3-pip
update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.8 1
rm -rf /var/lib/apt/lists/*
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
source $HOME/.cargo/env
pip3 install --break-system-packages pycparser==2.21 pyyaml==5.4.1
EOF
