#!/bin/bash

git config --global http.proxy "http://cache-etu.univ-lille1.fr:3128"
git clone "http://github.com/Tikiwinkie/PJE.git"
git clone "https://github.com/JoKeRGreGre/depotalacon.git"
mv ./depotalacon/smews/* ./PJE/smews
sudo ip link set eth1 up
sudo ip addr add 192.168.1.2 dev eth1
sudo ip route add 192.168.1.3 via 192.168.1.2 dev eth1
