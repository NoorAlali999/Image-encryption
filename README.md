# Image-encryption
## Author: Noor AlAli

### Description:
- Image encryption program to enc/dec images using three algorithms:
- xor
- or
- and

### How to run the code:
1. Case 1: to enryrpt an image with xor algorithm: 
- $ g++ main.cpp -o exe
- $  ./exe 1 <image_name.bmp> <encryption_key_number>

#### Example case1:
- $ g++ main.cpp -o exe
- $  ./exe 1 img.bmp 1234

2. Case 2: to decrypt an image with xor algorithm:
- $ g++ main.cpp -o exe
- $  ./exe 2 <image_name.bmp> <encryption_key_number>

#### Example case2:
- $ g++ main.cpp -o exe
- $  ./exe 2 img.bmp 1234

3. Case 3: to encrypt an image with or/and algorithms: 
- $ g++ main.cpp -o exe
- $  ./exe 3 <image_name.bmp> <encryption_key_number>

#### Example case3:
- $ g++ main.cpp -o exe
- $  ./exe 3 img.bmp 1234
